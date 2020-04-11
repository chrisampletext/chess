#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <vector>
#include "piece.h"

class Player{//extend peice class after
    public:
    //for pieces(change to char when the piece classes are done)
    std::vector<Piece*> pieces;
    

    ~Player();
    void start();

};

#endif