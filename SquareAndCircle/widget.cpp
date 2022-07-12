#include "widget.h"
#include <QPainter>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget{parent}
{
    //currentI=centerPoint.x()-radius;
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
}

void Widget::slotTimerAlarm()
{
    ++currentI;
    update();
}




void Widget::mousePressEvent(QMouseEvent* event){


    if ((event->buttons() & Qt::LeftButton))
    {
         centerPoint = event->pos();
         currentI=centerPoint.x()-radius;
        repaint();
    }

}

void Widget::paintEvent(QPaintEvent *event) {

    QPainter painter(this);
    QPen penCircle(color, 5);
    QColor cl= Qt::blue;
    QPen penSquare(cl, 1);
    painter.setPen(penCircle);
    painter.drawEllipse(centerPoint.x()-radius, centerPoint.y()-radius, 2*radius, 2*radius);
    painter.setPen(penSquare);
    QPoint x1(centerPoint.x()-radius, centerPoint.y());
    QPoint x2(centerPoint.x()+radius, centerPoint.y());
    if (currentI>=x1.x()&& currentI<x2.x() ){
        int yi= centerPoint.y()+ qSqrt(radius*radius-(currentI-centerPoint.y())*(currentI-centerPoint.y()));
        int yi_= centerPoint.y()- qSqrt(radius*radius-(currentI-centerPoint.y())*(currentI-centerPoint.y()));
      painter.drawRect(currentI+5, yi-2.5, 10, 10) ;
       painter.drawRect(currentI+5, yi_-2.5, 10, 10) ;
    }
    else  {
        currentI=x1.x();
        int yi= centerPoint.y()+ qSqrt(radius*radius-(currentI-centerPoint.y())*(currentI-centerPoint.y()));
      painter.drawRect(currentI+5, yi-2.5, 10, 10) ;

    }
}
