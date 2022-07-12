#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <widget.h>
#include <QKeyEvent>
#include <QSlider>
#include <QPushButton>
#include <QColorDialog>


class mainwidget : public QWidget
{
    Q_OBJECT
public:
    explicit mainwidget(QWidget *parent = nullptr);
protected:
  ///////void keyPressEvent(QKeyEvent* key_);
protected slots:
    void setPen();
    void onClickedColorButton();
private:
    Widget* widget_;
    QSlider * slider;
    QPushButton * colorButton;
};

#endif // MAINWIDGET_H
