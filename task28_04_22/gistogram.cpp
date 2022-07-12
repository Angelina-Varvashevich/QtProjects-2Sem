#include "gistogram.h"
#include "ui_gistogram.h"
#include "cmath"
#include <fstream>
#include <iostream>

Gistogram::Gistogram(QWidget *parent): QWidget (parent){
    std::string value;
    std::ifstream fin("D:\\QT projects\\task28_04_22\\filelist.txt");
    if(fin.is_open()){


    while (getline(fin, value)){
         int vl= std::stoi(value);
         data.push_back(vl);}
    }
    else {
        std::cout << "File not found";
    }
}

Gistogram::~Gistogram()
{
    delete ui;
}

void Gistogram::paintEvent(QPaintEvent *event) {
Q_UNUSED(event);

QRect widgetRect = this->rect();
QPainter painter(this);
QPen pen(Qt::black, 2);
QBrush brush(Qt::yellow);

painter.setPen(pen);
painter.setBrush(brush);

int max = *(std::max_element(data.begin(), data.end()));
int min= *(std::min_element(data.begin(), data.end()));
if (abs(min)>max) max=abs(min);
int dx = (widgetRect.width()) / data.size();//ширина
int dy = (widgetRect.height()/2) / max;//единица высоты

for (int i=0; i<data.size(); ++i){
    if (data[i]<0){
painter.drawRect(i*dx,  -dy*abs(data[i])+max*dy, dx, dy*abs(data[i]) );
QString str = QString::number(data[i]);
painter.drawText(dx*i+ dx/2, dy*max/2, str);
    }
  else{
        painter.drawRect(i*dx,max*dy, dx, dy*abs(data[i]) );
        QString str = QString::number(data[i]);
        painter.drawText(dx*i+ dx/2, dy*abs(data[i])/2+max*dy, str);
    }
  }
}


