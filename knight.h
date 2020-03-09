#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#pragma once

class Knight: public Piece {
    public:
        Knight(bool white);
        virtual ~Knight();
};
#endif // KNIGHT_H
