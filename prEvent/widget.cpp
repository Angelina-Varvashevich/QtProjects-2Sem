#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{
}

void Widget::mousePressEvent(QMouseEvent *event)
{


}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton))
    {
        QPoint point = event->pos();
        points.push_back(point);
        update();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{}

void Widget::paintEvent(QPaintEvent *event)
{
    /*QPainter painter(this);
    for (QPoint& point : points)
    {
        painter.drawEllipse(point.x(), point.y(), 10, 10);
    }*/

    QPainter painter(this);
    if (points.empty()) return;
    for (int i=0; i < points.size(); ++i)
    {
        painter.drawLine(points[i], points[i+1]);
       // painter.drawEllipse(point.x(), point.y(), 10, 10);
    }

}


