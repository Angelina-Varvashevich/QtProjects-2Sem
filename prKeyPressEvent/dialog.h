#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
class MyWidget;

class Dialog : public QDialog
{
public:
    Dialog(QWidget* parent = nullptr);
    QPoint point() const;

private:
    QLineEdit * xLineEdit;
    QLineEdit * yLineEdit;

};

#endif // DIALOG_H
