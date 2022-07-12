#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QLineEdit>

class panel : public QWidget
{
    Q_OBJECT

public:
    panel(std::function<double(double)> func, QWidget *parent = nullptr);
    ~panel();

    void setX1(double x1_){
        x1=x1_;
        parametersCalculate();
    }

    double getX1(){
        return x1;
    }

    void setX2(double x2_){
        x2=x2_;
        parametersCalculate();
    }

    double getX2(){
        return x2;
    }
std::function<double(double)> func_;
    //double function(double x);

protected:

    void paintEvent(QPaintEvent * event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    double w;
    double h;
    double x1;
    double x2;
    double X1;
    double X2;
    double y_max;
    double y_min;
    double current_length_y;
    double spaceX;
    double spaceY;

    void parametersCalculate();



};
#endif // PANEL_H
