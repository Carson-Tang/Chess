#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>

class Piece {
    QLabel *p;
    private:
        bool killed;
        bool white;

    public:
        Piece(bool white_ = false, bool killed_ = false) {
            this->setColor(white_);
            this->setKilled(killed_);
        }

    bool isKilled(){ return this->killed;}
    bool isWhite(){ return this->white;}
    void setColor(bool white_){ this->white = white_;}
    void setKilled(bool killed_){ this->killed = killed_;}
    void setPixmap(){ this->p->setPixmap(QPixmap());}
};


class King: public Piece {
    private:
        bool alreadyCastled;

    public:
        King(bool white, bool alreadyCastled_ = false) {
            this->setColor(white);
            this->setCastled(alreadyCastled_);
        }

    bool hasCastled(){ return this->alreadyCastled;}
    void setCastled(bool alreadyCastled_){ this->alreadyCastled = alreadyCastled_;}
};


class Queen: public Piece {
    public:
        Queen(bool white) {
            this->setColor(white);
        }
};


class Rook: public Piece {
    public:
        Rook(bool white) {
            this->setColor(white);
        }
};


class Bishop: public Piece {
    public:
        Bishop(bool white) {
            this->setColor(white);
        }
};


class Knight: public Piece {
    public:
        Knight(bool white) {
            this->setColor(white);
        }
};


class Pawn: public Piece {
    public:
        Pawn(bool white) {
            this->setColor(white);
        }
};


class Spot {
    Piece piece;
    private:
        int x;
        int y;

    public:
        Spot(int x_, int y_, Piece piece_): piece(piece_) {
            this->setPiece(piece_);
            this->setX(x_);
            this->setY(y_);
        }

    Piece getPiece(){ return this->piece;}
    int getX(){ return this->x;}
    int getY(){ return this->y;}
    void setX(int x_){ this->x = x_;}
    void setY(int y_){ this->y = y_;}
    void setPiece(Piece piece_){ this->piece = piece_;}
};

class Board {
    private:
        static Spot board[8][8];

    public:
        Board() {
            this->resetBoard();
        }
    void resetBoard(){
        // Black Rooks
        this->board[0][0] = Spot(0, 0, Rook(false));
        this->board[0][7] = Spot(0, 7, Rook(false));
        // White Rooks
        this->board[7][0] = Spot(7, 0, Rook(true));
        this->board[7][7] = Spot(7, 7, Rook(true));
        // Black Knights
        this->board[0][1] = Spot(0, 1, Knight(false));
        this->board[0][6] = Spot(0, 6, Knight(false));
        // White Knights
        this->board[7][1] = Spot(7, 1, Knight(true));
        this->board[7][6] = Spot(7, 6, Knight(true));
        // Black Bishops
        this->board[0][2] = Spot(0, 2, Bishop(false));
        this->board[0][5] = Spot(0, 5, Bishop(false));
        // White Bishops
        this->board[7][2] = Spot(7, 2, Bishop(true));
        this->board[7][5] = Spot(7, 5, Bishop(true));
        // Black Queen
        this->board[0][3] = Spot(0, 3, Queen(false));
        // White Queen
        this->board[7][3] = Spot(7, 3, Queen(false));
        // Black King
        this->board[0][4] = Spot(0, 4, King(false));
        // White King
        this->board[7][4] = Spot(7, 4, King(true));
        for(int i = 0; i < 8; i++){
            // Black Pawns
            this->board[1][i] = Spot(1, i, Pawn(false));
            // White Pawns
            this->board[6][i] = Spot(6, i, Pawn(false));
        }
    }
    Spot getSpot(int x, int y){ return this->board[x][y];}
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


int main(int argc, char *argv[]){
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
