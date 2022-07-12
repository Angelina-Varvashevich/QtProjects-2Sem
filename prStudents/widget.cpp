#include <QVBoxLayout>
#include <QFileDialog>

#include "widget.h"
#include "adddialog.h"
#include <QListWidget>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //studentsTextEdit = new QTextEdit(this);
    studentsTextEdit = new QListWidget(this);

    loadButton = new QPushButton("load from file", this);
    connect(loadButton, SIGNAL(clicked()), SLOT(onLoadClicked()));

    deleteButton=new QPushButton("Delete student", this);
    connect(deleteButton, SIGNAL(clicked()), SLOT(onDeleteClicked()));

    addButton = new QPushButton("add new student", this);
    connect(addButton, SIGNAL(clicked()), SLOT(onAddClicked()));

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget(studentsTextEdit);
    layout->addWidget(loadButton);
    layout->addWidget(addButton);
    layout->addWidget(deleteButton);

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

void Widget::onDeleteClicked()
{
    int index= studentsTextEdit->currentRow();
    if (index != -1 || students.size()> index){
  studentsTextEdit->takeItem(index);
  auto it= students.begin();
  for (int number=0; number<index;++number ){
      it++;
  }
  students.erase(it);
  QMessageBox msgBox;
  msgBox.setText(QString::number(index));
  msgBox.exec();
    }

}



void Widget::showStudents()
{
    studentsTextEdit->clear();
    for(const auto& student : students)
    {
        QString qStr(student.to_string().c_str());
        studentsTextEdit->addItem(qStr);
    }


}



