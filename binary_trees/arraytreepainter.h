#ifndef ARRAYTREEPAINTER_H
#define ARRAYTREEPAINTER_H

#include <QWidget>
#include <QPainter>
#include "arraybinarytree.h"

class ArrayTreePainter : public QWidget
{
    Q_OBJECT
public:
    explicit ArrayTreePainter(QWidget *parent = nullptr);
    ~ArrayTreePainter();
    void paintEvent(QPaintEvent *event){

        QPainter painter(this);
        tree->Paint(&painter);
    }
private:
    ArrayBinaryTree* tree;

};

#endif // ARRAYTREEPAINTER_H
