#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QSlider>
#include <QVBoxLayout>

struct Point{
  QPoint point;
  QColor color;
  int widthPen;


};


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QColor color; //сделать сеттер

    Point *p;///сеттер и в приват


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
/*protected slots:
    void setPen();*/
public:
    //std::vector<QPoint> points;
    std::vector<QPoint> current_line;
    std::vector<std::vector<QPoint>> lines;
    std::vector<Point> pp;


};

#endif // WIDGET_H
