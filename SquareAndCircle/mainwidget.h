#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include "widget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    protected slots:
    void onRadiusLineeditClicked();
private:
    Widget widget;
    QLineEdit* radiusLineEdit ;
    QPushButton *btn;

};
#endif // MAINWIDGET_H
