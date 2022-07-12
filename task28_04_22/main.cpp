#include "gistogram.h"

#include <QApplication>
#include <fstream>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gistogram w;
    w.resize(380,250);
    w.setWindowTitle("gistogram");
    w.show();
    return a.exec();
}
