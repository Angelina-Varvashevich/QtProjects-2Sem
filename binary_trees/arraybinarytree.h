#ifndef ARRAYBINARYTREE_H
#define ARRAYBINARYTREE_H


#include <iostream>
#include <QPainter>
#include <QBrush>
#include <QPen>

class array_node {
public:
    int key;
    int value;
};

class ArrayBinaryTree {
public:
    void Paint(QPainter *paint);
    ArrayBinaryTree() {
        for (int i = 0; i < size; ++i) {
            nodes_array[i].key = null_;
            nodes_array[i].value = null_;
        }
    }

    ~ArrayBinaryTree() {
        delete[] nodes_array;
    }

    ArrayBinaryTree(const ArrayBinaryTree &copy_tree) {
        for (int i = 0; i < size; ++i) {
            this->nodes_array[i].key = copy_tree.nodes_array[i].key;
            this->nodes_array[i].value = copy_tree.nodes_array[i].value;
        }
    }

    void Insert(int key, int value) {
        insert(key, value, 0);
    }

    void Tree_in_array() {
        for (int i = 0; i < size; ++i) {
            std::cout << nodes_array[i].key << " ";
        }
    }

    void Prefix() {
        prefix(0);
    }

    void Infix() {
        infix(0);
    }

    void Postfix() {
        postfix(0);
    }


private:
    int size = 2;

    const int null_ = 11111111111;

    const int increase = 3;

    array_node *nodes_array = new array_node[size];

    void insert(int key, int value, int index);

    void prefix(int index);

    void infix(int index);

    void postfix(int index);

    void resize_if_overflow(int index);

    void postfix_draw_ellipse(int index, int x, int y, int length, int width, QPainter* painter, int space);



};

#endif // ARRAYBINARYTREE_H
