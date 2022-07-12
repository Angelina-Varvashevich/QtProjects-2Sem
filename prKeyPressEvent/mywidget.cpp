#include <QPainter>
#include <QKeyEvent>
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include "mywidget.h"
#include "dialog.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget{parent}//,
    //str{"Hello"},
    //fontSize{20}
{

    center.rx()=100;
    center.ry()=100;
    //points.push_back(center);
    currentLine.push_back(center);
}

void MyWidget::onChangeColorClicked()
{
    QColor Color =QColorDialog::getColor(Qt::darkYellow, this);
    color= Color;
    update();
}

void MyWidget::onChangeStepClicked()
{
    bool ok= true;
    int i = QInputDialog::getInt(this, tr("QInputDialog"), tr("Step size:"), 7, 1, 50, 1, &ok);
    if (ok){
        delta=i;
    }
    update();

}

void MyWidget::onFontSizeClicked()
{
    bool ok=true;
    int i = QInputDialog::getInt(this, tr("QInputDialog"), tr(" Set font:"), 1, 1, 50, 1, &ok);
    if (ok){
        widthLine=i;
    }
    update();
}

void MyWidget::onClearFieldClicked()
{
   // points.clear();
    currentLine.clear();
    lines.clear();
    update();
}

void MyWidget::onSaveFieldClicked()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save as"), "untitled.png",
                                                    tr("Images(*.png * .xpm * .jpg"));
    int name_end_position = filename.lastIndexOf('.');
    ++name_end_position;
    int name_length = filename.length() - name_end_position;
    QString format = filename.right(name_length);
    QPixmap imageForSave = QWidget::grab(QRect(0, 20, width(), height() - 20));
    imageForSave.save(filename, format.toUpper().toUtf8());
    //points.clear();
    currentLine.clear();
    lines.clear();
    update();
}

void MyWidget::onChangePointClicked()
{
    Dialog *dialog = new Dialog(this);
    if (dialog->exec() == QDialog::Accepted)
    {
        center = dialog->point();
        currentLine.clear();
        currentLine.push_back(center);
        //points.push_back(center);

        update();

    }
}

void MyWidget::onLoadClicked()////циклит картинку
{
 QString fileName= QFileDialog::getOpenFileName(this, tr("Open file"), QDir::currentPath());
 if (!fileName.isEmpty()){
     QImage image(fileName);
     image= image.scaled(size() );
     if (image.isNull()){
         QMessageBox::information(this, tr("Open file"), tr("Can not load %1.").arg(fileName));
         return;
     }
     brush= new QBrush;
     palette= new QPalette;
     brush->setTextureImage( image);
     palette->setBrush(QPalette::Window, *brush);
     this->setAutoFillBackground(true);
     this->setPalette(*palette);
 }

}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen(color, widthLine);
    painter.setPen(pen);

   /* for (int i=1; i<= (int)points.size()-1; ++i){
        painter.drawLine(points[i-1], points[i] );

    }*/


        for (auto& line : lines)
    {
        for (int i = 1; i <= (int)(line.size())-1; i++)
        {
            painter.drawLine(line[i-1], line[i]);
        }
    }
     for (int i = 1; i <= (int) (currentLine.size())-1; i++)
    {
        painter.drawLine(currentLine[i-1], currentLine[i]);

    }
}

void MyWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    /*case Qt::Key_Plus:
        ++fontSize;
        update();
        break;
    case Qt::Key_Minus:
        --fontSize;
        update();
        break;*/


    case Qt::Key_Left:{
        if (center.rx()<=1.5*delta){
            center.rx()=2*delta;
        }
        center.rx()-=delta;
        //points.push_back(center);
        currentLine.push_back(center);
        lines.push_back(currentLine);
        update();
        break;
    }
    case Qt::Key_Right:{
        if (center.rx()>=width()-delta){
            center.rx()=width()-2*delta;
        }
        center.rx()+=delta;
        //points.push_back(center);
        currentLine.push_back(center);
        lines.push_back(currentLine);
        update();
        break;
    }
    case Qt::Key_Down: {
        if (center.ry()>=height()-delta){
            center.ry()=height()-2*delta;
        }
        center.ry()+=delta;
        ///points.push_back(center);
        currentLine.push_back(center);
        lines.push_back(currentLine);
        update();
        break;
    }
    case Qt::Key_Up:{
        if (center.ry()<=1.5*delta){
            center.ry()=2*delta;
        }
        center.ry()-=delta;
        //points.push_back(center);
        currentLine.push_back(center);
        lines.push_back(currentLine);
        update();
        break;
    }
    }
}


