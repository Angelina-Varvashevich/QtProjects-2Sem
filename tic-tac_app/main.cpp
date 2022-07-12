#include "playingfield.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlayingField w;
    w.show();
    return a.exec();
}
