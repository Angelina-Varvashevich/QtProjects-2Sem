#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include"item.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected slots:
    void onShowButtonClicked();
    void onSaveButtonClicked();

private:
    Ui::Widget *ui;
    Museum museum;
    QListWidget * studentsListWidget;
    QPushButton* showButton;
    QPushButton* loadButton;

};
#endif // WIDGET_H
