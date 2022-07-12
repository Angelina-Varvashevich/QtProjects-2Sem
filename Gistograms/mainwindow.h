#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
MainWindow(QWidget *parent = nullptr);
~MainWindow();
protected:
void paintEvent(QPaintEvent *event);
private:
std::vector<int> data{10, 20, 30};
private:
    Ui::MainWindow *ui;
};

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
for (int i = 0; i < 10; ++i)
data.push_back(rand() % 100 + 1);
}
MainWindow::~MainWindow() {}
void MainWindow::paintEvent(QPaintEvent *event) {
Q_UNUSED(event);
QRect widgetRect = this->rect();
QPainter painter(this);
QPen pen(Qt::blue, 2.5);
QBrush brush(Qt::gray);
painter.setPen(pen);
painter.setBrush(brush);
int max = *(std::max_element(data.begin(), data.end()));
int dx = widgetRect.width() / max;
int dy = widgetRect.height() / data.size();
for (int i=0; i<data.size(); ++i)
{
painter.drawRect(0, i * dy, data[i] * dx, dy);
QString str = QString::number(data[i]);
painter.drawText(20, i * dy + dy / 2, str);
}
}
#endif // MAINWINDOW_H
