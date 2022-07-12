#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "drawingpanel.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

protected slots:
    void onClickedColorButton();
    void onClickedStartStopButton();

private:
    DrawingPanel * drawingPanel;
    QPushButton * colorButton;
    QPushButton * startStopButton;

};
#endif // MAINWIDGET_H
