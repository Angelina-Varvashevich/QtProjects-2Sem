#include "arraytreepainter.h"

ArrayTreePainter::ArrayTreePainter(QWidget *parent)
    : QWidget{parent}
{
tree= new ArrayBinaryTree ();
tree->Insert(10,1);
tree->Insert(8, 1);
tree->Insert(12, 1);
tree->Insert(11, 1);
tree->Insert(-13,1);
tree->Insert(9, 1);
tree->Insert(15,1);
tree->Insert(20,1);
tree->Insert(17,1);
tree->Insert(16, 1);
tree->Insert(18,1);
tree->Insert(-16,1);
tree->Insert(-20,1);
tree->Insert(-3,1);
tree->Insert(-5,1);
tree->Insert(-2,1);
}

ArrayTreePainter::~ArrayTreePainter(){

}


