#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
public:
    explicit Widget(QWidget *parent = nullptr);
    int firstDg=0;
    int secondDg=0;
    QColor color= Qt::green;
protected:
    void mousePressEvent(QMouseEvent* event) override;
   // void mouseMoveEvent(QMouseEvent *event) override;
    //void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;


signals:
private:
    QVector <QPoint> centerPoints;
    //QPoint firstCenter;
    //QPoint secondCenter;
};

#endif // WIDGET_H
