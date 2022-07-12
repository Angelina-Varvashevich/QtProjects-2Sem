#include "painttree.h"



PaintTree::PaintTree(QWidget *parent)
    : QWidget{parent}
{

   /* ScrollArea = new QScrollArea(this);
    ScrollArea = new QScrollArea(this);
    ScrollArea->setGeometry(0, 0, width(), height());
    ScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ScrollArea->setBackgroundRole(QPalette::Light);
    //ScrollArea->hide();
    ScrollArea->setWidgetResizable(true);
    //ScrollArea->setWidget(this);*/
 tree= new NodeBinaryTree<int> ();
 /*tree->Insert(10,1);
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
 tree->Insert(-2,1);*/
 tree->Insert(20,1);
 tree->Insert(4, 1);
 tree->Insert(35,1);
 tree->Insert(9, 1);
 //tree->Insert(10,1);
 //tree->Insert(8, 1);

}

PaintTree::~PaintTree(){

}



