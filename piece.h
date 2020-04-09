#ifndef __PIECE_H__
#define __PIECE_H__
#include <string>



class Piece{

private:
    int row;
    int col;
    char name;
    std::string type;
    bool canCheck;

public:
    static void set(int x, int y);
    int getCol();
    int getRow();
    string getPlayer();
    bool canMove();

}