#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "widget.h"

class MainWidget : public QWidget
{
    Q_OBJECT
protected slots:
   void onfirstDiagClicked();
   void onsecondDiagClicked();
   void onChangeColorClicked();


public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    QLineEdit * firstDiag;
    QLineEdit * secondDiag;
    QPushButton * btn;
    Widget widget;


};
#endif // MAINWIDGET_H
