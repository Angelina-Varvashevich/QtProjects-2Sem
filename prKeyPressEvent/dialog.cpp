#include "dialog.h"
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

Dialog::Dialog(QWidget* parent) : QDialog(parent){
    xLineEdit = new QLineEdit(this);
    yLineEdit = new QLineEdit(this);

    QLabel * xLabel = new QLabel("&X");
    QLabel * yLabel = new QLabel("&Y");



    xLabel->setBuddy(xLineEdit);
    yLabel->setBuddy(yLineEdit);


    QPushButton *okButton = new QPushButton("&Ok");
    QPushButton *cancelButton = new QPushButton("&Cancel");

    connect(okButton, SIGNAL(clicked()), SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()), SLOT(reject()));

    // Layout setup
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(xLabel, 0, 0);
    layout->addWidget(yLabel, 1, 0);

    layout->addWidget(xLineEdit, 0, 1);
    layout->addWidget(yLineEdit, 1, 1);

    layout->addWidget(okButton, 2, 0);
    layout->addWidget(cancelButton, 2, 1);
    setLayout(layout);
}

QPoint Dialog::point() const
{
    int x=xLineEdit->text().toInt();
    int y=yLineEdit->text().toInt();
    return QPoint(x, y);

}

