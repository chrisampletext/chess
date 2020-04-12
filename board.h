#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>
#include "player.h"

class Board: public Player {//extend peice class after
    private:
    string turn; //which players turn, one of w or b

    public:
    //2d array for peice class for board
    //change to peice type
    //board is [x][y]
    char**curBoard;
    //first player second player
    Player* fp;
    Player* sp;
    

    ~Board();
    void start(); //initial board creation
    void setup(); //setup mode
    void movePiece(const int x1y1, const int x2y2); // moves a piece
    void game(); //actual gameplay
    //void end();
    //bool isCheckMate();
    //bool isCheck();
};

std::ostream& operator<<(std::ostream& out, const Board &board);

#endif