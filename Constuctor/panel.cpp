#include "panel.h"
#include <QtMath>
#include <QToolTip>

void panel::parametersCalculate()
{
   w = 500;
   h = 600;
   spaceX=w/(x2-x1);
   X1=spaceX*x1;
   X2=spaceX*x2;
   y_min= /*function(x1)*/ func_(x1);/////////////////
   y_max=y_min;
   for (double i=x1; i<=x2; i=i+0.5){
       double current_yi=/*function(i)*/ func_(i);/////////////////////////
       if (current_yi> y_max) y_max=current_yi;
       if (current_yi< y_min) y_min=current_yi;
   }

   current_length_y=0;
   if (y_max>=0 &&y_min>=0 ){
     current_length_y= y_max;
   }

   if (y_max<0 &&y_min<0){current_length_y= qFabs(y_min);}
   if (y_max>=0 &&y_min<=0){
     current_length_y= y_max-y_min;
   }

   spaceY=h/current_length_y;
}

panel::panel(std::function<double(double)> func, QWidget *parent)
    : QWidget(parent)
{
    func_=std::move(func);
     parametersCalculate();
}

panel::~panel()
{
}

void panel::paintEvent(QPaintEvent * event)
{
    w=width()-30;
    h =height()-30;
    QPainter painter(this);
    QPen pen(Qt::green, 5);
    QPen linePen(Qt::black, 1);

    painter.setPen(linePen);
    if (y_max>=0 &&y_min>=0 ){
       painter.translate(QPoint(w/2,h));
       painter.drawLine(-w/2,0, w/2, 0 );
       painter.drawLine(0, -h, 0,0);
    }
    else if (y_max<0 &&y_min<0) {
        painter.translate(QPoint(w/2,10));
        painter.drawLine(-w/2,0, w/2, 0 );
        painter.drawLine(0, 0, 0,h);
        for(int i=x1; i<= x2; ++i){
            painter.drawLine(spaceX*i, -3, spaceX*i, 3);
            painter.drawText(spaceX*i, 15, QString::number(i));
        }
    }
    else{
       painter.translate(QPoint(w/2,h/2));
       painter.drawLine(0,-h/2, 0,h/2+15 );
       painter.drawLine(-w/2, 0, w/2,0);
    }

    for(int i=x1; i<= x2; ++i){
    painter.drawLine(spaceX*i, -3, spaceX*i, 3);
    painter.drawText(spaceX*i, 15, QString::number(i));
    }

    for (int i=-current_length_y; i<=current_length_y; ++i){
    painter.drawLine(-3, spaceY*i, 3, spaceY*i);
    if (i !=0)painter.drawText(-20, -spaceY*i, QString::number(i));
    }

    painter.setPen(pen);
    for (double i= X1; i <= X2; i++) {
    QPointF coord;
    coord.rx() = i;
    double real_x=i/spaceX;
    coord.ry() = spaceY*(-1)*/*function(real_x)*/func_(real_x);/////////////////////////////////////
    painter.drawPoint(QPointF(coord.rx(), coord.ry()));
   }

}

void panel::mousePressEvent(QMouseEvent *event)
{
}

void panel::mouseMoveEvent(QMouseEvent *event)
{
}

void panel::mouseReleaseEvent(QMouseEvent *event)
{
  double y;
  double x;
  double spacex=-spaceX;;

   if (y_max>0&& y_min<0){
     y= -(event->y()/spaceY-current_length_y/2);
     x= (w/2-event->x())/spacex;
   }
   else if  (y_max>=0&& y_min>=0){
     y= ( (event->y()-15)/-spaceY+current_length_y);
     x= (w/2-event->x())/spacex;
    }
   else{
      y=(event->y()-10)/-spaceY;
     x= (w/2-event->x())/spacex;
   }

   if (/*function(x)*/ func_(x)<=y+0.5 && /*function(x)*/func_(x)>=y-0.5 )///////////////////////////////
       QToolTip::showText(event->pos(), "x: " + QString::number(x) + " ; " + "y: " + QString::number(y), this);

}

