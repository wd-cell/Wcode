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

    void CheckFlag(int flag); //����־λ�Ƿ���1���������ź�

    void BalanceCal(); //��ƽ�����

private:
    Ui::MainWindow *ui;
    HncApi *hnc;
    NetDialog *netdiag; //�������ô���

    SetChannelDialog *setdiag; //ͨ�����ô���
    QTimer *ms_200;

    QVector<int> bufferCnt; //�������Ȼ���
    QVector<QVector <double>> dataBuffer; //�������ݻ���
    QVector <double> vibBuffer; //������
    QVector <double> angleBuffer; //1K�����õ��ĵ���Ƕ�ֵ����20K��Ƶ�����Բ�ֵ

    QVector<double> AxisX; // ��ͼ��������Ҫ��X��Vector,0~49999

    int sampleFinishFlag; //������ɱ�־λ
    double amplitude, phase; //��ֵ����λ

signals:
    void FlagValueChange();//�źŷ��ͺ���

private slots:
    void NetDiagShow(); //��������
    void SetChShow(); //
    void StartSample();
    void GetData();
    void SaveData(); //����Ĵ����ɼ��������ݺ���
    void Transfer();

    void on_PlotButton_clicked();
    void on_PolarButton_clicked();
    void on_ReadButton_clicked();
};
#endif // MAINWINDOW_H
