#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout* layout= new QVBoxLayout(this);
    studentsListWidget= new QListWidget(this);

    showButton= new QPushButton("Shows items in museum", this);
    connect(showButton, SIGNAL(clicked()), this, SLOT(onShowButtonClicked()));

   loadButton= new QPushButton("Load items in museum", this);
   connect(loadButton, SIGNAL(clicked()), this, SLOT(onSaveButtonClicked()));
//    museum = new Museum();

    layout->addWidget(studentsListWidget);
    layout->addWidget(showButton);
    layout->addWidget(loadButton);
    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onShowButtonClicked()
{
   /* QString fileName = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    QFile file(fileName);
    if(!file.open(QIODevice::Append| QIODevice::Text))
        return;
        QTextStream out(&file);*/

    studentsListWidget->clear();
    for( auto item: museum.items)
    {
        QString itemString=QString::fromUtf8(item->Print().data(), int(item->Print().size()));
        studentsListWidget->addItem(itemString);
        /*out<<Qt::endl;
        out<<item->name<< " ";
        out<<  QString::number(item->year)<< " ";*/

    }
}


void Widget::onSaveButtonClicked(){
     QString fileName = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
     QFile file(fileName);
     if(!file.open(QIODevice::Append| QIODevice::Text))
         return;
     QTextStream out(&file);

     studentsListWidget->clear();
     for( auto item: museum.items)
     {

         out<<Qt::endl;
         out<<item->name<< " ";
         out<<  QString::number(item->year)<< " ";

     }
}



