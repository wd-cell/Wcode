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

int MaxBufferLen = 5000;//单个Buffer存储的最大数据量, 大约采5s
int VibDataLen = MaxBufferLen * 20; //采得的振动数据长度。20kHz,故为Buffer长度的20倍

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    hnc(new HncApi),
    ui(new Ui::MainWindow),
    netdiag(new NetDialog(hnc,this)),
    setdiag(new SetChannelDialog(hnc, this)),
    ms_200(new QTimer), sampleFinishFlag(0), amplitude(0), phase(0)
{
    ui->setupUi(this);

    ui->Picture->setStyleSheet("QLabel{border-image: url(./resource/tool.png);}"); //添加机床图片, resource文件夹与exe同级目录

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
                                   "QPushButton:pressed{background-color:rgb(230,238,255);border-style: inset;}"); //绘图按钮背景图片
    ui->PlotButton->setStyleSheet("QPushButton{border-image: url(./resource/Timeplot.png);border-style: outset;}"
                                  "QPushButton:hover{background-color:rgb(230,238,255);}"
                                  "QPushButton:pressed{background-color:rgb(230,238,255);border-style: inset;}"); //

    ui->DecorateBtn->setStyleSheet("QPushButton{border-image: url(./resource/circle.png);}");
    ui->DecorateBtn->setEnabled(false);
    ui->DecorateBtn2->setStyleSheet("QPushButton{border-image: url(./resource/circle.png);}");
    ui->DecorateBtn2->setEnabled(false);
    ui->DecorateBtn3->setStyleSheet("QPushButton{border-image: url(./resource/circle.png);}");
    ui->DecorateBtn3->setEnabled(false);

    setFixedSize(860,500); // 禁止改变窗口大小
    this->setWindowTitle(QStringLiteral("机床主轴动平衡APP"));//修改标题

    ui->polarChart->setPolarRect(QRect(150, 0, 280, 280)); //动平衡雷达图初始化

    ui->stackedWidget->setCurrentWidget(ui->timePage);//初始化时界面放在时域图上

    for(int i=0;i < VibDataLen;i++) AxisX.push_back(i);

    connect(ui->NetButton, SIGNAL(clicked()), this, SLOT(NetDiagShow()));
    connect(ui->SetButton, SIGNAL(clicked()), this, SLOT(SetChShow()));
    connect(ui->StartButton, SIGNAL(clicked()), this, SLOT(StartSample()));
    connect(ui->SaveButton, SIGNAL(clicked()), this, SLOT(SaveData()));

    connect(this->ms_200, &QTimer::timeout,this, &MainWindow::GetData);
    connect(this, SIGNAL(FlagValueChange()), this, SLOT(Transfer())); //完成采集后，进行数据转换
}

MainWindow::~MainWindow()
{
    delete ui;
    delete hnc, netdiag, setdiag;

    dataBuffer.clear();
    delete ms_200;
}

void MainWindow::NetDiagShow() //网络连接对话框
{
    netdiag->show();
}

void MainWindow::SetChShow() //设置通道对话框
{
    if(netdiag->ConnectFlag == 0) //连接上网络才显示
        setdiag->show();
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle(QStringLiteral("提示"));
        msgBox.setText(QStringLiteral("网络未连接，请先连接网络"));
        msgBox.exec();
    }
}

void MainWindow::StartSample() //开始采样按钮
{
    if(setdiag->SetFlag == 0) //已配置通道成功
    {
        if(!dataBuffer.isEmpty()) dataBuffer.clear(); //若数据缓存数组不为空则清空

        sampleFinishFlag = 0; //清空采样完成标志位

        int len = setdiag->typeName->size();
        dataBuffer.resize(len); //重定义n维数据缓存器
        bufferCnt.resize(len); //重定义数据累加寄存器
        for(int i=0;i<len;i++)
        {
            dataBuffer[i].resize(MaxBufferLen); //n*MaxBufferLen的二维数组
            bufferCnt[i] = 0;
        }

        if(ms_200->isActive() == false) ms_200->start(200); //定时器开启，200ms

        hnc->HNC_SamplTriggerOn();
        hnc->HNC_RegSetBit(REG_TYPE_G, 2960, 12);
    }
    else if(setdiag->SetFlag == -1) //未完成通道配置，则提示
    {
        QMessageBox msgBox1;
        msgBox1.setWindowTitle(QStringLiteral("提示"));
        msgBox1.setText(QStringLiteral("通道未配置"));
        msgBox1.exec();
    }
}

void MainWindow::GetData() //获得通道数据
{
    Bit32 chNum = 0;
    Bit32 numPerCh = 0;
    Bit32 data[100000]; //获取的最大采样点数：32*10000memset(data, 0, 32 * 10000);
    memset(data, 0, 100000); //初始化为0

    hnc->HNC_SamplGetData(data, chNum, numPerCh);

    for (Bit32 i = 0; i < chNum; i++) //根据通道数将采样数据保存进二维数组中
    {
        for (Bit32 j = 0; j < numPerCh; j++)
        {
            if(bufferCnt[i] < MaxBufferLen)
            {
                dataBuffer[i][bufferCnt[i]] = data[i * numPerCh + j];
                bufferCnt[i]++;
            }
            else //一次采样只采50000个点
            {
                if(ms_200->isActive() == true) ms_200->stop();//采满停止
                if(i == chNum - 1)
                    sampleFinishFlag = 1;
                break;
            }
        }
    }
    CheckFlag(sampleFinishFlag);//检查并判定是否发送完成信号

}

void MainWindow::CheckFlag(int flag) //检测标志位
{
    if(flag == 1) emit FlagValueChange(); //发送完成信号
}

void MainWindow::Transfer() //采样完成后的数据转换，动平衡分析，及结果展示
{
    int i,j;
    vibBuffer.resize( VibDataLen );
    angleBuffer.resize( VibDataLen );

    for(j = 0; j < MaxBufferLen; j++)   dataBuffer[0][j] = dataBuffer[0][j]/1e5; //角度值除以1e5

    for(j = 0; j < MaxBufferLen; j++)
    {
        for(i = 0; i<10; i++) //转换
        {
             vibBuffer[j*20 + i*2] = (int)dataBuffer[i + 1][j] & 0x0000FFFF;
             vibBuffer[j*20 + i*2 +1] =  (int)dataBuffer[i + 1][j] >> 16;

             if(vibBuffer[j*20 + i*2] > 32678) vibBuffer[j*20 + i*2] -= 65536;
             if(vibBuffer[j*20 + i*2 + 1] > 32678) vibBuffer[j*20 + i*2 + 1] -= 65536;

             vibBuffer[j*20 + i*2]= vibBuffer[j*20 + i*2]/ 6553 * 10 * 9.8;
             vibBuffer[j*20 + i*2 + 1] = vibBuffer[j*20 + i*2 + 1] / 6553 * 10 * 9.8; //转换成m/s^2

            if(j != MaxBufferLen - 1) //电机角度值插值转换
            {   
                if( abs(dataBuffer[0][j + 1] - dataBuffer[0][j]) < 200 )
                {
                    angleBuffer[j*20 + i*2] = (dataBuffer[0][j + 1] - dataBuffer[0][j]) * (i*2) / 20 + dataBuffer[0][j];
                    angleBuffer[j*20 + i*2 + 1] = (dataBuffer[0][j + 1] - dataBuffer[0][j]) * (i*2+1) / 20 + dataBuffer[0][j]; // 线性插值
                }
                else //角度在360和0之间跳变
                {
                    if(dataBuffer[0][j + 1] < dataBuffer[0][j]) //编码器值增大，从360度跳到0度
                    {
                        angleBuffer[j*20 + i*2] = (360 + dataBuffer[0][j + 1] - dataBuffer[0][j]) * (i*2) / 20 + dataBuffer[0][j];
                        if(angleBuffer[j*20 + i*2] >= 360) angleBuffer[j*20 + i*2] = angleBuffer[j*20 + i*2] - 360;

                        angleBuffer[j*20 + i*2 + 1] = (360 + dataBuffer[0][j + 1] - dataBuffer[0][j]) * (i*2+1) / 20 + dataBuffer[0][j];
                        if(angleBuffer[j*20 + i*2 + 1] >= 360) angleBuffer[j*20 + i*2 + 1] = angleBuffer[j*20 + i*2 + 1] - 360;
                    }
                    else if(dataBuffer[0][j + 1] > dataBuffer[0][j]) //编码器值减小，从0度跳到360度
                    {
                        angleBuffer[j*20 + i*2] = -(360 - dataBuffer[0][j + 1] + dataBuffer[0][j]) * (i*2) / 20 + dataBuffer[0][j];
                        if(angleBuffer[j*20 + i*2] < 0) angleBuffer[j*20 + i*2] = angleBuffer[j*20 + i*2] + 360;

                        angleBuffer[j*20 + i*2 + 1] = -(360 - dataBuffer[0][j + 1] + dataBuffer[0][j]) * (i*2) / 20 + dataBuffer[0][j];
                        if(angleBuffer[j*20 + i*2 + 1] < 0) angleBuffer[j*20 + i*2 + 1] = angleBuffer[j*20 + i*2 + 1] + 360;
                    }
                }
            }
            else
                angleBuffer[j*20] = dataBuffer[0][j]/1e5; //最后一个点，无法线性插值.
        }
    }

    ui->timeChart->getData(AxisX, vibBuffer); //将振动数据绘制出来， 单通道绘制

    BalanceCal(); // 互相关运算

    ui->amplitude->setText(QString::number(amplitude, 'f', 4));//结果展示
    ui->phase->setText(QString::number(phase, 'f', 2));

    ui->stackedWidget->setCurrentWidget(ui->polarPage); //切换到动平衡显示界面
    ui->polarChart->setPoint(amplitude, phase);

}

void MainWindow::SaveData() //寄存器数据保存在DataSave文件夹中。
{
    if(sampleFinishFlag == 1)
    {
        int i = 0;
        time_t t = time(NULL); //获取当前时间
        QString filePath = "./DataSave/";
        char filename[64]={"\0"};

        strftime(filename,sizeof(filename),"RegData%Y-%m-%d %H-%M-%S.txt",localtime(&t));
        filePath = filePath + filename;
        QFile f(filePath); //创建txt文件

        f.open(QIODevice::Text | QIODevice::WriteOnly);
        QTextStream out(&f); //数据流

        out<< QStringLiteral("主轴角度")<< "   "<<QStringLiteral("振动数据")<<endl;

        for(i=0; i<MaxBufferLen*20 - 1; i++)
            out<< angleBuffer[i] << " "<< vibBuffer[i]<< "   "<<endl;

        f.close();
    }
    else
    {
        QMessageBox msgBox1;
        msgBox1.setWindowTitle(QStringLiteral("提示"));
        msgBox1.setText(QStringLiteral("采样不成功"));
        msgBox1.exec();
    }
}

void MainWindow::BalanceCal() //互相关运算
{
    int i, cal_len;
    int start_num = 0;
    double Rxy, Rxz, sin_tmp, cos_tmp;
    double pi = 3.1415926;
    double min = 30;
    cal_len = 3000*20; //计算时间为3s，60000个数据点
    Rxy = Rxz = 0;

    for(i=0; i < 10000; i++) //找到0相位附近的采样点 作为计算起始点
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

    for(i=start_num; i<start_num + cal_len; i++) //取3000*20个点进行计算， 若转速是50的整数倍，则过3s后一定是整周期
    {
        sin_tmp = sin( angleBuffer[i]*2.0*pi/360 ); //利用电机角度值获得互相关算法的sin和cos
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
    ui->stackedWidget->setCurrentWidget(ui->timePage); //切换到数据显示界面
}

void MainWindow::on_PolarButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->polarPage); //切换到动平衡显示界面
}

void MainWindow::on_ReadButton_clicked() //读取已有的数据文件, 运行多次有异常的BUG。不打算展示
{
    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("文件对话框"), "./DataSave", QString::fromLocal8Bit("文本文件(*txt)"));

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
    ui->timeChart->getData(__X, vibBuffer); //将振动数据绘制出来， 单通道绘制

    BalanceCal(); // 互相关运算

    ui->amplitude->setText(QString::number(amplitude, 'f', 4));//结果展示
    ui->phase->setText(QString::number(phase, 'f', 2));

    ui->stackedWidget->setCurrentWidget(ui->polarPage); //切换到动平衡显示界面
    ui->polarChart->setPoint(amplitude, phase);
}
