#include "rook.h"
#include "piece.h"


Rook::Rook(bool white): Piece(white, 'R') {
    this->setImage('R');
}
Rook::~Rook(){}

