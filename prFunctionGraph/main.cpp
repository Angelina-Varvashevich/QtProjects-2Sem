#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.resize(800, 700);
    w.setWindowTitle("Function Graph");
    w.show();
    return a.exec();
}
