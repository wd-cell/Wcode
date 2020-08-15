#include "setchanneldialog.h"
#include "ui_setchanneldialog.h"
#include "hncapi.h"
#include "hncregdef.h"
#include "hncdatadef.h"
#include "netdialog.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QFile>

SetChannelDialog::SetChannelDialog(HncApi *hnc, QWidget *parent) :
    QDialog(parent),
    hncapi(hnc),
    ui(new Ui::SetChannelDialog),
    channelNum(new QList <int>), dataType(new QList<int>),axisNo(new QList<int>),offSet(new QList<int>),
    dataLen(new QList<int>), typeName(new QList<QString>), axisName(new QList<QString>),
    SetFlag(-1)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("配置"));//修改标题

    ui->tableWidget->setColumnCount(5);
    QStringList List;
    List<<QStringLiteral("通道号")<<QStringLiteral("数据类型")<<QStringLiteral("逻辑轴号")<<QStringLiteral("偏移量")<<QStringLiteral("数据长度");
    ui->tableWidget->setHorizontalHeaderLabels(List); //设置标题栏

    ui->tableWidget->setColumnWidth(0, 60); //设置列长度
    ui->tableWidget->setColumnWidth(1, 100);
    ui->tableWidget->setColumnWidth(2, 60);
    ui->tableWidget->setColumnWidth(3, 60);
    ui->tableWidget->setColumnWidth(4, 60);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(1); //最后一列随窗口改变而改变
    ui->tableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->tableWidget->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->tableWidget->setEditTriggers ( QAbstractItemView::NoEditTriggers );//禁止编辑

   ui->LEChnanelNum->setText("0");
   ui->LEOffSet->setText("0");
   ui->LELength->setText("0");

   ui->AddButton->setEnabled(false);
   ui->DeleteButton->setEnabled(false);
   ui->DelSetButton->setEnabled(false);

   ReadConfig();
   DefaultVibSet(); //默认通道配置

   connect(ui->BoxDataType, &QComboBox::currentIndexChanged, this, &SetChannelDialog::DataTypeBoxFunc);
}

SetChannelDialog::~SetChannelDialog()
{
    delete ui;
    delete channelNum, dataType, axisNo, offSet, dataLen, typeName, axisName;
}

void SetChannelDialog::on_AddButton_clicked() //添加按钮
{
    int tmp1 = ui->LEChnanelNum->text().toInt();
    channelNum->append(tmp1); //通道号

    int tmp2;
    QString str1 = ui->BoxDataType->currentText();//文字信息
    int index1 = ui->BoxDataType->currentIndex(); //索引
    GetBoxDataType(index1, tmp2); //解码对应
    dataType->append(tmp2); //数据类型
    typeName->append(str1); //数据名称

    int tmp3;
    QString str2 = ui->BoxAxisNo->currentText();
    int index2 = ui->BoxAxisNo->currentIndex();
    GetBoxAxisNo(index2,tmp3);
    axisNo->append(tmp3); //轴号类型
    axisName->append(str2); //轴号名称

    int tmp4 = ui->LEOffSet->text().toInt();
    offSet->append(tmp4); //偏置量

    int tmp5 = ui->LELength->text().toInt();
    dataLen->append(tmp5); //数据长度

    int rowIndex = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(rowIndex + 1);//总行数增加1

    ui->tableWidget->setItem(rowIndex,0,new QTableWidgetItem(ui->LEChnanelNum->text())); //
    ui->tableWidget->setItem(rowIndex,1,new QTableWidgetItem(str1));
    ui->tableWidget->setItem(rowIndex,2,new QTableWidgetItem(str2));
    ui->tableWidget->setItem(rowIndex,3,new QTableWidgetItem(ui->LEOffSet->text()));
    ui->tableWidget->setItem(rowIndex,4,new QTableWidgetItem(ui->LELength->text()));
}

void SetChannelDialog::on_DeleteButton_clicked() //删除按钮
{
    int rowIndex = ui->tableWidget->currentRow();//未选中任何行时返回-1。选中的行号从0记数
    if(rowIndex != -1)
    {
        int nRet = QMessageBox::question(NULL, QStringLiteral("询问"), QStringLiteral("是否删除数据"),
                                         QMessageBox::Yes, QMessageBox::No);

        if (QMessageBox::Yes == nRet)// 选择是
        {
            ui->tableWidget->removeRow(rowIndex); //删除行

            channelNum->removeAt(rowIndex); //删除对应的元素
            dataType->removeAt(rowIndex);
            typeName->removeAt(rowIndex);
            axisNo->removeAt(rowIndex);
            axisName->removeAt(rowIndex);
            offSet->removeAt(rowIndex);
            dataLen->removeAt(rowIndex);
        }
    }
}

void SetChannelDialog::on_SetButton_clicked()//配置按钮
{
    int tmp = hncapi->HNC_NetIsConnect();
    if( hncapi->HNC_NetIsConnect() == 0 )
    {
        int i;
        for (i=0; i < channelNum->size(); i++ )
        {
           hncapi->HNC_SamplSetChannel(channelNum->at(i), dataType->at(i), axisNo->at(i), offSet->at(i), dataLen->at(i));
        }

        hncapi->HNC_SamplSetPeriod(1);//设置采样周期

        QMessageBox msgBox1;
        msgBox1.setWindowTitle(QStringLiteral("提示"));
        msgBox1.setText(QStringLiteral("配置成功"));
        msgBox1.exec();
        SetFlag = 0;

        return;
    }
    else
    {
        QMessageBox msgBox1;
        msgBox1.setWindowTitle(QStringLiteral("提示"));
        msgBox1.setText(QStringLiteral("网络未连接，请先连接网络"));
        msgBox1.exec();
        return;
    }
}

void SetChannelDialog::on_DelSetButton_clicked() //清除配置按钮
{
    int nRet = QMessageBox::question(NULL, QStringLiteral("询问"), QStringLiteral("是否清空所有配置"),
                                     QMessageBox::Yes, QMessageBox::No);
    int i;
    if (QMessageBox::Yes == nRet)// 选择是
    {
        SetFlag = -1; //设置标志位变为-1
        for (i=0; i < channelNum->size(); i++ )
        {
           hncapi->HNC_SamplRemoveConfig(dataType->at(i), axisNo->at(i), offSet->at(i), dataLen->at(i));
        }
        ui->tableWidget->clearContents();//清空内容
        ui->tableWidget->setRowCount(0);//行数设置为0

        channelNum->clear();
        dataType->clear();
        typeName->clear();
        axisNo->clear();
        axisName->clear();
        offSet->clear();
        dataLen->clear();
    }
}

void SetChannelDialog::DataTypeBoxFunc(int index) //根据数据类型的不同确定是否需要 偏置量 和 数据长度 使能
{
    int tmp;
    GetBoxDataType(index, tmp);

    if(tmp > 100) //变量数据需要设置偏置和数据长度
    {
        ui->LEOffSet->setEnabled(true);
        ui->LELength->setEnabled(true);
    }
    else
    {
        ui->LEOffSet->setEnabled(false);
        ui->LELength->setEnabled(false);
        ui->LEOffSet->setText("0");
        ui->LELength->setText("0");
    }
}

void GetBoxDataType(int index, int &tmp) //数据类型按钮的解码及对应函数
{
    switch (index) {
    case 0:
        tmp = SAMPL_X_REG;		/*!< X寄存器 */
        break;
    case 1:
        tmp = SAMPL_Y_REG;	/*!< Y寄存器 */
        break;
    case 2:
        tmp = SAMPL_CMD_POS;		/*!< 指令电机位置 */
        break;
    case 3:
        tmp = SAMPL_ACT_POS;		/*!< 实际电机位置 */
        break;
    case 4:
        tmp = SAMPL_AXIS_CMD;	/*!< 轴的指令位置 */
        break;
    case 5:
        tmp = SAMPL_AXIS_ACT;		/*!< 轴的实际位置 */
        break;
    case 6:
        tmp = SAMPL_CHAN_VAL;	/*!< 通道变量 */
        break;
    case 7:
        tmp = SAMPL_AXIS_VAL;		/*!< 轴变量 */
        break;
    case 8:
        tmp = SAMPL_SYS_VAL;	/*!< 系统变量 */
        break;
    default:
        break;
    }
}

void GetBoxAxisNo(int index, int &tmp)//逻辑轴号按钮的解码函数
{
    if(index == 3) tmp = 5;// 主轴逻辑号设置为5
    else tmp = index;
}

int SetChannelDialog::GetOffSet(int index) //偏移量
{
    return offSet->at(index);
}

void SetChannelDialog::DefaultVibSet() //默认振动配置
{
    channelNum->append(0); dataType->append(SAMPL_AXIS_ACT/*SAMPL_AXIS_CMD*/); typeName->append(QStringLiteral("实际位置")); axisNo->append(5); axisName->append(QStringLiteral("C轴")); offSet->append(0); dataLen->append(0);

    channelNum->append(1); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X寄存器")); axisNo->append(5); axisName->append(QStringLiteral("C轴")); offSet->append(start_offset+0); dataLen->append(4);
    channelNum->append(2); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X寄存器")); axisNo->append(5); axisName->append(QStringLiteral("C轴")); offSet->append(start_offset+4); dataLen->append(4);
    channelNum->append(3); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X寄存器")); axisNo->append(5); axisName->append(QStringLiteral("C轴")); offSet->append(start_offset+8); dataLen->append(4);
    channelNum->append(4); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X寄存器")); axisNo->append(5); axisName->append(QStringLiteral("C轴")); offSet->append(start_offset+12); dataLen->append(4);
    channelNum->append(5); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X寄存器")); axisNo->append(5); axisName->append(QStringLiteral("C轴")); offSet->append(start_offset+16); dataLen->append(4);
    channelNum->append(6); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X寄存器")); axisNo->append(5); axisName->append(QStringLiteral("C轴")); offSet->append(start_offset+20); dataLen->append(4);
    channelNum->append(7); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X寄存器")); axisNo->append(5); axisName->append(QStringLiteral("C轴")); offSet->append(start_offset+24); dataLen->append(4);
    channelNum->append(8); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X寄存器")); axisNo->append(5); axisName->append(QStringLiteral("C轴")); offSet->append(start_offset+28); dataLen->append(4);
    channelNum->append(9); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X寄存器")); axisNo->append(5); axisName->append(QStringLiteral("C轴")); offSet->append(start_offset+32); dataLen->append(4);
    channelNum->append(10); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X寄存器")); axisNo->append(5); axisName->append(QStringLiteral("C轴")); offSet->append(start_offset+36); dataLen->append(4);

    int rowIndex = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(rowIndex + 1);//总行数增加1
    ui->tableWidget->setItem(rowIndex,0,new QTableWidgetItem(QString::number(0))); //
    ui->tableWidget->setItem(rowIndex,1,new QTableWidgetItem(QStringLiteral("实际电机位置")));
    ui->tableWidget->setItem(rowIndex,2,new QTableWidgetItem(QStringLiteral("C轴")));
    ui->tableWidget->setItem(rowIndex,3,new QTableWidgetItem(QString::number(0)));
    ui->tableWidget->setItem(rowIndex,4,new QTableWidgetItem(QString::number(0)));

    for(int i=1; i<11; i++)
    {
        int rowIndex = ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(rowIndex + 1);//总行数增加1
        ui->tableWidget->setItem(rowIndex,0,new QTableWidgetItem(QString::number(i))); //
        ui->tableWidget->setItem(rowIndex,1,new QTableWidgetItem(QStringLiteral("X寄存器")));
        ui->tableWidget->setItem(rowIndex,2,new QTableWidgetItem(QStringLiteral("C轴")));
        ui->tableWidget->setItem(rowIndex,3,new QTableWidgetItem(QString::number( (i-1)*4 + start_offset )));
        ui->tableWidget->setItem(rowIndex,4,new QTableWidgetItem(QString::number(4)));
    }
}

void SetChannelDialog::ReadConfig()//读取配置文件信息
{
    QFile file("./resource/OffsetConfig.txt");
    QString info[2];

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
    start_offset = info[0].toInt();
}
