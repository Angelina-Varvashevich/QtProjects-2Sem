#ifndef PAINTTREE_H
#define PAINTTREE_H

#include <QWidget>
#include<QPainter>
#include<QScrollArea>
#include "nodebinarytree.h"
#include "arraybinarytree.h"
namespace Ui{
class PaintTree;
};

class PaintTree : public QWidget
{
    Q_OBJECT

public:

     PaintTree(QWidget *parent = nullptr);
    ~ PaintTree();

    void paintEvent(QPaintEvent *event){

        QPainter painter(this);
        tree->Paint(&painter);
    }
private:
    NodeBinaryTree<int>* tree;
    QScrollArea* ScrollArea;


};

#endif // PAINTTREE_H
