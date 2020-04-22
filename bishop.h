#ifndef __BISHOP_H__
#define __BISHOP_H__
#include <string>
#include "piece.h"

class Bishop: public Piece{

public:
    ~Bishop();
    Bishop(int x, int y , char c);

   
    void setMoves(int playerNum);
    void deleteMoves(int playerNum);
    

};

#endif 