#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    QColor color= Qt::green;
    int radius;
    QTimer *timer;

protected slots:
    void slotTimerAlarm();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    // void mouseMoveEvent(QMouseEvent *event) override;
    //void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

signals:
private:
    /*int getCurrentI(){
        return  centerPoint.x()-radius;
    }

    void setCurrentI(int value){
        currentI= value;
    }*/
    QPoint centerPoint;

    int currentI;



};

#endif // WIDGET_H
