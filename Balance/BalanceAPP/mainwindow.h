#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <hncdatatype.h>

namespace Ui {
class MainWindow;
}
class HncApi;
class NetDialog;
class SetChannelDialog;
class QTimer;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void CheckFlag(int flag); //检查标志位是否置1，是则发送信号

    void BalanceCal(); //动平衡计算

private:
    Ui::MainWindow *ui;
    HncApi *hnc;
    NetDialog *netdiag; //网络配置窗口

    SetChannelDialog *setdiag; //通道配置窗口
    QTimer *ms_200;

    QVector<int> bufferCnt; //采样长度缓存
    QVector<QVector <double>> dataBuffer; //采样数据缓存
    QVector <double> vibBuffer; //振动数据
    QVector <double> angleBuffer; //1K采样得到的电机角度值按照20K的频率线性插值

    QVector<double> AxisX; // 绘图参数所需要的X轴Vector,0~49999

    int sampleFinishFlag; //采样完成标志位
    double amplitude, phase; //幅值，相位

signals:
    void FlagValueChange();//信号发送函数

private slots:
    void NetDiagShow(); //网络连接
    void SetChShow(); //
    void StartSample();
    void GetData();
    void SaveData(); //保存寄存器采集到的数据函数
    void Transfer();

    void on_PlotButton_clicked();
    void on_PolarButton_clicked();
    void on_ReadButton_clicked();
};
#endif // MAINWINDOW_H
