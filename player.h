#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <vector>
#include "piece.h"
#include "pawn.h"
#include "king.h"

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
    bool inCheck;
    

    ~Player();
    void start();
    bool canMove();
    bool isSpotTaken(int,int);
    bool isOpponentPieceHere(int,int);
    int getPiece();//gets index of peice at certain coordinate
    void move();

};

#endif