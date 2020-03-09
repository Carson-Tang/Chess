#include <QLabel>
#include "piece.h"

Piece::Piece(bool white_, char type_, bool killed_, QLabel *piece_) :
    white(white_), type(type_), killed(killed_), pieceLabel(piece_) {
     this->pieceLabel->setStyleSheet("QLabel{ background-color: transparent;}");
}

QLabel* Piece::getPieceLabel(){ return this->pieceLabel;}
char Piece::getType(){ return this->type;}
bool Piece::isKilled(){ return this->killed;}
bool Piece::isWhite(){ return this->white;}
bool Piece::isEmpty(){ return this->type == '.';}
void Piece::setColor(bool white_){ this->white = white_;}
void Piece::setKilled(bool killed_){ this->killed = killed_;}
void Piece::setType(char type_){ this->type = type_;}
void Piece::setImage(char type_){
    if(this->isWhite()){
        switch (type_){
            case 'K': this->pieceLabel->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/king.png")); break;
            case 'Q': this->pieceLabel->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/queen.png")); break;
            case 'R': this->pieceLabel->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/rook.png")); break;
            case 'B': this->pieceLabel->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/bishop.png")); break;
            case 'N': this->pieceLabel->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/knight.png")); break;
            case 'P': this->pieceLabel->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/pawn.png")); break;
        }
    } else {
        switch (type_){
            case 'K': this->pieceLabel->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/bking.png")); break;
            case 'Q': this->pieceLabel->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/bqueen.png")); break;
            case 'R': this->pieceLabel->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/brook.png")); break;
            case 'B': this->pieceLabel->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/bbishop.png")); break;
            case 'N': this->pieceLabel->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/bknight.png")); break;
            case 'P': this->pieceLabel->setPixmap(QPixmap("C:/Users/Carson/Documents/Chess/pieces/bpawn.png")); break;
        }
    }
}

// overrided in King class
bool Piece::hasCastled(){ return 0;}
void Piece::setCastled(bool alreadyCastled_){ return;}

//virtual bool canMove(Board board, int x_1, int y_1, int x_2, int y_2){ return 0;}
