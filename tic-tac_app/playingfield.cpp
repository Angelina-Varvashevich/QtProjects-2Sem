#include "playingfield.h"
#include "ui_playingfield.h"
#include <QDebug>
#include <QLabel>

PlayingField::PlayingField(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlayingField)

{
    gameStart=true;
    yourTurn==true;
    ui->setupUi(this);
    ui->label_2->setVisible(false);//спрятали надпись о итогах игры
    timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onComputerMoveClicked()));

    CreateGrid();
    StartRestartGame();
    buttonsLocationOnField();
    //CheckGame();


}

PlayingField::~PlayingField()
{
    delete ui;
}

void PlayingField:: CreateGrid(){

    ui->textEdit->setVisible(false);
    startButton= new QPushButton("New Game", this);
    startButton->resize(100,50);
    startButton->move(5, 5);

    startButton->setStyleSheet("background-color: white");
    connect(startButton, SIGNAL(clicked()), this, SLOT(onStartButtonClicked()));
    gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(0);

    const QSize button_size=QSize(100,100);
    for (int rw=0; rw<3; ++rw){
        for (int cl=0; cl<3; ++cl){
            QPushButton *button =new QPushButton();
            button->setFixedSize(button_size);
            gridLayout->addWidget(button, rw, cl);
        }
    }
    setLayout(gridLayout);
}

void PlayingField::ChangeButtonType(int rw, int cl, int type ){
    QPushButton *btn= qobject_cast<QPushButton*>(gridLayout->itemAtPosition(rw, cl)->widget());
    if (type== 1) CreateCross(btn);
    if (type==0) CreateNull(btn);

}

void PlayingField::onStartButtonClicked()
{
    StartRestartGame();
}

void PlayingField::onButtonsFieldClicked()
{

    QPushButton *btn= qobject_cast<QPushButton*>(sender());
    int rw= btn->property("row").toInt() ;
    int cl=btn->property("column").toInt() ;
    if ( GameField[rw][cl]==-11 && yourTurn== true && gameStart==true  ){
        GameField[rw][cl]=1;
        ChangeButtonType(rw, cl, 1);
        yourTurn=false;
        ++moveOfGame;

        CheckGame();
        if(gameStart==true){
            computerMove();
            ++moveOfGame;
            CheckGame();

        }
    }
}

void PlayingField::StartRestartGame()
{

    ui->textEdit->setVisible(false);
    for (int rw=0; rw<3; ++rw){
        for (int cl=0; cl<3; ++cl){
            GameField[rw][cl]= -11;
            QPushButton *btn= qobject_cast<QPushButton*>(gridLayout->itemAtPosition(rw, cl)->widget());
            btn->setStyleSheet(defaultButtonStyle());
        }
    }
    gameStart = true;
    moveOfGame=0;
    yourTurn=true;

}

void PlayingField::buttonsLocationOnField()
{

    for (int rw=0; rw<3; ++rw){
        for (int cl=0; cl<3; ++cl){
            QPushButton *btn= qobject_cast<QPushButton*>(gridLayout->itemAtPosition(rw, cl)->widget());
            btn->setProperty("row", rw);
            btn->setProperty("column", cl);
            connect(btn, SIGNAL(clicked()), this, SLOT(onButtonsFieldClicked()));
        }
    }
    CheckGame();


}

void PlayingField::onComputerMoveClicked()
{
    int rw=rand()%3;
    int cl=rand()%3;
    while(GameField[rw][cl]!=-11){
        rw= rand()%3;
        cl= rand()%3;}
    GameField[rw][cl]=0;
    ChangeButtonType(rw, cl, 0);
    yourTurn=true;
    timer->stop();
}

void PlayingField::computerMove(){
    timer->start(3000);


}

void PlayingField::CheckGame()
{
    QString win="You are winner!!!!!!!!";
    QString lose="Machine won you...";

    if(GameField[0][0]==GameField[1][0] && GameField[1][0]==GameField[2][0]){
        if (GameField[0][0]==1){
            ui->textEdit->setText(win);
            ui->textEdit->setVisible(true);
            yourTurn= false;
            gameStart= false;}
        if (GameField[0][0]==0) {ui->textEdit->setText(lose);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
    }
    else if (GameField[0][1]==GameField[1][1] && GameField[1][1]==GameField[2][1]){
        if (GameField[0][1]==1){ui->textEdit->setText(win);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
        if (GameField[0][1]==0) { ui->textEdit->setText(lose);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
    }
    else if(GameField[0][2]==GameField[1][2] && GameField[1][2]==GameField[2][2]){
        if (GameField[0][2]==1){ui->textEdit->setText(win);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
        if (GameField[0][2]==0) { ui->textEdit->setText(lose);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
    }


    else if (GameField[0][0]==GameField[0][1]&& GameField[0][1]==GameField[0][2]){
        if (GameField[0][0]==1){ui->textEdit->setText(win);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
        if (GameField[0][0]==0){ui->textEdit->setText(lose);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
    }
    else if (GameField[1][0]==GameField[1][1] && GameField[1][1] ==GameField[1][2]){
        if (GameField[1][0]==1){ui->textEdit->setText(win);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
        if (GameField[1][0]==0) { ui->textEdit->setText(lose);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
    }
    else if (GameField[2][0]==GameField[2][1] && GameField[2][1] ==GameField[2][2]){
        if (GameField[2][0]==1){ui->textEdit->setText(win);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
        if (GameField[2][0]==0) {ui->textEdit->setText(lose);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
    }

    else if (GameField[0][0]==GameField[1][1] && GameField[1][1]==GameField[2][2]){
        if (GameField[0][0]==1){ui->textEdit->setText(win);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
        if (GameField[0][0]==0) {ui->textEdit->setText(lose);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
    }
    else if (GameField[0][2]==GameField[1][1]&& GameField[1][1]==GameField[2][0]){
        if (GameField[0][2]==1){ ui->textEdit->setText(win);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
        if (GameField[0][2]==0) {ui->textEdit->setText(lose);
            ui->textEdit->setVisible(true);
            yourTurn=false;
            gameStart= false;}
    }

    if (moveOfGame==9) { ui->textEdit->setText("Friendship Won!!!!!");
        ui->textEdit->setVisible(true);
        yourTurn=false;
        gameStart= false;}

}


