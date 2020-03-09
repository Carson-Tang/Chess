#ifndef PAWN_H
#define PAWN_H

#include <piece.h>
#pragma once

class Pawn: public Piece {
    public:
        Pawn(bool white);
        virtual ~Pawn();
};

#endif // PAWN_H
