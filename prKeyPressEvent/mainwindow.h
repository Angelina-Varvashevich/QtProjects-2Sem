#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mywidget.h"
#include <QMenuBar>
#include <QMenu>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QMenuBar menuBar;
    QMenu *menu;
    MyWidget * myWidget;


};
#endif // MAINWINDOW_H
