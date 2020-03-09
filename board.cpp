#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPushButton>

#include "spot.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "board.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"

Board::Board(QGraphicsScene* scene_, QPushButton* genMovesButton_) : board{
    {Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0)},
    {Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0)},
    {Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0)},
    {Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0)},
    {Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0)},
    {Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0)},
    {Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0)},
    {Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0), Spot(0,0)},
 } {
    this->scene = scene_;
    this->genMovesButton = genMovesButton_;
    this->initButton();
    this->clearBoard();
    this->drawBoard();
    this->resetBoard();
}

void Board::clearBoard(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            this->board[i][j] = Spot(0, 0);
        }
    }
}

void Board::resetBoard(){
    // Black Rooks
    this->board[0][0] = Spot(0, 0, new Rook(false));
    this->board[0][7] = Spot(0, 7, new Rook(false));
    this->scene->addWidget(this->board[0][0].getPiece()->getPieceLabel());
    this->scene->addWidget(this->board[0][7].getPiece()->getPieceLabel());
    // White Rooks
    this->board[7][0] = Spot(7, 0, new Rook(true));
    this->board[7][7] = Spot(7, 7, new Rook(true));
    this->scene->addWidget(this->board[7][0].getPiece()->getPieceLabel());
    this->scene->addWidget(this->board[7][7].getPiece()->getPieceLabel());
    // Black Knights
    this->board[0][1] = Spot(0, 1, new Knight(false));
    this->board[0][6] = Spot(0, 6, new Knight(false));
    this->scene->addWidget(this->board[0][1].getPiece()->getPieceLabel());
    this->scene->addWidget(this->board[0][6].getPiece()->getPieceLabel());
    // White Knights
    this->board[7][1] = Spot(7, 1, new Knight(true));
    this->board[7][6] = Spot(7, 6, new Knight(true));
    this->scene->addWidget(this->board[7][1].getPiece()->getPieceLabel());
    this->scene->addWidget(this->board[7][6].getPiece()->getPieceLabel());
    // Black Bishops
    this->board[0][2] = Spot(0, 2, new Bishop(false));
    this->board[0][5] = Spot(0, 5, new Bishop(false));
    this->scene->addWidget(this->board[0][2].getPiece()->getPieceLabel());
    this->scene->addWidget(this->board[0][5].getPiece()->getPieceLabel());
    // White Bishops
    this->board[7][2] = Spot(7, 2, new Bishop(true));
    this->board[7][5] = Spot(7, 5, new Bishop(true));
    this->scene->addWidget(this->board[7][2].getPiece()->getPieceLabel());
    this->scene->addWidget(this->board[7][5].getPiece()->getPieceLabel());
    // Black Queen
    this->board[0][3] = Spot(0, 3, new Queen(false));
    this->scene->addWidget(this->board[0][3].getPiece()->getPieceLabel());
    // White Queen
    this->board[7][3] = Spot(7, 3, new Queen(true));
    this->scene->addWidget(this->board[7][3].getPiece()->getPieceLabel());
    // Black King
    this->board[0][4] = Spot(0, 4, new King(false));
    this->scene->addWidget(this->board[0][4].getPiece()->getPieceLabel());
    // White King
    this->board[7][4] = Spot(7, 4, new King(true));
    this->scene->addWidget(this->board[7][4].getPiece()->getPieceLabel());
    for(int i = 0; i < 8; i++){
        // Black Pawns
            this->board[1][i] = Spot(1, i, new Pawn(false));
            this->scene->addWidget(this->board[1][i].getPiece()->getPieceLabel());
            // White Pawns
            this->board[6][i] = Spot(6, i, new Pawn(true));
            this->scene->addWidget(this->board[6][i].getPiece()->getPieceLabel());
    }
}

void Board::drawBoard(){
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
void Board::initButton(){
    this->genMovesButton->setText("Generate Moves");
    this->genMovesButton->move(800,0);
    this->scene->addWidget(this->genMovesButton);
}
Spot Board::getSpot(int x, int y){ return this->board[x][y];}

