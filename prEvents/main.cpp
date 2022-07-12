#include "widget.h"
#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Widget w;
    mainwidget w;
    w.show();
    w.resize(1000, 600);
    w.setWindowTitle("Paint");

    return a.exec();
}
