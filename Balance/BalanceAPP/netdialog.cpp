#include "netdialog.h"
#include "ui_netdialog.h"
#include "hncapi.h"
#include <QString>
#include "QMessageBox"
#include <QDebug>
#include <QFile>
#include <iostream>

NetDialog::NetDialog(HncApi *hnc, QWidget *parent):
    QDialog(parent),
    hncapi(hnc),
    ui(new Ui::NetDialog),
    ConnectFlag(-1)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("����"));//�޸ı���

    QString qstr;

    ui->UppPort->setText(qstr.setNum(9090));
    ui->UppPort->setEnabled(false);
    ui->ProcessName->setText("BalanceAPP");
    ui->ProcessName->setEnabled(false);

    ReadConfig();
}

NetDialog::~NetDialog()
{
    delete ui;
}

void NetDialog::on_pushButton_clicked() //��ť�ۺ���
{
    NetConnect();
}

void NetDialog::NetConnect() //�����ʼ�������Ӻ���
{
    /************************************Initial*******************************/
    QByteArray tmp1 = ui->UppIp->text().toLatin1();
    upperIP = tmp1.data(); //��λ��IP

    int tmp2 = ui->UppPort->text().toInt();
    upperPort = tmp2; //��λ��Port

    QByteArray tmp3 = ui->ProcessName->text().toLatin1();
    processName = tmp3.data(); //������

    int InitFlag = -1;

    InitFlag = hncapi->HNC_NetInit(upperIP, upperPort, processName);

    if(InitFlag != 0) //��ʼ��ʧ��
    {
        QMessageBox msgBox1;
        msgBox1.setWindowTitle(QStringLiteral("��ʾ"));
        msgBox1.setText(QStringLiteral("��ʼ��ʧ�ܣ������������Ƿ���"));
        msgBox1.exec();
        return;
    }
    /************************************Connect*******************************/
    QByteArray tmp4 = ui->LowIP->text().toLatin1();
    lowerIP = tmp4.data(); //��λ��IP

    int tmp5 = ui->LowPort->text().toInt();
    lowerPort = tmp5; //��λ��Port

    InitFlag = -1;
    InitFlag = hncapi->HNC_NetConnect(lowerIP, lowerPort,OnConnectCallBack); /*hncapi->HNC_NetConnect(lowerIP, lowerPort)*/

    if(InitFlag != 0) //����ʧ��
    {
        QMessageBox msgBox2;
        msgBox2.setWindowTitle(QStringLiteral("��ʾ"));
        msgBox2.setText(QStringLiteral("��ʼ��ʧ�ܣ����������Ƿ����"));
        msgBox2.exec();
        return;
    }
    else if(InitFlag ==0) //���ӳɹ�
    {
        ConnectFlag = 0;
        QMessageBox msgBox3;
        msgBox3.setWindowTitle(QStringLiteral("��ʾ"));
        msgBox3.setText(QStringLiteral("����������"));
        qDebug()<<hncapi->HNC_NetIsConnect();
        msgBox3.exec();
    }
    /************************************SaveNetConfig*******************************/
    WriteConfig();
}

void OnConnectCallBack(const string& ip, uBit16 port, bool result)
{
    if (result)
        qDebug()<<"success";
    else
        qDebug()<<"fial";
}

void NetDialog::ReadConfig()//��ȡ�����ļ���Ϣ
{
    QFile file("./resource/NetConfig.txt");
    QString info[3];

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }

    int i=0;
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        info[i] = str;
        i++;
    }
    info[0].chop(1);//��ȥ���һ�����з�'\n'
    info[1].chop(1);
    ui->UppIp->setText(info[0]);
    ui->LowIP->setText(info[1]);
    ui->LowPort->setText(info[2]);
}

void NetDialog::WriteConfig() //������Ӧ����������
{
    QFile f("./resource/NetConfig.txt"); //����txt�ļ�

    f.open(QIODevice::Text | QIODevice::WriteOnly);
    QTextStream out(&f); //������

    out<< ui->UppIp->text()<<endl;
    out<< ui->LowIP->text()<<endl;
    out<< ui->LowPort->text();
    f.close();
}
