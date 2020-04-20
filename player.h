#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <vector>
#include "piece.h"
#include "pawn.h"
#include "king.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"

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
    //bool inCheck;
    

    ~Player();
    void start();
    void restart();
    bool canMove();
    bool isSpotTaken(int,int);
    bool isOpponentPieceHere(int,int);
    int getPiece();//gets index of peice at certain coordinate
    int getKing();//gets index of king
    int getOpponentPiece(int,int);
    void move();
    void updateMoves();
    void updateMovesKnight();
    void updateMovesPawn();
    //if you have checked your opponent
    bool isCheck();
    bool isCheckMate();
    Player(int); 
 
    Player(const Player *&&p2); 
    

};

#endif