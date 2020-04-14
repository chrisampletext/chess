#ifndef PIECE_H
#define PIECE_H
#include <string>
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
    //void set(int x, int y);
    ~Piece();
    Piece(int x, int y, char c);
    std::string getPlayer();
    bool pieceCanMove(int newx, int newy, int playerNum);
    //virtual bool pieceCanMove(int x,int y)=0;
    //virtual void setGame();

};

#endif