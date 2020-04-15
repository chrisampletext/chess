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
  
    moves.clear();
    char** move = new char*[8];
    for(int x = 0; x<8; x++){
        move[x] = new char[8];
        for(int y =0; y<8; y++){
            move[x][y]='*';
        }
    
    }    

    moves.push_back(move);
    moves.push_back(move);
    moves.push_back(move);
    moves.push_back(move);
    moves.push_back(move);
    moves.push_back(move);
    moves.push_back(move);
    moves.push_back(move);


    //n
    if(row - 1 >= 0){
        moves[0][col][row-1] = 'm';
    }
    //ne
    if(row - 1 >= 0 && col + 1 <= 7){
        
        moves[1][col+1][row-1] = 'm';
    }
    //e
    if(col + 1 <= 7){
        moves[2][col+1][row] = 'm';
    }
    //se
    if(row + 1 <= 7 && col + 1 <=7){
        moves[3][col+1][row+1] = 'm';
    }
    //s      
    if(row + 1 <= 7){
        moves[4][col][row+1] = 'm';
    }
    //sw
    if(row + 1 <= 7 && col - 1 >= 0){
        moves[5][col-1][row+1] = 'm';
    }
    //w
    if(col - 1 >= 0){
        moves[6][col-1][row] = 'm';
    }
    //nw
    if(row-1 >=0 && col - 1 >= 0){
        moves[7][col-1][row-1] = 'm';
    }

        
    

    char** temp = moves[1];
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
