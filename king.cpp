#include "king.h"
#include "piece.h"



King::King(bool white, bool alreadyCastled_): Piece(white, 'K') {
    this->setCastled(alreadyCastled_);
    this->setImage('K');
}

bool King::hasCastled(){ return this->alreadyCastled;}
void King::setCastled(bool alreadyCastled_){ this->alreadyCastled = alreadyCastled_;}
King::~King(){}
