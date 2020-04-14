#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <vector>
//#include "board.h"



class Piece{

private:
    
    
    std::string type;
    bool canCheck;
   // Board *board;

public:
    int col;
    int row;
    char name;
    std::vector<char**> moves;

    //void set(int x, int y);
    ~Piece();
    Piece(int x, int y, char c);
    std::string getPlayer();
    

    virtual void setMoves(int playerNum);
    virtual void deleteMoves(int playerNum);
    //virtual void setGame();

};

#endif