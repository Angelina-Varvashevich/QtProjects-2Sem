#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include "widget.h"

class MainWidget : public QWidget
{
    Q_OBJECT
protected slots:
   void onfirstDiagClicked();
   void onsecondDiagClicked();


public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    QLineEdit * firstDiag;
    QLineEdit * secondDiag;
    Widget widget;


};
#endif // MAINWIDGET_H
