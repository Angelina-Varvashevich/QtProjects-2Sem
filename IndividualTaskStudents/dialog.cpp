#include "dialog.h"

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

#include "student.h"

Dialog::Dialog(QWidget* parent) : QDialog(parent)
{
    specializationLineEdit = new QLineEdit(this);
    groupLineEdit = new QLineEdit(this);
    srnmLineEdit = new QLineEdit(this);
    mark1LineEdit= new QLineEdit(this);
    mark2LineEdit= new QLineEdit(this);
    mark3LineEdit= new QLineEdit(this);
    mark4LineEdit= new QLineEdit(this);

    QLabel *specializationLabel = new QLabel("&specialization");
    QLabel *groupLabel = new QLabel("&group");
    QLabel *srnmLabel = new QLabel("&surname");
    QLabel * mark1Label = new QLabel("&first mark");
    QLabel * mark2Label = new QLabel("&second mark");
    QLabel * mark3Label = new QLabel("&third mark");
    QLabel * mark4Label = new QLabel("&fourth mark");


    specializationLabel->setBuddy(specializationLineEdit);
    groupLabel->setBuddy(groupLineEdit);
    srnmLabel->setBuddy(srnmLineEdit);
    mark1Label->setBuddy(mark1LineEdit);
    mark2Label->setBuddy(mark2LineEdit);
    mark3Label->setBuddy(mark3LineEdit);
    mark4Label->setBuddy(mark4LineEdit);

    QPushButton *okButton = new QPushButton("&Ok");
    QPushButton *cancelButton = new QPushButton("&Cancel");

    connect(okButton, SIGNAL(clicked()), SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()), SLOT(reject()));

    // Layout setup
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(specializationLabel, 0, 0);
    layout->addWidget(groupLabel, 1, 0);
    layout->addWidget(srnmLabel, 2, 0);
    layout->addWidget(mark1Label, 3, 0);
    layout->addWidget(mark2Label, 4, 0);
    layout->addWidget(mark3Label, 5, 0);
    layout->addWidget(mark4Label, 6, 0);

    layout->addWidget(specializationLineEdit, 0, 1);
    layout->addWidget(groupLineEdit, 1, 1);
    layout->addWidget(srnmLineEdit, 2, 1);
    layout->addWidget(mark1LineEdit, 3, 1);
    layout->addWidget(mark2LineEdit, 4, 1);
    layout->addWidget(mark3LineEdit, 5, 1);
    layout->addWidget(mark4LineEdit, 6, 1);

    layout->addWidget(okButton, 7, 0);
    layout->addWidget(cancelButton, 7, 1);
    setLayout(layout);
}


Student Dialog::student() const
{
    QString spec = specializationLineEdit->text();
    QString srnm = srnmLineEdit->text();
    int group = groupLineEdit->text().toInt();
    double m1= mark1LineEdit->text().toDouble();
    double m2= mark2LineEdit->text().toDouble();
    double m3= mark3LineEdit->text().toDouble();
    double m4= mark4LineEdit->text().toDouble();
    QVector<double> mrk;
    mrk.push_back(m1);  mrk.push_back(m2);  mrk.push_back(m3);  mrk.push_back(m4);
    return Student(spec, group, srnm, mrk);
}


