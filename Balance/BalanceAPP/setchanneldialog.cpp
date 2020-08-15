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
    this->setWindowTitle(QStringLiteral("����"));//�޸ı���

    ui->tableWidget->setColumnCount(5);
    QStringList List;
    List<<QStringLiteral("ͨ����")<<QStringLiteral("��������")<<QStringLiteral("�߼����")<<QStringLiteral("ƫ����")<<QStringLiteral("���ݳ���");
    ui->tableWidget->setHorizontalHeaderLabels(List); //���ñ�����

    ui->tableWidget->setColumnWidth(0, 60); //�����г���
    ui->tableWidget->setColumnWidth(1, 100);
    ui->tableWidget->setColumnWidth(2, 60);
    ui->tableWidget->setColumnWidth(3, 60);
    ui->tableWidget->setColumnWidth(4, 60);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(1); //���һ���洰�ڸı���ı�
    ui->tableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows); //����ѡ����Ϊ������Ϊ��λ
    ui->tableWidget->setSelectionMode ( QAbstractItemView::SingleSelection); //����ѡ��ģʽ��ѡ����
    ui->tableWidget->setEditTriggers ( QAbstractItemView::NoEditTriggers );//��ֹ�༭

   ui->LEChnanelNum->setText("0");
   ui->LEOffSet->setText("0");
   ui->LELength->setText("0");

   ui->AddButton->setEnabled(false);
   ui->DeleteButton->setEnabled(false);
   ui->DelSetButton->setEnabled(false);

   ReadConfig();
   DefaultVibSet(); //Ĭ��ͨ������

   connect(ui->BoxDataType, &QComboBox::currentIndexChanged, this, &SetChannelDialog::DataTypeBoxFunc);
}

SetChannelDialog::~SetChannelDialog()
{
    delete ui;
    delete channelNum, dataType, axisNo, offSet, dataLen, typeName, axisName;
}

void SetChannelDialog::on_AddButton_clicked() //��Ӱ�ť
{
    int tmp1 = ui->LEChnanelNum->text().toInt();
    channelNum->append(tmp1); //ͨ����

    int tmp2;
    QString str1 = ui->BoxDataType->currentText();//������Ϣ
    int index1 = ui->BoxDataType->currentIndex(); //����
    GetBoxDataType(index1, tmp2); //�����Ӧ
    dataType->append(tmp2); //��������
    typeName->append(str1); //��������

    int tmp3;
    QString str2 = ui->BoxAxisNo->currentText();
    int index2 = ui->BoxAxisNo->currentIndex();
    GetBoxAxisNo(index2,tmp3);
    axisNo->append(tmp3); //�������
    axisName->append(str2); //�������

    int tmp4 = ui->LEOffSet->text().toInt();
    offSet->append(tmp4); //ƫ����

    int tmp5 = ui->LELength->text().toInt();
    dataLen->append(tmp5); //���ݳ���

    int rowIndex = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(rowIndex + 1);//����������1

    ui->tableWidget->setItem(rowIndex,0,new QTableWidgetItem(ui->LEChnanelNum->text())); //
    ui->tableWidget->setItem(rowIndex,1,new QTableWidgetItem(str1));
    ui->tableWidget->setItem(rowIndex,2,new QTableWidgetItem(str2));
    ui->tableWidget->setItem(rowIndex,3,new QTableWidgetItem(ui->LEOffSet->text()));
    ui->tableWidget->setItem(rowIndex,4,new QTableWidgetItem(ui->LELength->text()));
}

void SetChannelDialog::on_DeleteButton_clicked() //ɾ����ť
{
    int rowIndex = ui->tableWidget->currentRow();//δѡ���κ���ʱ����-1��ѡ�е��кŴ�0����
    if(rowIndex != -1)
    {
        int nRet = QMessageBox::question(NULL, QStringLiteral("ѯ��"), QStringLiteral("�Ƿ�ɾ������"),
                                         QMessageBox::Yes, QMessageBox::No);

        if (QMessageBox::Yes == nRet)// ѡ����
        {
            ui->tableWidget->removeRow(rowIndex); //ɾ����

            channelNum->removeAt(rowIndex); //ɾ����Ӧ��Ԫ��
            dataType->removeAt(rowIndex);
            typeName->removeAt(rowIndex);
            axisNo->removeAt(rowIndex);
            axisName->removeAt(rowIndex);
            offSet->removeAt(rowIndex);
            dataLen->removeAt(rowIndex);
        }
    }
}

void SetChannelDialog::on_SetButton_clicked()//���ð�ť
{
    int tmp = hncapi->HNC_NetIsConnect();
    if( hncapi->HNC_NetIsConnect() == 0 )
    {
        int i;
        for (i=0; i < channelNum->size(); i++ )
        {
           hncapi->HNC_SamplSetChannel(channelNum->at(i), dataType->at(i), axisNo->at(i), offSet->at(i), dataLen->at(i));
        }

        hncapi->HNC_SamplSetPeriod(1);//���ò�������

        QMessageBox msgBox1;
        msgBox1.setWindowTitle(QStringLiteral("��ʾ"));
        msgBox1.setText(QStringLiteral("���óɹ�"));
        msgBox1.exec();
        SetFlag = 0;

        return;
    }
    else
    {
        QMessageBox msgBox1;
        msgBox1.setWindowTitle(QStringLiteral("��ʾ"));
        msgBox1.setText(QStringLiteral("����δ���ӣ�������������"));
        msgBox1.exec();
        return;
    }
}

void SetChannelDialog::on_DelSetButton_clicked() //������ð�ť
{
    int nRet = QMessageBox::question(NULL, QStringLiteral("ѯ��"), QStringLiteral("�Ƿ������������"),
                                     QMessageBox::Yes, QMessageBox::No);
    int i;
    if (QMessageBox::Yes == nRet)// ѡ����
    {
        SetFlag = -1; //���ñ�־λ��Ϊ-1
        for (i=0; i < channelNum->size(); i++ )
        {
           hncapi->HNC_SamplRemoveConfig(dataType->at(i), axisNo->at(i), offSet->at(i), dataLen->at(i));
        }
        ui->tableWidget->clearContents();//�������
        ui->tableWidget->setRowCount(0);//��������Ϊ0

        channelNum->clear();
        dataType->clear();
        typeName->clear();
        axisNo->clear();
        axisName->clear();
        offSet->clear();
        dataLen->clear();
    }
}

void SetChannelDialog::DataTypeBoxFunc(int index) //�����������͵Ĳ�ͬȷ���Ƿ���Ҫ ƫ���� �� ���ݳ��� ʹ��
{
    int tmp;
    GetBoxDataType(index, tmp);

    if(tmp > 100) //����������Ҫ����ƫ�ú����ݳ���
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

void GetBoxDataType(int index, int &tmp) //�������Ͱ�ť�Ľ��뼰��Ӧ����
{
    switch (index) {
    case 0:
        tmp = SAMPL_X_REG;		/*!< X�Ĵ��� */
        break;
    case 1:
        tmp = SAMPL_Y_REG;	/*!< Y�Ĵ��� */
        break;
    case 2:
        tmp = SAMPL_CMD_POS;		/*!< ָ����λ�� */
        break;
    case 3:
        tmp = SAMPL_ACT_POS;		/*!< ʵ�ʵ��λ�� */
        break;
    case 4:
        tmp = SAMPL_AXIS_CMD;	/*!< ���ָ��λ�� */
        break;
    case 5:
        tmp = SAMPL_AXIS_ACT;		/*!< ���ʵ��λ�� */
        break;
    case 6:
        tmp = SAMPL_CHAN_VAL;	/*!< ͨ������ */
        break;
    case 7:
        tmp = SAMPL_AXIS_VAL;		/*!< ����� */
        break;
    case 8:
        tmp = SAMPL_SYS_VAL;	/*!< ϵͳ���� */
        break;
    default:
        break;
    }
}

void GetBoxAxisNo(int index, int &tmp)//�߼���Ű�ť�Ľ��뺯��
{
    if(index == 3) tmp = 5;// �����߼�������Ϊ5
    else tmp = index;
}

int SetChannelDialog::GetOffSet(int index) //ƫ����
{
    return offSet->at(index);
}

void SetChannelDialog::DefaultVibSet() //Ĭ��������
{
    channelNum->append(0); dataType->append(SAMPL_AXIS_ACT/*SAMPL_AXIS_CMD*/); typeName->append(QStringLiteral("ʵ��λ��")); axisNo->append(5); axisName->append(QStringLiteral("C��")); offSet->append(0); dataLen->append(0);

    channelNum->append(1); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X�Ĵ���")); axisNo->append(5); axisName->append(QStringLiteral("C��")); offSet->append(start_offset+0); dataLen->append(4);
    channelNum->append(2); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X�Ĵ���")); axisNo->append(5); axisName->append(QStringLiteral("C��")); offSet->append(start_offset+4); dataLen->append(4);
    channelNum->append(3); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X�Ĵ���")); axisNo->append(5); axisName->append(QStringLiteral("C��")); offSet->append(start_offset+8); dataLen->append(4);
    channelNum->append(4); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X�Ĵ���")); axisNo->append(5); axisName->append(QStringLiteral("C��")); offSet->append(start_offset+12); dataLen->append(4);
    channelNum->append(5); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X�Ĵ���")); axisNo->append(5); axisName->append(QStringLiteral("C��")); offSet->append(start_offset+16); dataLen->append(4);
    channelNum->append(6); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X�Ĵ���")); axisNo->append(5); axisName->append(QStringLiteral("C��")); offSet->append(start_offset+20); dataLen->append(4);
    channelNum->append(7); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X�Ĵ���")); axisNo->append(5); axisName->append(QStringLiteral("C��")); offSet->append(start_offset+24); dataLen->append(4);
    channelNum->append(8); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X�Ĵ���")); axisNo->append(5); axisName->append(QStringLiteral("C��")); offSet->append(start_offset+28); dataLen->append(4);
    channelNum->append(9); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X�Ĵ���")); axisNo->append(5); axisName->append(QStringLiteral("C��")); offSet->append(start_offset+32); dataLen->append(4);
    channelNum->append(10); dataType->append(SAMPL_X_REG); typeName->append(QStringLiteral("X�Ĵ���")); axisNo->append(5); axisName->append(QStringLiteral("C��")); offSet->append(start_offset+36); dataLen->append(4);

    int rowIndex = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(rowIndex + 1);//����������1
    ui->tableWidget->setItem(rowIndex,0,new QTableWidgetItem(QString::number(0))); //
    ui->tableWidget->setItem(rowIndex,1,new QTableWidgetItem(QStringLiteral("ʵ�ʵ��λ��")));
    ui->tableWidget->setItem(rowIndex,2,new QTableWidgetItem(QStringLiteral("C��")));
    ui->tableWidget->setItem(rowIndex,3,new QTableWidgetItem(QString::number(0)));
    ui->tableWidget->setItem(rowIndex,4,new QTableWidgetItem(QString::number(0)));

    for(int i=1; i<11; i++)
    {
        int rowIndex = ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(rowIndex + 1);//����������1
        ui->tableWidget->setItem(rowIndex,0,new QTableWidgetItem(QString::number(i))); //
        ui->tableWidget->setItem(rowIndex,1,new QTableWidgetItem(QStringLiteral("X�Ĵ���")));
        ui->tableWidget->setItem(rowIndex,2,new QTableWidgetItem(QStringLiteral("C��")));
        ui->tableWidget->setItem(rowIndex,3,new QTableWidgetItem(QString::number( (i-1)*4 + start_offset )));
        ui->tableWidget->setItem(rowIndex,4,new QTableWidgetItem(QString::number(4)));
    }
}

void SetChannelDialog::ReadConfig()//��ȡ�����ļ���Ϣ
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
