#ifndef GISTOGRAM_H
#define GISTOGRAM_H

#include <QWidget>
#include <QPainter>


QT_BEGIN_NAMESPACE
namespace Ui { class Gistogram; }
QT_END_NAMESPACE

class Gistogram : public QWidget
{
    Q_OBJECT

public:
    Gistogram(QWidget *parent = nullptr);
    ~Gistogram();

protected:
    void paintEvent(QPaintEvent *parent );

private:
   std::vector<int> data;

private:
    Ui::Gistogram *ui;
};



#endif // GISTOGRAM_H
