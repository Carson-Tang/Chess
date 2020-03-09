#ifndef KING_H
#define KING_H

#include "piece.h"
#pragma once

class King: public Piece {
    private:
        bool alreadyCastled;

    public:
        King(bool white, bool alreadyCastled_ = false);
        bool hasCastled();
        void setCastled(bool alreadyCastled_);
        virtual ~King();
};
#endif // KING_H
