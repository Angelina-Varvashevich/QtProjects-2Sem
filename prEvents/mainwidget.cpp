#include "mainwidget.h"

mainwidget::mainwidget(QWidget *parent)
    : QWidget{parent}
{
       widget_ = new Widget();
       widget_->color = Qt::blue;
       slider= new QSlider(Qt::Vertical);
       slider->setRange(1, 15);
       slider->setPageStep(1);
       slider->setValue(5);
       widget_->p->widthPen= slider->value();
       slider->setTickPosition(QSlider::TicksAbove);
       slider->setTickInterval(1);
       colorButton = new QPushButton("Change Color", this);
       colorButton->resize(150,30);
       colorButton->move(50,0);

       connect(colorButton, SIGNAL(clicked()), SLOT(onClickedColorButton()));
       connect(slider, SIGNAL(valueChanged(int)/* setTracking(false))*/),this, SLOT(setPen()));


       QHBoxLayout* layout = new QHBoxLayout;
       layout->addWidget(slider);
       layout->addWidget(widget_);
       setLayout(layout);
}

void mainwidget::setPen(){
    widget_->p->widthPen= slider->value();
}

void mainwidget::onClickedColorButton()
{
    QColor color =QColorDialog::getColor(Qt::darkYellow, this);
    //drawingPanel->setColor(QColor(rand()%256, rand()%256, rand()%256));
    widget_->p->color= color;
    widget_->update();
}
