#include "widget.h"
#include <QMouseEvent>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget{parent}
{
for (int i=0; i<2; ++i){
    centerPoints[i].rx()=0;
    centerPoints[i].ry()=0;
}

}

void Widget::mousePressEvent(QMouseEvent* event){
    if ((event->buttons() & Qt::LeftButton))
    {
        QPoint p;
        p = event->pos();
        centerPoints.push_back(p);
        update();
    }
}
/////////////////////////////////////////
void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pen(color, 5);
     painter.setPen(pen);
    if (centerPoints[0].rx()==0 && centerPoints[0].ry()==0 && firstDg==0 && centerPoints[1].rx()==0 && centerPoints[1].ry()==0 && secondDg==0){

    }
    else if  (centerPoints[0].rx()==0 && centerPoints[0].ry()==0 && firstDg==0){
         painter. drawRect(centerPoints[1].rx()-secondDg, centerPoints[1].ry()+secondDg, centerPoints[1].ry()+secondDg, centerPoints[1].ry()-secondDg);
    }
    else if (centerPoints[1].rx()==0 && centerPoints[1].ry()==0 && secondDg==0){
        painter. drawRect(centerPoints[0].rx()-firstDg, centerPoints[0].ry()+firstDg, centerPoints[0].ry()+firstDg, centerPoints[0].ry()-firstDg);
   }
    else {
         painter. drawRect(centerPoints[0].rx()-firstDg, centerPoints[0].ry()+firstDg, centerPoints[0].ry()+firstDg, centerPoints[0].ry()-firstDg);
         painter. drawRect(centerPoints[1].rx()-secondDg, centerPoints[1].ry()+secondDg, centerPoints[1].ry()+secondDg, centerPoints[1].ry()-secondDg);
    }
}
