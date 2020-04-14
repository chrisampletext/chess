#include "pawn.h"
#include <iostream>
#include <sstream>
using namespace std;


Pawn::Pawn(int x, int y, char c): Piece(x, y, c) {}

/*void Pawn::setGame(Board * b){
    game = b;
}*/


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

//move either by kill or by going up
//check if pawn is going down or up and determine if you can move



void Pawn::deleteMoves(int playerNum){

}

//MOVE N NE E SE S SW W NW 
//     0 1  2 3  4 5  6 7 
void Pawn::setMoves(int playerNum){
    
    char** move = new char*[8];
    for(int x = 0; x<8; x++){
        move[x] = new char[8];
        for(int y =0; y<8; y++){
            move[x][y]='*';
        }
    }    
    //for first player
    if(playerNum == 1){
        //first move case 
        if(row==1){ 
            move[col][row+2] = 'm';
        }
        if(row + 1 <= 7){
            move[col][row+1] = 'm';
        }
    }
    else if(playerNum == 2){
        //first move case  
        if(row==6){ 
            move[col][row-2] = 'm';
        }
        if(row - 1 >= 0){
            move[col][row-1] = 'm';
        }
    }
    
    moves.push_back(move);


    char** temp = moves[0];
    for(int y = 0; y<8; y++){
        for(int x =0; x<8; x++){
            cout<<temp[x][y];
        }
        cout<<endl;
    }
    //if able to kill
    //constant M represent move
    //constant K represent kill

}
