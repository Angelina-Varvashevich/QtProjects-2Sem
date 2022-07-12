#include "widget.h"


Widget::Widget(std::function<double(double)> func, QWidget *parent)
    : QWidget{parent}
{
    func_=std::move(func);
    editX = new QLineEdit(this);
    connect(editX, SIGNAL(textChanged(const QString & )), SLOT(onChangedEditX()));
    editY = new QLineEdit(this);
    editY->setDisabled(true);
    QLabel* lblX =  new QLabel("x",this);

    QLabel* lblY = new QLabel("y",this);
    Panel= new panel( func_,this);////
    QVBoxLayout *Layout = new QVBoxLayout();
    Layout->addWidget(Panel);
    lblX->setFixedSize(50, 50);
    lblY->setFixedSize(50, 50);

    Layout->addWidget(lblX);
    Layout->addWidget(editX);
    Layout->addWidget(lblY);
    Layout->addWidget(editY);
    setLayout(Layout);
}
