#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QLineEdit>
class Student;

// http://qt-doc.ru/sozdanie-sobstvennogo-dialogovogo-okna.html
class AddDialog : public QDialog
{
public:
    AddDialog(QWidget * parent = nullptr);
    Student student() const;

private:
    QLineEdit * nameLineEdit;
    QLineEdit * yearLineEdit;
};

#endif // ADDDIALOG_H
