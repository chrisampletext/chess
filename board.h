#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>
#include "player.h"


class Board{//extend peice class after
    public:
    //2d array for peice class for board
    //change to peice type
    //board is [x][y]
    Board(Player* fp,Player* sp);
    
    char**curBoard;
    //first player second player
    
    void move(Player* fp,Player* sp);
    ~Board();
    
    
    //void end();
    //bool isCheckMate();
    //bool isCheck();
};

std::ostream& operator<<(std::ostream& out, const Board &board);

#endif