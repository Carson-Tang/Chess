#include "piece.h"
#include "bishop.h"


Bishop::Bishop(bool white): Piece(white, 'B') {
    this->setImage('B');
}
Bishop::~Bishop(){}
