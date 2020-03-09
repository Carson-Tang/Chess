#include "piece.h"
#include "pawn.h"


Pawn::Pawn(bool white): Piece(white, 'P') {
    this->setImage('P');
}
Pawn::~Pawn(){}

