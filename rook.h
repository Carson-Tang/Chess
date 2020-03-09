#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#pragma once

class Rook: public Piece {
    public:
        Rook(bool white);
        virtual ~Rook();
};

#endif // ROOK_H
