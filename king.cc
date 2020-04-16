#include "king.h"
#include <iostream>
#include <sstream>
using namespace std;


King::King(int x, int y, char c): Piece(x, y, c) {}

/*void Pawn::setGame(Board * b){
    game = b;
}*/


King::~King(){
}

//we need the current position (we have this)

//we need the position to where the piece wants to move

//we need the board state

//check if the pawn has never moved yet
// if it hasn't it can move 1/2 spaces up
// check if there are any pieces in the way
// check if the board is legal *** optional


//aside: if pawn is at the end of the board it promotes

//move either by kill or by going up
//check if pawn is going down or up and determine if you can move



void King::deleteMoves(int playerNum){

}

//MOVE N NE E SE S SW W NW 
//     0 1  2 3  4 5  6 7 
void King::setMoves(int playerNum){
  
    moves = new char*[8];
    for(int x = 0; x<8; x++){
        moves[x] = new char[8];
        for(int y =0; y<8; y++){
            moves[x][y]='*';
        }
    
    }    


    //n
    if(row - 1 >= 0){
        moves[col][row-1] = 'm';
    }
    //ne
    if(row - 1 >= 0 && col + 1 <= 7){
        
        moves[col+1][row-1] = 'm';
    }
    //e
    if(col + 1 <= 7){
        moves[col+1][row] = 'm';
    }
    //se
    if(row + 1 <= 7 && col + 1 <=7){
        moves[col+1][row+1] = 'm';
    }
    //s      
    if(row + 1 <= 7){
        moves[col][row+1] = 'm';
    }
    //sw
    if(row + 1 <= 7 && col - 1 >= 0){
        moves[col-1][row+1] = 'm';
    }
    //w
    if(col - 1 >= 0){
        moves[col-1][row] = 'm';
    }
    //nw
    if(row-1 >=0 && col - 1 >= 0){
        moves[col-1][row-1] = 'm';
    }

        
    
    //if able to kill
    //constant M represent move
    //constant K represent kill

}
