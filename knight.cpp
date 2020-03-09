#include "piece.h"
#include "knight.h"


Knight::Knight(bool white): Piece(white, 'N') {
    this->setImage('N');
}
Knight::~Knight(){}
