#include "mainwidget.h"
#include <QLineEdit>
#include <QLabel>

#include <QVBoxLayout>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
  drawingPanel = new DrawingPanel(this);
  colorButton = new QPushButton("Change Color", this);
  Start_End_Button = new QPushButton("Start Timer", this);///
  btn = new QPushButton("set f", this);
  connect(colorButton, SIGNAL(clicked()), SLOT(onClickedColorButton()));
  connect(Start_End_Button, SIGNAL(clicked()), SLOT(onClickedColorButton()));////
  connect(btn, SIGNAL(clicked()), SLOT(onClickedColorButton()));
  editx= new QLineEdit(this);///setfixsize
  edity= new QLineEdit(this);
  QLabel *lblx= new QLabel(this);
  QLabel *lbly= new QLabel(this);
  QVBoxLayout *mainLayout = new QVBoxLayout();
  mainLayout->addWidget(drawingPanel);
  mainLayout->addWidget(colorButton);
  mainLayout->addWidget(Start_End_Button);///
  mainLayout->addWidget(editx);///
 mainLayout->addWidget(edity);///


  setLayout(mainLayout);  /////edity->setText(editx->setText); связываем кнопки+ чистить едит, set redoanly, setdisabled(не редактировать)
}

MainWidget::~MainWidget()
{
}

void MainWidget::onClickedColorButton()
{
    drawingPanel->setColor(QColor(rand()%256, rand()%256, rand()%256));
    drawingPanel->update();
}

