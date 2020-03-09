#ifndef SPOT_H
#define SPOT_H

#include "piece.h"
#pragma once

class Spot {
    Piece* piece;
    private:
        int x;
        int y;

    public:
        Spot(int x_, int y_, Piece* piece_ = new Piece());

    Piece* getPiece();
    int getX();
    int getY();
    void setX(int x_);
    void setY(int y_);
    void setPiece(Piece* piece_);
    void setPosition(int x_, int y_);
};

#endif // SPOT_H
