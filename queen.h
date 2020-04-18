#ifndef __QUEEN_H__
#define __QUEEN_H__
#include <string>
#include "piece.h"

class Queen: public Piece{

public:
    ~Queen();
    Queen(int x, int y , char c);

   
    void setMoves(int playerNum);
    void deleteMoves(int playerNum);
    

};

#endif 