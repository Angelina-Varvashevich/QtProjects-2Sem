#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(350, 280);
    w.setWindowTitle("Gistogram");
    w.show();
    return a.exec();
}
