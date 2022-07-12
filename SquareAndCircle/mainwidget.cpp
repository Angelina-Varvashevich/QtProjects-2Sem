#include "mainwidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QLabel * radiusLabel = new QLabel("Choose radius", this);
    radiusLineEdit= new QLineEdit("", this);
    connect(radiusLineEdit, SIGNAL(textChanged(const QString & )), this, SLOT(onRadiusLineeditClicked()));
    QVBoxLayout * layout= new QVBoxLayout();
    layout->addWidget(&widget);
    layout-> addWidget(radiusLabel);
    layout->addWidget(radiusLineEdit);
    layout->setStretch(0, 10);
    layout->setStretch(1, 1);
    layout->setStretch(2, 1);
    setLayout(layout);



}

MainWidget::~MainWidget()
{
}

void MainWidget::onRadiusLineeditClicked()
{
    widget.timer->start(100);
 widget.radius= radiusLineEdit->text().toInt();
 repaint();
}

