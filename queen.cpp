#include "queen.h"
#include "piece.h"


Queen::Queen(bool white): Piece(white, 'Q') {
    this->setImage('Q');
}
Queen::~Queen(){}
