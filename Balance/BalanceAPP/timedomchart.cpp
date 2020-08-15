#include "timedomchart.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>
#include <QRect>


TimeDomChart::TimeDomChart(QWidget *parent) : QWidget(parent)
{
    QLabel *label = new QLabel(this);
    label->resize(QSize(540, 270));

    // 把控件添加到布局上
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(label);
    m_customPlot = new QCustomPlot (label);
    m_customPlot->resize(label->size());
    rubberBand = new QRubberBand(QRubberBand::Rectangle, m_customPlot);
    //设置图例
//    m_customPlot->legend->setVisible(true);
//    QFont legendFont;
//    legendFont.setPointSize(9);
//    m_customPlot->setFont(legendFont);
//    m_customPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));

    m_customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);//
    //添加标题
//    m_customPlot->plotLayout()->insertRow(0);
//    m_customPlot->plotLayout()->addElement(0, 0,
//    new QCPTextElement(m_customPlot, "时域", QFont("宋体", 10, QFont::Bold)));
    m_customPlot->yAxis->setLabel("vib/(m/s^2)");

    //添加曲线
    plotCh[0] = m_customPlot->addGraph();
    plotCh[0]->setPen(QPen(QColor(255,0,0)));
    plotCh[0]->setLineStyle(QCPGraph::lsLine);
    plotCh[0]->setName("CH0");

//    plotCh[1] = m_customPlot->addGraph();
//    plotCh[1]->setPen(QPen(QColor(0,255,0)));
//    plotCh[1]->setLineStyle(QCPGraph::lsLine);
//    plotCh[1]->setName("CH1");
//    plotCh[2] = m_customPlot->addGraph();
//    plotCh[2]->setPen(QPen(QColor(0,0,255)));
//    plotCh[2]->setLineStyle(QCPGraph::lsLine);
//    plotCh[2]->setName("CH2");

    //矩形缩放
    connect(m_customPlot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePressEvent(QMouseEvent*)));
    connect(m_customPlot, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(mouseReleaseEvent(QMouseEvent*)));
    connect(m_customPlot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMoveEvent(QMouseEvent*)));

    //菜单
    m_popMenu = new QMenu();
    m_actZoomReset = new QAction(this);
    m_actZoomReset->setText(tr("zoom reset"));
    connect (m_actZoomReset, &QAction::triggered, this, &TimeDomChart::zoomReset);

    //坐标轴
    m_customPlot->xAxis2->setVisible(true);
    m_customPlot->xAxis2->setTickLabels(false);
    m_customPlot->yAxis2->setVisible(true);
    m_customPlot->yAxis2->setTickLabels(false);
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:

    //    m_customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom |QCP::iSelectPlottables);
    m_customPlot->setInteractions(QCP::iRangeZoom |QCP::iSelectPlottables);
    //设置坐标轴自适应
    m_customPlot->rescaleAxes();
}


void TimeDomChart::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        rubberOrigin = event->pos();    //保存橡皮筋起点
        rubberBand->setGeometry(QRect(rubberOrigin, QSize()));
        rubberBand->show();     //橡皮筋显示
    }
    else if (event->button() == Qt::RightButton)
    {
        m_popMenu->clear();
        m_popMenu->addAction(m_actZoomReset);
        m_popMenu->exec(QCursor::pos());
        event->accept();
    }
}


void TimeDomChart::mouseMoveEvent(QMouseEvent *event)
{
    if(rubberBand->isVisible())
    {
        rubberBand->setGeometry(QRect(rubberOrigin, event->pos()).normalized());
    }
}

void TimeDomChart::mouseReleaseEvent(QMouseEvent *event)
{
    if((rubberBand->isVisible())&&(rubberOrigin != event->pos()))
    {
        const QRect zoomRect = rubberBand->geometry();  //获取橡皮筋矩形

        int xp1, yp1, xp2, yp2;
        zoomRect.getCoords(&xp1, &yp1, &xp2, &yp2);     //获取橡皮筋矩形坐标（像素单位）
        //重新计算xAxis,yAxis坐标
        double x1 = m_customPlot->xAxis->pixelToCoord(xp1);   //像素坐标至坐标转换
        double y1 = m_customPlot->yAxis->pixelToCoord(yp1);
        double x2 = m_customPlot->xAxis->pixelToCoord(xp2);
        double y2 = m_customPlot->yAxis->pixelToCoord(yp2);
        m_customPlot->xAxis->setRange(x1, x2);
        m_customPlot->yAxis->setRange(y1, y2);
    }
    rubberBand->hide();
    m_customPlot->replot();
}

void TimeDomChart::zoomReset()
{
    m_customPlot->rescaleAxes();
    m_customPlot->replot();
}

void TimeDomChart::getData(QVector<double> &vecDataX, QVector<QVector<double> > &vecDataY, int index) //
{
//    for (int i = 0; i < vecDataY.size(); i++)
//    {
//        plotCh[i]->setData(vecDataX, vecDataY.at(i));
//    }

    plotCh[0]->setData(vecDataX, vecDataY.at(index + 1));
    m_customPlot->rescaleAxes();
    m_customPlot->replot();
}

void TimeDomChart::getData(QVector<double> &vecDataX, QVector<double> &vecDataY)
{
    plotCh[0]->setData(vecDataX, vecDataY);
    m_customPlot->rescaleAxes();
    m_customPlot->replot();
}

void TimeDomChart::setChannelShow(bool bArrShow[])
{
    for (int i = 0; i < 3; i++)
    {
        if (bArrShow[i] == false)
        {
            plotCh[i]->setVisible(false);
            plotCh[i]->removeFromLegend();
        }
        else if(bArrShow[i] == true)
        {
            plotCh[i]->setVisible(true);
            plotCh[i]->addToLegend();
        }
    }
    m_customPlot->replot();
}
