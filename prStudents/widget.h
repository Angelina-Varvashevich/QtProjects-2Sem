#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QListWidget>
#include <QPushButton>
#include <list>

#include "student.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onLoadClicked();
    void onDeleteClicked();
    void onAddClicked();

private:
    // Данные, используемые окном вносите в класс окна
    std::list<Student> students;

   // QTextEdit * studentsTextEdit;
    QListWidget * studentsTextEdit;
    QPushButton * loadButton;
    QPushButton * addButton;
    QPushButton * deleteButton;

    void showStudents();

};
#endif // WIDGET_H
