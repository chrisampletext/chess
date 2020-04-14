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
    std::vector<char**> moves;
    int col;
    int row;
    char name;
    //void set(int x, int y);
    ~Piece();
    Piece(int x, int y, char c);
    std::string getPlayer();
    virtual void setMoves(int playerNum);
    virtual void deleteMoves(int playerNum);

};
#endif