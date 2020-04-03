#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>

class Board{//extend peice class after
    public:
    //2d array for peice class for board
    //change to peice type
    //board is [x][y]
    char**curBoard;
    
    ~Board();
    void start();
    //void end();
    //bool isCheckMate();
    //bool isCheck();
};

std::ostream& operator<<(std::ostream& out, const Board &board);

#endif