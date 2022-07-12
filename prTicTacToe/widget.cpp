#include <QGridLayout>
#include <QMessageBox>
#include "widget.h"
#include "mybutton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout * layout = new QGridLayout();

    for (int i = 0; i< size * size; ++i)
    {
        buttons[i] = new MyButton();
        layout->addWidget(buttons[i], i / size, i % size);
        connect(buttons[i], SIGNAL(clicked()), SLOT(onClickedButton()));
    }

    this->setLayout(layout);
}

Widget::~Widget()
{
}

void Widget::onClickedButton()
{
//    QMessageBox msgBox;
//    msgBox.setText("Clicked!!!");
//    msgBox.exec();

    // Источник сигнала???
    MyButton * source = (MyButton *)QObject::sender();

    if ( source->getValue() == 0) source->setValue(1);
    else source->setValue(0);
}


