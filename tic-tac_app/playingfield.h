#ifndef PLAYINGFIELD_H
#define PLAYINGFIELD_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QPainterPath>
#include <QVector>
#include <QTimer>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class PlayingField; }
QT_END_NAMESPACE

class PlayingField : public QWidget
{
    Q_OBJECT

public:

    PlayingField(QWidget *parent = nullptr);

    ~PlayingField();

    void CreateGrid();

    QGridLayout *gridLayout;

protected:

    int GameField[3][3] = {
        {-11, -11, -11},
        {-11, -11, -11},
        {-11, -11, -11}
    };

    void ChangeButtonType(int rw, int cl, int type );

protected slots:

    void onStartButtonClicked();

    void onButtonsFieldClicked();


    void onComputerMoveClicked();

private:

    void CreateCross(QPushButton *btn){
        btn->setStyleSheet("border-image: url(:image/cross.png) stretch");
    };
    void CreateNull(QPushButton *btn){
        btn->setStyleSheet("border-image: url(:image/null.png) stretch");
    }

    int  player = 1; // по умолчанию пользователь крестик

    bool gameStart= false;

    int moveOfGame=0;

    Ui::PlayingField *ui;

    QString defaultButtonStyle() ///поменять цвет
    {
        return "QPushButton{"
                "  border:none;"
                "  background: #272D39;"
                "}"
                "QPushButton::hover{"
                "  background: #373D49;"
                "}";
    }


    void StartRestartGame();

    void buttonsLocationOnField();

    QPushButton* startButton;

    void computerMove();

    QTimer *timer;

    void CheckGame();

    bool yourTurn = true;

};
#endif // PLAYINGFIELD_H
