#ifndef SETCHANNELDIALOG_H
#define SETCHANNELDIALOG_H

#include <QDialog>
#include <QList>
#include <QString>
namespace Ui {
class SetChannelDialog;
}
class HncApi;
class NetDialog;

void GetBoxDataType(int index, int &tmp); //�������Ͱ�ť�Ľ��뼰��Ӧ����
void GetBoxAxisNo(int index, int &tmp); //�߼���Ű�ť�Ľ��뺯��

class SetChannelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetChannelDialog(HncApi *hnc, QWidget *parent = 0);
    ~SetChannelDialog();

    int SetFlag; //ͨ�����õı�־λ��0���óɹ���-1δ����
    QList <QString> *typeName;
    QList <QString> *axisName;

    int GetOffSet(int index);//��ȡ��Ӧ��ƫ����

    void DefaultVibSet(); //Ĭ�ϵĶ�ƽ������

    void ReadConfig();

private:
    Ui::SetChannelDialog *ui;
    HncApi *hncapi;
    QList <int> *channelNum;
    QList <int> *dataType;
    QList <int> *axisNo;
    QList <int> *offSet;
    QList <int> *dataLen;
    int start_offset;

private slots:
    void on_AddButton_clicked(); //
    void on_DeleteButton_clicked();
    void DataTypeBoxFunc(int index);
    void on_SetButton_clicked();
    void on_DelSetButton_clicked();
};

#endif // SETCHANNELDIALOG_H
