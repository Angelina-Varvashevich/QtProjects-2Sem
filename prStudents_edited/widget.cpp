#include <QVBoxLayout>
#include <QFileDialog>

#include "widget.h"
#include "adddialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //studentsTextEdit = new QTextEdit(this);
    studentsListWidget = new QListWidget(this);

    connect(studentsListWidget, SIGNAL(itemSelectionChanged()), SLOT(onStudentChanged()));

    loadButton = new QPushButton("load from file", this);
    connect(loadButton, SIGNAL(clicked()), SLOT(onLoadClicked()));

    addButton = new QPushButton("add new student", this);
    connect(addButton, SIGNAL(clicked()), SLOT(onAddClicked()));

    deleteButton = new QPushButton("delete student", this);
    connect(deleteButton, SIGNAL(clicked()), SLOT(onDeleteClicked()));

    courseLabel = new QLabel("course", this);
    courseEdit = new QLineEdit(this);

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget(studentsListWidget);
    layout->addWidget(loadButton);
    layout->addWidget(addButton);
    layout->addWidget(deleteButton);
    layout->addWidget(courseLabel);
    layout->addWidget(courseEdit);

    this->setLayout(layout);

}

Widget::~Widget()
{
}

void Widget::onLoadClicked()
{
    QString qStr = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    readFromFile(students, qStr.toStdString());
    showStudents();
}

void Widget::onAddClicked()
{
  AddDialog *addDialog = new AddDialog(this);
  if (addDialog->exec() == QDialog::Accepted)
  {
    Student tmp = addDialog->student();
    students.push_back(tmp);
    showStudents();
  }
}

//void Widget::showStudents()
//{
//    studentsTextEdit->clear();
//    for(const auto& student : students)
//    {
//        QString qStr(student.to_string().c_str());
//        studentsTextEdit->append(qStr);
//    }
//}

void Widget::showStudents()
{
    studentsListWidget->clear();
    for(const auto& student : students)
    {
        QString qStr(student.to_string().c_str());
        studentsListWidget->addItem(qStr);
    }
}





void Widget::onDeleteClicked()
{
    int index = studentsListWidget->currentRow();

    if(index!=-1){


        QMessageBox msgBox;
        msgBox.setText(QString::number(index));
        msgBox.exec();

        studentsListWidget->takeItem(index);

    auto iter = students.begin();
    for(int i = 0; i<index; i++){
        iter++;
    }
    students.erase(iter);
}
}


void Widget::onStudentChanged(){

    int index = studentsListWidget->currentRow();

    auto iter = students.begin();
    for(int i = 0; i<index; i++){
        iter++;
    }

    courseEdit->setText(QString::number(iter->get_year_of_study()));
}
