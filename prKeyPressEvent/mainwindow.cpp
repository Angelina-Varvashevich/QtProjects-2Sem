#include <QStatusBar>
#include <QColorDialog>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    myWidget = new MyWidget(this);
    menu= new QMenu("&Menu");
    menu->addAction("&Change color",
                    myWidget/*this*/,
                    SLOT(onChangeColorClicked()),
                    Qt::Key_1
                    ) ;
    menu->addSeparator();

    menu->addAction("&Change step",
                    myWidget/*this*/,
                    SLOT(onChangeStepClicked()),
                    Qt::Key_2
                    ) ;
    menu->addSeparator();

    menu->addAction("&Change line font",
                    myWidget/*this*/,
                    SLOT(onFontSizeClicked()),
                    Qt::Key_3
                    ) ;
    menu->addSeparator();

    menu->addAction("&Clear drawing panell",
                    myWidget/*this*/,
                    SLOT(onClearFieldClicked()),
                    Qt::CTRL + Qt::Key_N
                    ) ;
    menu->addSeparator();

    menu->addAction("&Save drawing panell",
                    myWidget/*this*/,
                    SLOT(onSaveFieldClicked()),
                    Qt::CTRL + Qt::Key_S
                    ) ;
    menu->addSeparator();

    menu->addAction("&Change point of start drawing",
                    myWidget/*this*/,
                    SLOT(onChangePointClicked()),
                    Qt::CTRL + Qt::Key_W
                    ) ;
    menu->addSeparator();

    menu->addAction("&Load drawing panell",
                    myWidget/*this*/,
                    SLOT(onLoadClicked()),
                    Qt::CTRL + Qt::Key_V
                    ) ;
    menu->addSeparator();

    menuBar.addMenu(menu);

    myWidget->setFocus();
    this->setCentralWidget(myWidget);
    this->setMenuBar(&menuBar);
}

MainWindow::~MainWindow()
{}


