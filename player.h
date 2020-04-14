#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <vector>
#include "piece.h"
#include "pawn.h"

class Player{//extend peice class after
    public:
    //for pieces(change to char when the piece classes are done)
   
    int number;
    std::vector<Piece*> pieces;
    Player* opponent;
    //will be entered in through commands
    int curCol;
    int curRow;
    int nextCol;
    int nextRow;
    

    ~Player();
    void start();
    bool canMove();
    bool isSpotTaken(int,int);
    int getPiece();//gets index of peice at certain coordinate
    void move();

};

#endif