#include "widget.h"
#include <QMouseEvent>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget{parent}
{}

void Widget::mousePressEvent(QMouseEvent* event){
    if ((event->buttons() & Qt::LeftButton))
    {
        if (centerPoints.size() == 2)
            return;
        QPoint p = event->pos();
        centerPoints.push_back(p);
        repaint();
    }
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pen(color, 5);
    ///QPen input(Qt::red, 5);
    painter.setPen(pen);


    /*int size1=firstDg/qSqrt(2);
    int half1=size1/2;
    int size2=secondDg/qSqrt(2);
    int half2= size2/2;
    QPoint a2(centerPoints[0].x()+half1, centerPoints[0].y()-half1 );
    QPoint a4(centerPoints[0].x()+half1, centerPoints[0].y()+half1 );
    QPoint b1(centerPoints[1].x()-half2, centerPoints[1].y()-half2 );
    QPoint b2(centerPoints[1].x()+half2, centerPoints[1].y()-half2 );
    //прямая б1б2*/




    if (centerPoints.size() >= 1 && firstDg > 0)
        painter.drawRect(centerPoints[0].x()-qSqrt(firstDg)/2, centerPoints[0].y()+qSqrt(firstDg)/2, firstDg/qSqrt(2),firstDg/qSqrt(2));
    if (centerPoints.size() == 2 && secondDg > 0)
        painter.drawRect(centerPoints[1].x()+qSqrt(secondDg)/2, centerPoints[1].y()-qSqrt(secondDg)/2, secondDg/qSqrt(2), secondDg/qSqrt(2));
   /* painter.setPen(input);
    for(int i=b1.x(); i<=b2.x(); ++i){
        if(i==a2.x()+((a4.x()-a2.x())*(b1.y()-a2.y())/(a4.y()-a2.y()))){
            painter.drawRect(i, b1.y(), b1.x()-i, b1.x()-i);
        }
    }*/




    //update();
}
