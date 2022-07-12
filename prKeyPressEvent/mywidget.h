#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QColorDialog>
#include <QMenuBar>
#include <QMenu>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    QColor color= Qt::blue;

signals:
protected slots:
    void  onChangeColorClicked();
    void onChangeStepClicked();
    void onFontSizeClicked();
    void onClearFieldClicked();
    void onSaveFieldClicked();
    void onChangePointClicked();
    void onLoadClicked();

protected:
    void paintEvent(QPaintEvent *) override;
    void keyPressEvent(QKeyEvent *) override;

private:
    //QString str;
    //int fontSize;
    int delta=3;
    QPoint center;
    //QVector<QPoint> points;
    QVector<QPoint> currentLine;
    QVector<QVector<QPoint>> lines;

    int widthLine=3;
    QBrush* brush;
    QPalette* palette;
};

#endif // MYWIDGET_H
