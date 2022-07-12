#include "widget.h"
#include "panel.h"
#include <QtMath>
#include <iostream>

#include <QApplication>

//double panel::function(double x){
    //return qSin(x);
    //return x*x+qSin(x);
    //return x*x-2;
    //return -x*x-2;
  //  return x*x+2;
//}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto func=[](double x){
        return qSin(x);//x*x+2;
        //return -x*x-2;
        //return x*x+2;
    };
    Widget w(func);
    w.setX1_w(-9.42);
    w.setX2_w(9.42);
    w.show();
    return a.exec();
}
