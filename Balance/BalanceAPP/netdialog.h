#ifndef NETDIALOG_H
#define NETDIALOG_H

#include "hncdatatype.h"
#include "hncapi.h"
#include <QDialog>

namespace Ui {
class NetDialog;
}
class HncApi;

void OnConnectCallBack(const string& ip, uBit16 port, bool result);

class NetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NetDialog(HncApi *hnc, QWidget *parent = 0);
    ~NetDialog();
    void NetConnect();
    Bit16 ConnectFlag; //连接成功标志位, 0为成功

    void ReadConfig();
    void WriteConfig();


private:
    Ui::NetDialog *ui;
    HncApi *hncapi; //该对象由mainwindow传入

    Bit8 *upperIP, *lowerIP;
    uBit16 upperPort, lowerPort;
    Bit8 *processName;

private slots:
    void on_pushButton_clicked();


};

#endif // NETDIALOG_H
