#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>


void drawBoard(QGraphicsScene* scene){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            QGraphicsRectItem* grid = new QGraphicsRectItem();
            grid->setRect(j*100,i*100,100,100);
            if ((i+j)%2){
                grid->setBrush(Qt::white);
            } else {
                grid->setBrush(Qt::black);
            }
            scene->addItem(grid);
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QGraphicsScene* scene = new QGraphicsScene;
    drawBoard(scene);

    QGraphicsView view(scene);
    view.show();
    return a.exec();
}
