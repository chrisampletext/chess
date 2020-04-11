#ifndef __PAWN_H__
#define __PAWN_H__
#include <string>
#include "piece.h"

class Pawn: public Piece{



public:
 
    bool canMove() override;

};

#endif 