#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#pragma once

class Bishop: public Piece {
    public:
        Bishop(bool white);
        virtual ~Bishop();
};

#endif // BISHOP_H
