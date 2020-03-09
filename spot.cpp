#include "spot.h"
#include "piece.h"

Spot::Spot(int x_, int y_, Piece* piece_){
    this->setPiece(piece_);
    this->setX(x_);
    this->setY(y_);
    this->setPosition(x_, y_);
}

Piece* Spot::getPiece(){ return this->piece;}
int Spot::getX(){ return this->x;}
int Spot::getY(){ return this->y;}
void Spot::setX(int x_){ this->x = x_;}
void Spot::setY(int y_){ this->y = y_;}
void Spot::setPiece(Piece* piece_){ this->piece = piece_;}
void Spot::setPosition(int x_, int y_){ this->piece->getPieceLabel()->move(y_*100+5, x_*100);}
