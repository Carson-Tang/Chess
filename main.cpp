#include "mainwindow.h"
#include "board.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QGraphicsScene* scene = new QGraphicsScene();
    QPushButton* genMovesButton = new QPushButton();

    Board board = Board(scene, genMovesButton);
    //board.clearBoard();
    //board.drawBoard();
    //board.resetBoard();

    QGraphicsView view(scene);
    view.show();

    return a.exec();
}
