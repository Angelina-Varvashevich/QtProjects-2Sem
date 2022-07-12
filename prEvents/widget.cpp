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
        p->point = event->pos();
        current_line.push_back(p->point);
       /// pp.push_back(Point());
        update();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
    {
        lines.push_back(current_line);
        current_line.clear();
    }
}



void Widget::paintEvent(QPaintEvent *event)
{
    /*QPainter painter(this);
        QPen pen(color, widthPen);
    painter.setPen(pen);
    for (QPoint& point : points)
    {
        painter.drawEllipse(point.x(), point.y(), 10, 10);
    }*/

    QPainter painter(this);
    QPen pen(p->color, p->widthPen);
    painter.setPen(pen);
    QPen curr_pen(Qt::black, 1);

    if (lines.empty() && current_line.empty())
        return;


    for (auto& line : lines)
    {
        for (int i = 0; i < static_cast<int>(line.size())-1; i++)
        {
            painter.drawLine(line[i], line[i + 1]);
        }
    }


     for (int i = 0; i < static_cast<int>(current_line.size())-1; i++)
    {
        painter.drawLine(current_line[i], current_line[i + 1]);

    }

}
