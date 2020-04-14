#ifndef __PAWN_H__
#define __PAWN_H__
#include <string>
#include "piece.h"

class Pawn: public Piece{

public:
    ~Pawn();
    Pawn(int x, int y , char c);

   
    void setMoves(int playerNum);
    void deleteMoves(int playerNum);
    

};

#endif 