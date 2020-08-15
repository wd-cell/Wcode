#ifndef TIMEDOMCHART_H
#define TIMEDOMCHART_H

#include <QWidget>
#include <QVector>
#include "qcustomplot.h"
#include <QRect>

class TimeDomChart : public QWidget
{
    Q_OBJECT
public:
    explicit TimeDomChart(QWidget *parent = 0);

signals:

public slots:
    void mousePressEvent(QMouseEvent *event);   //矩形缩放鼠标按下
    void mouseReleaseEvent(QMouseEvent *event); //矩形缩放鼠标释放
    void mouseMoveEvent(QMouseEvent *event);    //矩形缩放鼠标移动
    void zoomReset();

private:
    QRubberBand *rubberBand;    //橡皮筋
    QPoint rubberOrigin;        //橡皮筋起点
public:
    QCustomPlot *m_customPlot;
    QMenu *m_popMenu;
    QAction *m_actZoomReset;
    QCPGraph *plotCh[3];        //曲线指针数组
/***************************
 *  getData
 * 获取波形图的显示数据
 * vecDataX:横坐标数据
 * vecDataY:纵坐标数据
 * ***************************/
    void getData(QVector<double> &vecDataX, QVector<QVector<double>> &vecDataY, int index);
    void getData(QVector<double> &vecDataX, QVector<double> &vecDataY);
/******************************
 * setChannelShow
 * 设置曲线的显示，显示将bArrShow[]相应值设为true,不显示设为false
 * bArrShow[]:曲线显示与否的布尔数组
 * ****************************/
    void setChannelShow(bool bArrShow[]);
};

#endif // TIMEDOMCHART_H
