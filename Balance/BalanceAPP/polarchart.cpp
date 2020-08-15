#include "polarchart.h"
#include <QPainter>
#include <QDebug>
#include <QLabel>

PolarChart::PolarChart(QWidget *parent) : QWidget(parent)
{
    Max_Amplitude = 0.5; //
    m_ptPoint = QPoint(0, 0);
}

PolarChart::~PolarChart()
{
}

void PolarChart::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    QPen pen = QPen(QColor(Qt::darkCyan));
    painter->setPen(pen);

    painter->translate(m_polarRect.width()/2, m_polarRect.height()/2);
    painter->rotate(-90);
    //极坐标中心点
    m_ptCenter = QPoint (0, 0);

    //画线
    painter->drawLine(-(m_polarRect.width()/2), 0, m_polarRect.width()/2, 0);
    painter->drawLine(0, -(m_polarRect.height()/2), 0, m_polarRect.height()/2);

    //圆环
    int i = 0;
    for(i=1; i<= 5; i++) painter->drawEllipse(m_ptCenter, i*25, i*25);

    //不平衡量点
    pen.setWidth(10);
    pen.setColor(Qt::red);
    painter->setPen(pen);
    painter->setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter->drawEllipse(m_ptPoint, 3, 3);

    painter->rotate(90);
    painter->drawText(130, 0, "0°");
    painter->drawText(2, -130, "90°");
    painter->drawText(-140, 0, "180°");
    painter->drawText(2, 135, "270°");

    painter->drawText(25, 9, "0.1");
    painter->drawText(50, 9, "0.2");
    painter->drawText(75, 9, "0.3");
    painter->drawText(100, 9, "0.4");
    painter->drawText(125, 9, "0.5");

}


void PolarChart::setPolarRect(QRect &polarRect)
{
    m_polarRect = polarRect;
    update();
}

void PolarChart::setPoint(QPointF &ptPoint)
{
    m_ptPoint = ptPoint;
    update();
}

void PolarChart::setPoint(double amplitude, double phase)
{
    double pi = 3.1415926;
    double angle = phase * pi / 180;
    amplitude = amplitude / Max_Amplitude * 125;

    m_ptPoint.setX(amplitude * sin(angle));
    m_ptPoint.setY(amplitude * cos(angle));

    qDebug()<<m_ptPoint;
    update();
}
