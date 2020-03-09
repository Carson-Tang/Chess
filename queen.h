#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#pragma once

class Queen: public Piece {
    public:
        Queen(bool white);

    virtual ~Queen();
};

#endif // QUEEN_H
