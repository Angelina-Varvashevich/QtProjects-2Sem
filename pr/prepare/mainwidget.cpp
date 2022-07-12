#include "mainwidget.h"
#include <QColorDialog>

void MainWidget::onfirstDiagClicked()
{
  widget.firstDg=firstDiag->text().toDouble();
  //repaint();
   update();
}

void MainWidget::onsecondDiagClicked()
{
  widget.secondDg=secondDiag->text().toDouble();
  //repaint();
  update();
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
  btn = new QPushButton("Change Color", this);
  connect (btn, SIGNAL(clicked()), this, SLOT(onChangeColorClicked()));

  layout->addWidget(&widget);
  layout->addWidget(label1);
  layout->addWidget(firstDiag);
  layout->addWidget(label2);
  layout->addWidget(secondDiag);
  layout->addWidget(btn);
  layout->setStretch(0, 10);
  layout->setStretch(1, 1);
  layout->setStretch(2, 1);
  layout->setStretch(3, 1);
  layout->setStretch(4,1);
  setLayout(layout);
}

void MainWidget::onChangeColorClicked()
{
    QColor Color =QColorDialog::getColor(Qt::darkYellow, this);
    widget.color= Color;
    update();
}

MainWidget::~MainWidget()
{
}

