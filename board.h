#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPushButton>

#include "spot.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"
#pragma once

class Board {
    private:
        QGraphicsScene* scene;
        QPushButton* genMovesButton;
        Spot board[8][8];

    public:
        Board(QGraphicsScene* scene_, QPushButton* genMovesButton_);

    void clearBoard();
    void resetBoard();
    void drawBoard();
    void initButton();
    Spot getSpot(int x, int y);
};

#endif // BOARD_H
