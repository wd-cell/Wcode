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
    this->setWindowTitle(QStringLiteral("连接"));//修改标题

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

void NetDialog::on_pushButton_clicked() //按钮槽函数
{
    NetConnect();
}

void NetDialog::NetConnect() //网络初始化及连接函数
{
    /************************************Initial*******************************/
    QByteArray tmp1 = ui->UppIp->text().toLatin1();
    upperIP = tmp1.data(); //上位机IP

    int tmp2 = ui->UppPort->text().toInt();
    upperPort = tmp2; //上位机Port

    QByteArray tmp3 = ui->ProcessName->text().toLatin1();
    processName = tmp3.data(); //进程名

    int InitFlag = -1;

    InitFlag = hncapi->HNC_NetInit(upperIP, upperPort, processName);

    if(InitFlag != 0) //初始化失败
    {
        QMessageBox msgBox1;
        msgBox1.setWindowTitle(QStringLiteral("提示"));
        msgBox1.setText(QStringLiteral("初始化失败，请检查适配器是否开启"));
        msgBox1.exec();
        return;
    }
    /************************************Connect*******************************/
    QByteArray tmp4 = ui->LowIP->text().toLatin1();
    lowerIP = tmp4.data(); //下位机IP

    int tmp5 = ui->LowPort->text().toInt();
    lowerPort = tmp5; //下位机Port

    InitFlag = -1;
    InitFlag = hncapi->HNC_NetConnect(lowerIP, lowerPort,OnConnectCallBack); /*hncapi->HNC_NetConnect(lowerIP, lowerPort)*/

    if(InitFlag != 0) //连接失败
    {
        QMessageBox msgBox2;
        msgBox2.setWindowTitle(QStringLiteral("提示"));
        msgBox2.setText(QStringLiteral("初始化失败，请检查网线是否插上"));
        msgBox2.exec();
        return;
    }
    else if(InitFlag ==0) //连接成功
    {
        ConnectFlag = 0;
        QMessageBox msgBox3;
        msgBox3.setWindowTitle(QStringLiteral("提示"));
        msgBox3.setText(QStringLiteral("网络已连接"));
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

void NetDialog::ReadConfig()//读取配置文件信息
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
    info[0].chop(1);//除去最后一个换行符'\n'
    info[1].chop(1);
    ui->UppIp->setText(info[0]);
    ui->LowIP->setText(info[1]);
    ui->LowPort->setText(info[2]);
}

void NetDialog::WriteConfig() //保存相应的网络配置
{
    QFile f("./resource/NetConfig.txt"); //创建txt文件

    f.open(QIODevice::Text | QIODevice::WriteOnly);
    QTextStream out(&f); //数据流

    out<< ui->UppIp->text()<<endl;
    out<< ui->LowIP->text()<<endl;
    out<< ui->LowPort->text();
    f.close();
}
