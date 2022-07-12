#include "mainwidget.h"

void MainWidget::onfirstDiagClicked()
{
    widget.firstDg=firstDiag->text().toDouble();
   // update();
}

void MainWidget::onsecondDiagClicked()
{
    widget.secondDg=secondDiag->text().toDouble();
    //update();
}

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{

    QVBoxLayout *layout= new QVBoxLayout(this);
    QLabel *label1= new QLabel("Diagonal of the first square", this);

    firstDiag= new QLineEdit("", this);
    connect (firstDiag, SIGNAL(textChanged(const QString & )), this, SLOT(onfirstDiagClicked()));
    QLabel *label2= new QLabel("Diagonal of the second square", this);
    secondDiag=new QLineEdit("", this);
    connect (secondDiag, SIGNAL(textChanged(const QString & )), this, SLOT(onsecondDiagClicked()));

    layout->addWidget(&widget);
    layout->addWidget(label1);
    layout->addWidget( firstDiag);
    layout->addWidget(label2);
    layout->addWidget( secondDiag);
    setLayout(layout);
}

MainWidget::~MainWidget()
{
}

