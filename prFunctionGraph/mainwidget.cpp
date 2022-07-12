#include "mainwidget.h"

#include <QVBoxLayout>
#include <QColorDialog>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
  drawingPanel = new DrawingPanel(this);
  colorButton = new QPushButton("Change Color", this);
  connect(colorButton, SIGNAL(clicked()), SLOT(onClickedColorButton()));
  startStopButton=new QPushButton("Start Timer", this);
  connect(startStopButton, SIGNAL(clicked()), SLOT(onClickedStartStopButton()));

  QVBoxLayout *mainLayout = new QVBoxLayout();
  mainLayout->addWidget(drawingPanel);
  mainLayout->addWidget(colorButton);
  mainLayout->addWidget(startStopButton);


  setLayout(mainLayout);
}

MainWidget::~MainWidget()
{
}

void MainWidget::onClickedColorButton()
{
    QColor color =QColorDialog::getColor(Qt::darkYellow, this);
    //drawingPanel->setColor(QColor(rand()%256, rand()%256, rand()%256));
    drawingPanel->setColor(color);
    drawingPanel->update();
}

void MainWidget::onClickedStartStopButton(){
    if (drawingPanel->startWatch== false){
        startStopButton->setText("End Timer");
        drawingPanel->getTimer()->start(20);
        drawingPanel->startWatch= true;
    }
    else{
   startStopButton->setText("Start Timer");
   drawingPanel->getTimer()->stop();
   drawingPanel->startWatch= false;
}
}
