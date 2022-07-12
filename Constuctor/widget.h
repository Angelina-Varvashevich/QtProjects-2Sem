#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include "panel.h"

class Widget : public QWidget
{
    Q_OBJECT
public:
     Widget(std::function<double(double)> func, QWidget *parent = nullptr);

    void setX1_w(double x1_){
        Panel->setX1(x1_);
        x1=x1_;
    }

    void setX2_w(double x2_){
        Panel->setX2(x2_);
        x2=x2_;
    }
    std::function<double(double)> func_ ;
protected slots:

    void onChangedEditX(){
        editY->setText(QString::number(Panel->/*function( editX->text().toDouble() )*/func_(editX->text().toDouble()) ) );
    }


private:

    double x1;
    double x2;
    panel* Panel;
    QLineEdit *editX;
    QLineEdit *editY;
    //std::function<double(double)> func_;

};

#endif // WIDGET_H
