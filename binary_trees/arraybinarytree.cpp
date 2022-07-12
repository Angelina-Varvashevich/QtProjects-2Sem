#include "arraybinarytree.h"

void ArrayBinaryTree::insert(int key, int value, int index) {
    resize_if_overflow(index);
    if (nodes_array[index].key == null_ && nodes_array[index].value == null_) {
        nodes_array[index].key = key;
        nodes_array[index].value = value;
        return;
    }
    if (key < nodes_array[index].key) {
        insert(key, value, 2 * index + 1);
    } else {
        insert(key, value, 2 * index + 2);
    }

}

void ArrayBinaryTree::prefix(int index) {
    if (nodes_array[index].key == null_ && nodes_array[index].value == null_) return;
    std::cout << nodes_array[index].key << " " << std::endl;
    std::cout << std::endl;
    prefix(2 * index + 1);
    prefix(2 * index + 2);
}

void ArrayBinaryTree::infix(int index) {
    if (nodes_array[index].key == null_ && nodes_array[index].value == null_) return;
    infix(2 * index + 1);
    std::cout << nodes_array[index].key << " " << std::endl;
    std::cout << std::endl;
    infix(2 * index + 2);
}

void ArrayBinaryTree::postfix(int index) {
    if (nodes_array[index].key == null_ && nodes_array[index].value == null_) return;
    postfix(2 * index + 1);
    postfix(2 * index + 2);
    std::cout << nodes_array[index].key << " " << std::endl;
    std::cout << std::endl;
}

void ArrayBinaryTree::resize_if_overflow(int index) {
    if (size <= 2 * index + 2) {
        array_node *new_nodes_array = new array_node[size * increase];
        int current_size=size;
        for (int i = 0; i < size; ++i) {
            new_nodes_array[i].key = nodes_array[i].key;
            new_nodes_array[i].value = nodes_array[i].value;
        }
        delete[] nodes_array;
        nodes_array = new_nodes_array;
        size *= increase;
        for (int i=current_size; i<size; ++i){
            new_nodes_array[i].key =null_;
            new_nodes_array[i].value = null_;
        }
    }
}

void ArrayBinaryTree::postfix_draw_ellipse(int index, int centre, int current_dy, int diametr, int diametr_, QPainter* painter, int space){// если 0, то -1
    QPen treePen(QColor(5,3,255), 1);
    treePen.setStyle(Qt::DotLine);
    QBrush treeBrush(Qt::gray);
    painter->setBrush( treeBrush);
    painter->setPen( treePen);

    if (nodes_array[index].key == null_) return;
    if (nodes_array[2*index+1].key!=null_) {
        painter->drawLine(centre+diametr/2, current_dy, centre+diametr/2-space, current_dy+space);
    }
    if(nodes_array[2*index+2].key!=null_){
        painter->drawLine(centre+diametr, current_dy+diametr/2, centre+diametr+space, current_dy+diametr/2+space);
    }
    postfix_draw_ellipse(2*index+1, (centre-space), current_dy+space,  diametr, diametr_, painter, 0.7*space);
    postfix_draw_ellipse(2*index+2,(centre+space), current_dy+space, diametr, diametr_, painter, 0.7*space );
    painter->drawEllipse(centre, current_dy, diametr, diametr_);
    painter->drawText(centre+diametr/2, current_dy+diametr/2, QString::number(nodes_array[index].key));

}

void ArrayBinaryTree::Paint(QPainter* painter){
    int dx=700;
    int margin =20; //отступы от границы
    int current_dy= margin;
    int space =125;
    int diametr =27;
    int centre = dx/2;
    postfix_draw_ellipse(0, centre, current_dy, diametr, diametr, painter, space);
}

