#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected slots:
    void onLoadButtonClicked();
    void onAverageAllButtonClicked();
    void onAverageGroupButtonClicked();
    void onGoodButtonClicked();
    void onSurnameEditChanged();
    void onStudentsGroupButtonClicked();
    void onAddStudentClicked();


private:
    Ui::Widget *ui;
    QList<Student> students;
    QString fileName;
    QPushButton* loadButton;
    QPushButton* averageAllButton;
    QPushButton* averageGroupButton;
    QPushButton* goodStudentsButton;
    QPushButton* addStudentButton;
    QLabel* surnameLabel;
    QLineEdit* surnameEdit;
    QPushButton* groupStudentsButton;
    QListWidget * studentsListWidget;
    void ParseFileAndInitializeStudents();
    void ShowStudentsList();
    void SortAverageGroup();
    QString string( Student student);
};
#endif // WIDGET_H
