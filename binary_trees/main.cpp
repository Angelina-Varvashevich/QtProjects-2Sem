#include "nodebinarytree.h"
#include "painttree.h"
#include "arraytreepainter.h"

#include <QApplication>
#include <QScrollArea>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PaintTree w1;
    w1.resize(700, 500);
    w1.setWindowTitle("BST on nodes");
    w1.show();

    ArrayTreePainter w2;
    w2.resize(700, 500);
    w2.setWindowTitle("BST on array");
    w2.show();
    return a.exec();
}
