#include "widget.h"
#include "dialog.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QtAlgorithms>
#include <QVBoxLayout>
#include <QInputDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QVBoxLayout* layout= new QVBoxLayout(this);
    studentsListWidget= new QListWidget(this);

    loadButton= new QPushButton("Load list from file", this);
    connect(loadButton, SIGNAL(clicked()), this, SLOT(onLoadButtonClicked()));
    averageAllButton= new QPushButton ("Sort by marks of all students", this);
    connect(averageAllButton, SIGNAL(clicked()), this, SLOT(onAverageAllButtonClicked()));
   // averageGroupButton= new QPushButton ("Sort by marks of students in groups", this);
   // connect(averageGroupButton, SIGNAL(clicked()), this, SLOT(onAverageAllButtonClicked()));
    goodStudentsButton= new QPushButton ("Show students with positive marks", this);
    connect(goodStudentsButton, SIGNAL(clicked()), this, SLOT(onGoodButtonClicked()));
    groupStudentsButton= new QPushButton("Student in group №...", this);
    connect(groupStudentsButton, SIGNAL(clicked()), this, SLOT(onStudentsGroupButtonClicked()));
    addStudentButton= new QPushButton("Add Student", this);
    connect(addStudentButton, SIGNAL(clicked()), this, SLOT(onAddStudentClicked()));

    surnameLabel=new QLabel("Find student by surname", this);
    surnameEdit=new QLineEdit(this);
    connect(surnameEdit, SIGNAL(returnPressed()), this, SLOT(onSurnameEditChanged())  );


    layout->addWidget(studentsListWidget);
    layout->addWidget(loadButton);
    layout->addWidget(addStudentButton);
    layout->addWidget(averageAllButton);
    //layout->addWidget(averageGroupButton);
    layout->addWidget(groupStudentsButton);
    layout->addWidget(goodStudentsButton);
    layout->addWidget(surnameLabel);
    layout->addWidget(surnameEdit);
    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onLoadButtonClicked()
{
    studentsListWidget->clear();
    fileName = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    QFile file(fileName);
    if(!file.open(QIODevice::Append| QIODevice::Text))
        return;

    QTextStream in (&file);
    while(!in.atEnd()){
        QString line= in.readLine();
        Student student;
        std::string parseString= line.toStdString();
        students.push_back( student.ParseString(parseString));
    }

    ShowStudentsList();

}

void Widget::ShowStudentsList()
{
    studentsListWidget->clear();
    for( auto& student : students)
    {
        studentsListWidget->addItem(string(student));
    }
}

void Widget::onAverageAllButtonClicked()
{
    std::sort(students.begin(), students.end(), []( Student& student1, Student& student2){
        return student1.CalculateAverageMark() > student2.CalculateAverageMark();
    } );
    ShowStudentsList();
}

void Widget::onAverageGroupButtonClicked()
{   SortAverageGroup();
    ShowStudentsList();

}

void Widget::SortAverageGroup(){
     studentsListWidget->clear();
    std::sort(students.begin(), students.end(), []( Student& student1, Student& student2){
        return (student1.GetGroupNumber()==student2.GetGroupNumber() &&
                student1.GetSpecialization()==student2.GetSpecialization())
                && (student1.CalculateAverageMark() > student2.CalculateAverageMark());
    });
}

QString Widget::string( Student student)
{
    return (" "+student.GetSpecialization()+ " || "+ QString::number(student.GetGroupNumber()) +" || "+ student.GetSurname()+"  Marks:  "+
            QString::number(student.GetMark(0))+ " "+ QString::number(student.GetMark(1))+ " " +  QString::number(student.GetMark(2))
            +" "+ QString::number(student.GetMark(3))+ "  ||  "+ QString::number(student.CalculateAverageMark()) );
}

void Widget::onGoodButtonClicked()
{
    studentsListWidget->clear();
    for( auto& student : students)
    {
        if (student.GetMark(0)>=4 && student.GetMark(1)>=4 && student.GetMark(2)>=4 && student.GetMark(3)>=4 ){
            studentsListWidget->addItem(string(student));
        }
    }
}

void Widget::onSurnameEditChanged()
{    for( auto& student : students)
    {
        if(surnameEdit->text()== student.GetSurname()){
            studentsListWidget->clear();
            studentsListWidget->addItem(string(student));
        }

    }
}

void Widget::onStudentsGroupButtonClicked()
{

    bool ok=true;
    int group;
    int i = QInputDialog::getInt(this, tr("QInputDialog"), tr(" Set group of students"), 1, 1, 15, 1, &ok);
    if (ok ){
        group =i;
    }
    studentsListWidget->clear();
    SortAverageGroup();
    for( auto& student : students)
    {
        if(group== student.GetGroupNumber()){
            studentsListWidget->addItem(string(student));
        }
    }
}

void Widget::onAddStudentClicked()
{
    Dialog *dialog = new Dialog(this);
    if (dialog->exec() != QDialog::Accepted)
        return;

    Student student = dialog->student();
    students.push_back(student);
    ShowStudentsList();

    QFile file(fileName);
    if (file.open(QIODevice::Append|QIODevice::Text)){

        QTextStream out(&file);
        out<<Qt::endl;
        out<<student.GetSpecialization()<< " ";
        out<<  QString::number(student.GetGroupNumber())<< " ";
        out<< student.GetSurname()<< " ";
        out<< QString::number(student.GetMark(0))<< " ";
        out<< QString::number(student.GetMark(1))<< " ";
        out<< QString::number(student.GetMark(2))<< " ";
        out<< QString::number(student.GetMark(3))<< " ";
    }
}




