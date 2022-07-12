#ifndef NODEBINARYTREE_H
#define NODEBINARYTREE_H


#include <QPainter>
#include <QBrush>
#include <QPen>
#include <iostream>

template<typename T>
class Node {
public:
    explicit Node(T key) : Key(key) {

    }



    int Key;
    T Value;
    Node *Left = nullptr;
    Node *Right = nullptr;

};

template<typename T>
class NodeBinaryTree
{

public:
    void Paint(QPainter *paint);
    NodeBinaryTree() : Root(nullptr) {

    }

    ~NodeBinaryTree() {
        cleanse(Root);
    }

    void Insert(int key/**/, T value) {
        insert(key, value, Root);
    }

    void Prefix() {
        prefix(Root);
    }

    void Infix() {
        infix(Root);
    }

    void Postfix() {
        postfix(Root);
    }

    Node<T>* GetRoot(){
        return Root;
    }



private:
    Node<T> *Root;

    void insert(int key/**/, T value, Node<T> *&node);

    void cleanse(Node<T> *node);

    void prefix(Node<T> *current);

    void infix(Node<T> *current);

    void postfix(Node<T> *current);

    void postfix_draw_ellipse(Node<T> *current, int x, int y, int length, int width, QPainter* painter, int space);


};

template<typename T>
void NodeBinaryTree<T>::insert(int key/**/, T value, Node<T> *&node) {
    if (node == nullptr) {
        node = new Node<T>(key);
        node->Key = key;
        node->Value = value;
        node->Left = node->Right = nullptr;
        return;
    }
    if (key < node->Key) {
        insert(key, value, node->Left);
    } else { /// (key >= node->Key)
        insert(key, value, node->Right);
    }
}

template<typename T>
void NodeBinaryTree<T>::cleanse(Node<T> *node) {
    if (node == nullptr) return;
    cleanse(node->Left);
    cleanse(node->Right);
    delete node;
}

template<typename T>
void NodeBinaryTree<T>::prefix(Node<T> *current) {
    if (current == nullptr) return;
    std::cout << current->Key << " ";
    std::cout << std::endl;
    prefix(current->Left);
    std::cout << std::endl;
    prefix(current->Right);
}

template<typename T>
void NodeBinaryTree<T>::infix(Node<T> *current) {
    if (current == nullptr) return;
    infix(current->Left);
    std::cout << std::endl;
    std::cout << current->Key << " ";
    std::cout << std::endl;
    infix(current->Right);
}

template<typename T>
void NodeBinaryTree<T>::postfix(Node<T> *current) {
    if (current == nullptr) return;
    postfix(current->Left);
    postfix(current->Right);
    std::cout << std::endl;
    std::cout << current->Key << " ";
    std::cout << std::endl;
}

template<typename T>
void NodeBinaryTree<T>::Paint(QPainter* painter){
    int dx=700;
    //int dy= widgetRect.height();
    int margin =20; //отступы от границы
    int current_dy= margin;
    int space =125;
    int diametr =27;
    int centre = dx/2;

    postfix_draw_ellipse(Root, centre, current_dy, diametr, diametr, painter, space);
}

template<typename T>
void NodeBinaryTree<T>::postfix_draw_ellipse(Node<T> *current, int centre, int current_dy, int diametr, int diametr_, QPainter* painter, int space){
    QPen treePen(QColor(5,3,165), 1);
    treePen.setStyle(Qt::DashDotLine);
    QBrush treeBrush(Qt::yellow);
    painter->setBrush( treeBrush);
    painter->setPen( treePen);

    if (current == nullptr) return;
    if (current->Left!=nullptr) {
        painter->drawLine(centre+diametr/2, current_dy, centre+diametr/2-space, current_dy+space);
    }
    if(current->Right!=nullptr){
        painter->drawLine(centre+diametr, current_dy+diametr/2, centre+diametr+space, current_dy+diametr/2+space);
    }
    postfix_draw_ellipse(current->Left, (centre-space), current_dy+space,  diametr, diametr_, painter, space*0.7);
    postfix_draw_ellipse(current->Right,(centre+space), current_dy+space, diametr, diametr_, painter, space*0.7);
    painter->drawEllipse(centre, current_dy, diametr, diametr_);/// установить значения ключа
    painter->drawText(centre+diametr/2, current_dy+diametr/2, QString::number(current->Key));

}




#endif // NODEBINARYTREE_H
