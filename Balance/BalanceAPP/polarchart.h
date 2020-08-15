#ifndef POLARCHART_H
#define POLARCHART_H

#include <QWidget>

class PolarChart : public QWidget
{
    Q_OBJECT
public:
    explicit PolarChart(QWidget *parent = 0);
    ~PolarChart();

    void setPolarRect(QRect& polarRect);
/******************************
 * setPoint
 * ptPoint:不平衡量点
 * *****************************/
    void setPoint(QPointF& ptPoint);
    void setPoint(double amplitude, double phase);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);

private:
    QPoint m_ptCenter;
    QRect m_polarRect;
    QPointF m_ptPoint;
    double Max_Amplitude;
};

#endif // POLARCHART_H
