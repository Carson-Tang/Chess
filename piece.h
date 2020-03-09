#ifndef PIECE_H
#define PIECE_H

#include <QLabel>
#pragma once

class Piece {
    QLabel *pieceLabel;
    private:
        bool killed;
        bool white;
        char type;
    public:
        Piece(bool white_ = false, char type_ = '.', bool killed_ = false, QLabel *piece_ = new QLabel());

    QLabel* getPieceLabel();
    char getType();
    bool isKilled();
    bool isWhite();
    bool isEmpty();
    void setColor(bool white_);
    void setKilled(bool killed_);
    void setType(char type_);
    void setImage(char type_);
    virtual bool hasCastled();
    //virtual bool canMove(Board board, int x_1, int y_1, int x_2, int y_2){ return 0;}
    virtual void setCastled(bool alreadyCastled_);
};

#endif // PIECE_H
