#include "drawingpanel.h"

#include <QPainter>

DrawingPanel::DrawingPanel(QWidget *parent)
    : QWidget{parent}
{
    color = Qt::blue;
    currentI = -width()/2;

    /* Инициализируем Таймер и подключим его к слоту,
     * который будет обрабатывать timeout() таймера
     * */
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));

    ///timer->start(20); // И запустим таймер

}

// Лекция_5_ОСНОВЫ РИСОВАНИЯ
void DrawingPanel::paintEvent(QPaintEvent *)
{
  int w = width();  // Ширина и высота окна
  int h = height();
  int margin = 20; // Отступ от края окна

  QPainter painter(this);
  QPen pen(color, 3);
  QPen currentPen(Qt::red, 3);

  QPoint originOfCoordinates(w / 2 + margin, h / 2+ margin);  // Определяем новое начало координат
  painter.translate(originOfCoordinates); // Перемещаем начало координат
  for (int i=-w/2; i <= w / 2; i++) {

      QPointF coord;
      coord.rx() = i;
      coord.ry() = (-1) * coord.rx() * coord.rx() * 0.01;


      if (i == currentI ) {
          painter.setPen(currentPen);
          painter.drawEllipse(coord.rx()-5, coord.ry()-5, 10, 10);
      } else {
          painter.setPen(pen);
          painter.drawPoint(QPointF(coord.rx(), coord.ry()));
      }
      if (currentI>=w/2){
          currentI= -w/2;
      i=currentI;}

  }
}

void DrawingPanel::slotTimerAlarm()
{
    ++currentI;
    update();
}
