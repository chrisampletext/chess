#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <vector>

class Player{//extend peice class after
    public:
    //for pieces(change to char when the piece classes are done)
    std::vector<char> pieces;
    

    ~Player();
    void start();

};

#endif