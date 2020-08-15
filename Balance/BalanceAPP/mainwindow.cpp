#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hncapi.h"
#include "hncregdef.h"
#include "netdialog.h"
#include "setchanneldialog.h"
#include "polarchart.h"
#include "timedomchart.h"
#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include <QVector>
#include <QPainter>
#include <QFile>
#include <QTextStream>
#include <time.h>
#include <QIcon>

int MaxBufferLen = 5000;//����Buffer�洢�����������, ��Լ��5s
int VibDataLen = MaxBufferLen * 20; //�ɵõ������ݳ��ȡ�20kHz,��ΪBuffer���ȵ�20��

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    hnc(new HncApi),
    ui(new Ui::MainWindow),
    netdiag(new NetDialog(hnc,this)),
    setdiag(new SetChannelDialog(hnc, this)),
    ms_200(new QTimer), sampleFinishFlag(0), amplitude(0), phase(0)
{
    ui->setupUi(this);

    ui->Picture->setStyleSheet("QLabel{border-image: url(./resource/tool.png);}"); //��ӻ���ͼƬ, resource�ļ�����exeͬ��Ŀ¼

    QString ButtonStyle = "QPushButton{background-color:white;color: rgb(90,140,255); border-radius: 10px;  border: 2px groove gray;border-style: outset;}"
                          "QPushButton:hover{background-color:rgb(230,238,255); color: rgb(90,140,255);}"
                          "QPushButton:pressed{background-color:rgb(230,238,255);border-style: inset;}";
    ui->StartButton->setStyleSheet(ButtonStyle);
    ui->SetButton->setStyleSheet(ButtonStyle);
    ui->SaveButton->setStyleSheet(ButtonStyle);
    ui->NetButton->setStyleSheet(ButtonStyle);
    ui->ReadButton->setStyleSheet(ButtonStyle);

    ui->PolarButton->setStyleSheet("QPushButton{border-image: url(./resource/Balance.png);border-style: outset;}"
                                   "QPushButton:hover{background-color:rgb(230,238,255);}"
                                   "QPushButton:pressed{background-color:rgb(230,238,255);border-style: inset;}"); //��ͼ��ť����ͼƬ
    ui->PlotButton->setStyleSheet("QPushButton{border-image: url(./resource/Timeplot.png);border-style: outset;}"
                                  "QPushButton:hover{background-color:rgb(230,238,255);}"
                                  "QPushButton:pressed{background-color:rgb(230,238,255);border-style: inset;}"); //

    ui->DecorateBtn->setStyleSheet("QPushButton{border-image: url(./resource/circle.png);}");
    ui->DecorateBtn->setEnabled(false);
    ui->DecorateBtn2->setStyleSheet("QPushButton{border-image: url(./resource/circle.png);}");
    ui->DecorateBtn2->setEnabled(false);
    ui->DecorateBtn3->setStyleSheet("QPushButton{border-image: url(./resource/circle.png);}");
    ui->DecorateBtn3->setEnabled(false);

    setFixedSize(860,500); // ��ֹ�ı䴰�ڴ�С
    this->setWindowTitle(QStringLiteral("�������ᶯƽ��APP"));//�޸ı���

    ui->polarChart->setPolarRect(QRect(150, 0, 280, 280)); //��ƽ���״�ͼ��ʼ��

    ui->stackedWidget->setCurrentWidget(ui->timePage);//��ʼ��ʱ�������ʱ��ͼ��

    for(int i=0;i < VibDataLen;i++) AxisX.push_back(i);

    connect(ui->NetButton, SIGNAL(clicked()), this, SLOT(NetDiagShow()));
    connect(ui->SetButton, SIGNAL(clicked()), this, SLOT(SetChShow()));
    connect(ui->StartButton, SIGNAL(clicked()), this, SLOT(StartSample()));
    connect(ui->SaveButton, SIGNAL(clicked()), this, SLOT(SaveData()));

    connect(this->ms_200, &QTimer::timeout,this, &MainWindow::GetData);
    connect(this, SIGNAL(FlagValueChange()), this, SLOT(Transfer())); //��ɲɼ��󣬽�������ת��
}

MainWindow::~MainWindow()
{
    delete ui;
    delete hnc, netdiag, setdiag;

    dataBuffer.clear();
    delete ms_200;
}

void MainWindow::NetDiagShow() //�������ӶԻ���
{
    netdiag->show();
}

void MainWindow::SetChShow() //����ͨ���Ի���
{
    if(netdiag->ConnectFlag == 0) //�������������ʾ
        setdiag->show();
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle(QStringLiteral("��ʾ"));
        msgBox.setText(QStringLiteral("����δ���ӣ�������������"));
        msgBox.exec();
    }
}

void MainWindow::StartSample() //��ʼ������ť
{
    if(setdiag->SetFlag == 0) //������ͨ���ɹ�
    {
        if(!dataBuffer.isEmpty()) dataBuffer.clear(); //�����ݻ������鲻Ϊ�������

        sampleFinishFlag = 0; //��ղ�����ɱ�־λ

        int len = setdiag->typeName->size();
        dataBuffer.resize(len); //�ض���nά���ݻ�����
        bufferCnt.resize(len); //�ض��������ۼӼĴ���
        for(int i=0;i<len;i++)
        {
            dataBuffer[i].resize(MaxBufferLen); //n*MaxBufferLen�Ķ�ά����
            bufferCnt[i] = 0;
        }

        if(ms_200->isActive() == false) ms_200->start(200); //��ʱ��������200ms

        hnc->HNC_SamplTriggerOn();
        hnc->HNC_RegSetBit(REG_TYPE_G, 2960, 12);
    }
    else if(setdiag->SetFlag == -1) //δ���ͨ�����ã�����ʾ
    {
        QMessageBox msgBox1;
        msgBox1.setWindowTitle(QStringLiteral("��ʾ"));
        msgBox1.setText(QStringLiteral("ͨ��δ����"));
        msgBox1.exec();
    }
}

void MainWindow::GetData() //���ͨ������
{
    Bit32 chNum = 0;
    Bit32 numPerCh = 0;
    Bit32 data[100000]; //��ȡ��������������32*10000memset(data, 0, 32 * 10000);
    memset(data, 0, 100000); //��ʼ��Ϊ0

    hnc->HNC_SamplGetData(data, chNum, numPerCh);

    for (Bit32 i = 0; i < chNum; i++) //����ͨ�������������ݱ������ά������
    {
        for (Bit32 j = 0; j < numPerCh; j++)
        {
            if(bufferCnt[i] < MaxBufferLen)
            {
                dataBuffer[i][bufferCnt[i]] = data[i * numPerCh + j];
                bufferCnt[i]++;
            }
            else //һ�β���ֻ��50000����
            {
                if(ms_200->isActive() == true) ms_200->stop();//����ֹͣ
                if(i == chNum - 1)
                    sampleFinishFlag = 1;
                break;
            }
        }
    }
    CheckFlag(sampleFinishFlag);//��鲢�ж��Ƿ�������ź�

}

void MainWindow::CheckFlag(int flag) //����־λ
{
    if(flag == 1) emit FlagValueChange(); //��������ź�
}

void MainWindow::Transfer() //������ɺ������ת������ƽ������������չʾ
{
    int i,j;
    vibBuffer.resize( VibDataLen );
    angleBuffer.resize( VibDataLen );

    for(j = 0; j < MaxBufferLen; j++)   dataBuffer[0][j] = dataBuffer[0][j]/1e5; //�Ƕ�ֵ����1e5

    for(j = 0; j < MaxBufferLen; j++)
    {
        for(i = 0; i<10; i++) //ת��
        {
             vibBuffer[j*20 + i*2] = (int)dataBuffer[i + 1][j] & 0x0000FFFF;
             vibBuffer[j*20 + i*2 +1] =  (int)dataBuffer[i + 1][j] >> 16;

             if(vibBuffer[j*20 + i*2] > 32678) vibBuffer[j*20 + i*2] -= 65536;
             if(vibBuffer[j*20 + i*2 + 1] > 32678) vibBuffer[j*20 + i*2 + 1] -= 65536;

             vibBuffer[j*20 + i*2]= vibBuffer[j*20 + i*2]/ 6553 * 10 * 9.8;
             vibBuffer[j*20 + i*2 + 1] = vibBuffer[j*20 + i*2 + 1] / 6553 * 10 * 9.8; //ת����m/s^2

            if(j != MaxBufferLen - 1) //����Ƕ�ֵ��ֵת��
            {   
                if( abs(dataBuffer[0][j + 1] - dataBuffer[0][j]) < 200 )
                {
                    angleBuffer[j*20 + i*2] = (dataBuffer[0][j + 1] - dataBuffer[0][j]) * (i*2) / 20 + dataBuffer[0][j];
                    angleBuffer[j*20 + i*2 + 1] = (dataBuffer[0][j + 1] - dataBuffer[0][j]) * (i*2+1) / 20 + dataBuffer[0][j]; // ���Բ�ֵ
                }
                else //�Ƕ���360��0֮������
                {
                    if(dataBuffer[0][j + 1] < dataBuffer[0][j]) //������ֵ���󣬴�360������0��
                    {
                        angleBuffer[j*20 + i*2] = (360 + dataBuffer[0][j + 1] - dataBuffer[0][j]) * (i*2) / 20 + dataBuffer[0][j];
                        if(angleBuffer[j*20 + i*2] >= 360) angleBuffer[j*20 + i*2] = angleBuffer[j*20 + i*2] - 360;

                        angleBuffer[j*20 + i*2 + 1] = (360 + dataBuffer[0][j + 1] - dataBuffer[0][j]) * (i*2+1) / 20 + dataBuffer[0][j];
                        if(angleBuffer[j*20 + i*2 + 1] >= 360) angleBuffer[j*20 + i*2 + 1] = angleBuffer[j*20 + i*2 + 1] - 360;
                    }
                    else if(dataBuffer[0][j + 1] > dataBuffer[0][j]) //������ֵ��С����0������360��
                    {
                        angleBuffer[j*20 + i*2] = -(360 - dataBuffer[0][j + 1] + dataBuffer[0][j]) * (i*2) / 20 + dataBuffer[0][j];
                        if(angleBuffer[j*20 + i*2] < 0) angleBuffer[j*20 + i*2] = angleBuffer[j*20 + i*2] + 360;

                        angleBuffer[j*20 + i*2 + 1] = -(360 - dataBuffer[0][j + 1] + dataBuffer[0][j]) * (i*2) / 20 + dataBuffer[0][j];
                        if(angleBuffer[j*20 + i*2 + 1] < 0) angleBuffer[j*20 + i*2 + 1] = angleBuffer[j*20 + i*2 + 1] + 360;
                    }
                }
            }
            else
                angleBuffer[j*20] = dataBuffer[0][j]/1e5; //���һ���㣬�޷����Բ�ֵ.
        }
    }

    ui->timeChart->getData(AxisX, vibBuffer); //�������ݻ��Ƴ����� ��ͨ������

    BalanceCal(); // ���������

    ui->amplitude->setText(QString::number(amplitude, 'f', 4));//���չʾ
    ui->phase->setText(QString::number(phase, 'f', 2));

    ui->stackedWidget->setCurrentWidget(ui->polarPage); //�л�����ƽ����ʾ����
    ui->polarChart->setPoint(amplitude, phase);

}

void MainWindow::SaveData() //�Ĵ������ݱ�����DataSave�ļ����С�
{
    if(sampleFinishFlag == 1)
    {
        int i = 0;
        time_t t = time(NULL); //��ȡ��ǰʱ��
        QString filePath = "./DataSave/";
        char filename[64]={"\0"};

        strftime(filename,sizeof(filename),"RegData%Y-%m-%d %H-%M-%S.txt",localtime(&t));
        filePath = filePath + filename;
        QFile f(filePath); //����txt�ļ�

        f.open(QIODevice::Text | QIODevice::WriteOnly);
        QTextStream out(&f); //������

        out<< QStringLiteral("����Ƕ�")<< "   "<<QStringLiteral("������")<<endl;

        for(i=0; i<MaxBufferLen*20 - 1; i++)
            out<< angleBuffer[i] << " "<< vibBuffer[i]<< "   "<<endl;

        f.close();
    }
    else
    {
        QMessageBox msgBox1;
        msgBox1.setWindowTitle(QStringLiteral("��ʾ"));
        msgBox1.setText(QStringLiteral("�������ɹ�"));
        msgBox1.exec();
    }
}

void MainWindow::BalanceCal() //���������
{
    int i, cal_len;
    int start_num = 0;
    double Rxy, Rxz, sin_tmp, cos_tmp;
    double pi = 3.1415926;
    double min = 30;
    cal_len = 3000*20; //����ʱ��Ϊ3s��60000�����ݵ�
    Rxy = Rxz = 0;

    for(i=0; i < 10000; i++) //�ҵ�0��λ�����Ĳ����� ��Ϊ������ʼ��
    {
        if(angleBuffer[i] < min)
        {
            start_num = i;
            min = angleBuffer[i];
        }
        else if (angleBuffer[i] > 300 && 360 - angleBuffer[i] < min)
        {
            start_num = i;
            min = 360 - angleBuffer[i];
        }
    }

    for(i=start_num; i<start_num + cal_len; i++) //ȡ3000*20������м��㣬 ��ת����50�������������3s��һ����������
    {
        sin_tmp = sin( angleBuffer[i]*2.0*pi/360 ); //���õ���Ƕ�ֵ��û�����㷨��sin��cos
        cos_tmp = cos( angleBuffer[i]*2.0*pi/360 );

        Rxy += sin_tmp * vibBuffer[i];
        Rxz += cos_tmp * vibBuffer[i];
    }
    amplitude = 2 * ( sqrt(Rxy*Rxy + Rxz*Rxz) / cal_len );

    if(Rxz != 0) phase = atan(Rxy/Rxz)*(180/pi); //chen
    else phase = 0;
    if(Rxz<0)
        phase = phase + 180;
    else if(Rxy<0)
        phase = phase + 360;

}

void MainWindow::on_PlotButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->timePage); //�л���������ʾ����
}

void MainWindow::on_PolarButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->polarPage); //�л�����ƽ����ʾ����
}

void MainWindow::on_ReadButton_clicked() //��ȡ���е������ļ�, ���ж�����쳣��BUG��������չʾ
{
    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("�ļ��Ի���"), "./DataSave", QString::fromLocal8Bit("�ı��ļ�(*txt)"));

    QFile file(fileName);
    QString info;
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    angleBuffer.clear();
    vibBuffer.clear();

    int len = 0;
    while(!file.atEnd())
    {
        len++;
        QByteArray line = file.readLine();

        if(len > 1)
        {
            QString str(line);
            angleBuffer.append(str.section(' ', 0, 0).trimmed().toDouble());
            vibBuffer.append(str.section(' ', 1, 1).trimmed().toDouble());
        }
    }

    QVector<double> __X;
    for(int i=0;i < vibBuffer.length();i++) __X.append(i);
    ui->timeChart->getData(__X, vibBuffer); //�������ݻ��Ƴ����� ��ͨ������

    BalanceCal(); // ���������

    ui->amplitude->setText(QString::number(amplitude, 'f', 4));//���չʾ
    ui->phase->setText(QString::number(phase, 'f', 2));

    ui->stackedWidget->setCurrentWidget(ui->polarPage); //�л�����ƽ����ʾ����
    ui->polarChart->setPoint(amplitude, phase);
}
