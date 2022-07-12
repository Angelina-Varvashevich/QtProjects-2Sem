#ifndef DIALOG_H
#define DIALOG_H


#include <QDialog>
#include <QLineEdit>
class Student;

class Dialog : public QDialog
{
public:
    Dialog(QWidget* parent = nullptr);
    Student student() const;

private:
    QLineEdit * specializationLineEdit;
    QLineEdit * groupLineEdit;
    QLineEdit * srnmLineEdit;
    QLineEdit * mark1LineEdit;
    QLineEdit * mark2LineEdit;
    QLineEdit * mark3LineEdit;
    QLineEdit * mark4LineEdit;
};

#endif // DIALOG_H
