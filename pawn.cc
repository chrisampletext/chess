#include "piece.h"
#include <iostream>
#include <sstream>
using namespace std;


Pawn::Pawn(char c,int x, int y, Board *board){
    Piece(c, x, y, board);
}

Pawn::~Pawn(){
}

//we need the current position (we have this)

//we need the position to where the piece wants to move

//we need the board state

//check if the pawn has never moved yet
// if it hasn't it can move 1/2 spaces up
// check if there are any pieces in the way
// check if the board is legal *** optional


//aside: if pawn is at the end of the board it promotes


bool::Pawn canMove(){
    if(x == 2){
        cout << "dicks" << endl;
    }
    else{
        cout << "hello world" << endl;

    }
}
