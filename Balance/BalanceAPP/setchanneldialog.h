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

void GetBoxDataType(int index, int &tmp); //数据类型按钮的解码及对应函数
void GetBoxAxisNo(int index, int &tmp); //逻辑轴号按钮的解码函数

class SetChannelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetChannelDialog(HncApi *hnc, QWidget *parent = 0);
    ~SetChannelDialog();

    int SetFlag; //通道设置的标志位。0设置成功，-1未设置
    QList <QString> *typeName;
    QList <QString> *axisName;

    int GetOffSet(int index);//获取对应的偏置量

    void DefaultVibSet(); //默认的动平衡配置

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
