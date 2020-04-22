#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include <string>
#include "piece.h"

class Knight: public Piece{

public:
    ~Knight();
    Knight(int x, int y , char c);

   
    void setMoves(int playerNum);
    void deleteMoves(int playerNum);
    

};

#endif 