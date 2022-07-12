#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <list>
#include <QListWidget>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>

#include "student.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onLoadClicked();
    void onAddClicked();
    void onDeleteClicked();
    void onStudentChanged();

private:
    // Данные, используемые окном, вносите в класс окна
    std::list<Student> students;

    //QTextEdit * studentsTextEdit;
    QListWidget * studentsListWidget;
    QPushButton * loadButton;
    QPushButton * addButton;
    QPushButton * deleteButton;
    QLabel* courseLabel;
    QLineEdit* courseEdit;

    void showStudents();

};
#endif // WIDGET_H
