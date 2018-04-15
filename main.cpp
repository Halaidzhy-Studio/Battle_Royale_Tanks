#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "GameMenu/gamemenu.h"
#include "mainwindow.h"
//#include "playwidget.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameMenu gamemenu;

    gamemenu.show();
    return a.exec();
}
