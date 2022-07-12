#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "drawingpanel.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

protected slots:
    void onClickedColorButton();

private:
    QPushButton*  btn;
    DrawingPanel * drawingPanel;
    QPushButton * colorButton;
     QPushButton * Start_End_Button;
     QLineEdit* editx;
     QLineEdit* edity;

};
#endif // MAINWIDGET_H
