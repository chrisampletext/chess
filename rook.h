#ifndef __ROOK_H__
#define __ROOK_H__
#include <string>
#include "piece.h"

class Rook: public Piece{

public:
    ~Rook();
    Rook(int x, int y , char c);

   
    void setMoves(int playerNum);
    void deleteMoves(int playerNum);
    

};

#endif 