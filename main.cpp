#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>

class Piece {
    QLabel *p;
    private:
        bool killed = false;
        bool white  = false;

    Piece(bool white){
        this->white = white;
    }

    bool isKilled(){ return this->killed;}
    bool isWhite(){ return this->white;}
    bool setColor(bool white){ this->white = white;}
    bool setKilled(bool killed){ this->killed = killed;}
    void setPixmap(){ this->p->setPixmap(QPixmap());}
};

class Spot {
    Piece piece;
    private:
        int x;
        int y;

    Spot(int x, int y, Piece piece){
        this->setPiece(piece);
        this->setX(x);
        this->setY(y);
    }

    Piece getPiece(){ return this->piece;}
    int getX(){ return this->x;}
    int getY(){ return this->y;}
    void setX(int x){ this->x = x;}
    void setY(int y){ this->y = y;}
    void setPiece(Piece piece){ this->piece = piece;}
};

void drawBoard(QGraphicsScene* scene){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            QGraphicsRectItem* grid = new QGraphicsRectItem();

            grid->setRect(j*100,i*100,100,100);
            if ((i+j)%2){
                grid->setBrush(Qt::black);
            } else {
                grid->setBrush(Qt::white);
            }
            scene->addItem(grid);
        }
    }
    QLabel* piece = new QLabel();
    piece->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/bking.svg.png"));
    piece->move(600,600);
    scene->addWidget(piece);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QGraphicsScene* scene = new QGraphicsScene;

    drawBoard(scene);

    QPushButton* GenMovesButton = new QPushButton();
    GenMovesButton->setText("Generate Moves");
    GenMovesButton->move(800,0);
    scene->addWidget(GenMovesButton);

    QGraphicsView view(scene);
    view.show();

    return a.exec();
}
