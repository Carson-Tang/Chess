#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>

class Piece {
    QLabel *piece;
    private:
        bool killed;
        bool white;

    public:
        Piece(bool white_ = false, bool killed_ = false, QLabel *piece_ = new QLabel()) {
            this->setColor(white_);
            this->setKilled(killed_);
            this->piece = piece_;
            this->piece->setStyleSheet("QLabel{ background-color: transparent;}");
        }
    QLabel* getPiece(){ return this->piece;}
    bool isKilled(){ return this->killed;}
    bool isWhite(){ return this->white;}
    void setColor(bool white_){ this->white = white_;}
    void setKilled(bool killed_){ this->killed = killed_;}
    void setImage(char type){
        if(this->isWhite()){
            switch (type){
                case 'K': this->piece->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/king.png")); break;
                case 'Q': this->piece->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/queen.png")); break;
                case 'R': this->piece->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/rook.png")); break;
                case 'B': this->piece->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/bishop.png")); break;
                case 'N': this->piece->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/knight.png")); break;
                case 'P': this->piece->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/pawn.png")); break;
            }
        } else {
            switch (type){
                case 'K': this->piece->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/bking.png")); break;
                case 'Q': this->piece->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/bqueen.png")); break;
                case 'R': this->piece->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/brook.png")); break;
                case 'B': this->piece->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/bbishop1.png")); break;
                case 'N': this->piece->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/bknight.png")); break;
                case 'P': this->piece->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/bpawn.png")); break;
            }
        }
    }
};


class King: public Piece {
    private:
        bool alreadyCastled;

    public:
        King(bool white, bool alreadyCastled_ = false) {
            this->setColor(white);
            this->setCastled(alreadyCastled_);
            this->setImage('K');
        }

    bool hasCastled(){ return this->alreadyCastled;}
    void setCastled(bool alreadyCastled_){ this->alreadyCastled = alreadyCastled_;}
};


class Queen: public Piece {
    public:
        Queen(bool white) {
            this->setColor(white);
            this->setImage('Q');
        }
};


class Rook: public Piece {
    public:
        Rook(bool white) {
            this->setColor(white);
            this->setImage('R');
        }
};


class Bishop: public Piece {
    public:
        Bishop(bool white) {
            this->setColor(white);
            this->setImage('B');
        }
};


class Knight: public Piece {
    public:
        Knight(bool white) {
            this->setColor(white);
            this->setImage('N');
        }
};


class Pawn: public Piece {
    public:
        Pawn(bool white) {
            this->setColor(white);
            this->setImage('P');
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
            this->setPosition(x_, y_);
        }

    Piece getPiece(){ return this->piece;}
    int getX(){ return this->x;}
    int getY(){ return this->y;}
    void setX(int x_){ this->x = x_;}
    void setY(int y_){ this->y = y_;}
    void setPiece(Piece piece_){ this->piece = piece_;}
    void setPosition(int x_, int y_){ this->piece.getPiece()->move(y_*100+5, x_*100);}
};

class Board {
    private:
        QGraphicsScene* scene;
        QPushButton* genMovesButton;
        Spot board[8][8];

    public:
        Board(QGraphicsScene* scene_, QPushButton* genMovesButton_) : board{
            {Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL)},
            {Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL)},
            {Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL)},
            {Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL)},
            {Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL)},
            {Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL)},
            {Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL)},
            {Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL), Spot(0,0,NULL), Spot(0,0, NULL)},
        } {
            this->scene = scene_;
            this->genMovesButton = genMovesButton_;
            this->initButton();
            this->clearBoard();
            this->resetBoard();
        }

    void clearBoard(){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                this->board[i][j] = Spot(0, 0, NULL);
            }
        }
    }
    void resetBoard(){
        // Black Rooks
        this->board[0][0] = Spot(0, 0, Rook(false));
        this->board[0][7] = Spot(0, 7, Rook(false));
        this->scene->addWidget(this->board[0][0].getPiece().getPiece());
        this->scene->addWidget(this->board[0][7].getPiece().getPiece());
        // White Rooks
        this->board[7][0] = Spot(7, 0, Rook(true));
        this->board[7][7] = Spot(7, 7, Rook(true));
        this->scene->addWidget(this->board[7][0].getPiece().getPiece());
        this->scene->addWidget(this->board[7][7].getPiece().getPiece());
        // Black Knights
        this->board[0][1] = Spot(0, 1, Knight(false));
        this->board[0][6] = Spot(0, 6, Knight(false));
        this->scene->addWidget(this->board[0][1].getPiece().getPiece());
        this->scene->addWidget(this->board[0][6].getPiece().getPiece());
        // White Knights
        this->board[7][1] = Spot(7, 1, Knight(true));
        this->board[7][6] = Spot(7, 6, Knight(true));
        this->scene->addWidget(this->board[7][1].getPiece().getPiece());
        this->scene->addWidget(this->board[7][6].getPiece().getPiece());
        // Black Bishops
        this->board[0][2] = Spot(0, 2, Bishop(false));
        this->board[0][5] = Spot(0, 5, Bishop(false));
        this->scene->addWidget(this->board[0][2].getPiece().getPiece());
        this->scene->addWidget(this->board[0][5].getPiece().getPiece());
        // White Bishops
        this->board[7][2] = Spot(7, 2, Bishop(true));
        this->board[7][5] = Spot(7, 5, Bishop(true));
        this->scene->addWidget(this->board[7][2].getPiece().getPiece());
        this->scene->addWidget(this->board[7][5].getPiece().getPiece());
        // Black Queen
        this->board[0][3] = Spot(0, 3, Queen(false));
        this->scene->addWidget(this->board[0][3].getPiece().getPiece());
        // White Queen
        this->board[7][3] = Spot(7, 3, Queen(true));
        this->scene->addWidget(this->board[7][3].getPiece().getPiece());
        // Black King
        this->board[0][4] = Spot(0, 4, King(false));
        this->scene->addWidget(this->board[0][4].getPiece().getPiece());
        // White King
        this->board[7][4] = Spot(7, 4, King(true));
        this->scene->addWidget(this->board[7][4].getPiece().getPiece());
        for(int i = 0; i < 8; i++){
            // Black Pawns
            this->board[1][i] = Spot(1, i, Pawn(false));
            this->scene->addWidget(this->board[1][i].getPiece().getPiece());
            // White Pawns
            this->board[6][i] = Spot(6, i, Pawn(true));
            this->scene->addWidget(this->board[6][i].getPiece().getPiece());
        }
    }
    void drawBoard(){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                QGraphicsRectItem* grid = new QGraphicsRectItem();
                grid->setRect(j*100,i*100,100,100);
                if ((i+j) % 2){
                    grid->setBrush(Qt::black);
                } else {
                    grid->setBrush(Qt::white);
                }
                this->scene->addItem(grid);
            }
        }
    }
    Spot getSpot(int x, int y){ return this->board[x][y];}
    void initButton(){
        this->genMovesButton->setText("Generate Moves");
        this->genMovesButton->move(800,0);
        this->scene->addWidget(this->genMovesButton);
    }
};


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QGraphicsScene* scene = new QGraphicsScene();
    QPushButton* genMovesButton = new QPushButton();

    Board board = Board(scene, genMovesButton);
    board.clearBoard();
    board.drawBoard();
    board.resetBoard();

    QGraphicsView view(scene);
    view.show();

    return a.exec();
}
