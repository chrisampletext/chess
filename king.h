#ifndef __KING_H__
#define __KING_H__
#include <string>
#include "piece.h"

class King: public Piece{

public:
    ~King();
    King(int x, int y , char c);

   
    void setMoves(int playerNum);
    void deleteMoves(int playerNum);
    

};

#endif 