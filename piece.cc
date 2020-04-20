#include "piece.h"
#include <iostream>
#include <sstream>


using namespace std;


Piece::Piece(int x, int y, char c){
    if (c == ' '){
        type = "none";
    }
    else if (c == 'P' || c == 'R' || c == 'Q' || c == 'K' || c == 'N' || c == 'B'){
        type = "white";
    }
    else{
        type = "black";
    }
    name = c;
    col = x;
    row = y;
}

Piece::~Piece(){
       for(int i = 0; i < 8; ++i) {
        delete[] moves[i];   
    }
    
    delete[] moves;
}
/*
void Piece::set(int x, int y){
    row = x;
    col = y;
}
*/


void Piece::setMoves(int playerNum){

}

void Piece::deleteMoves(int playerNum){
    
}

/*void setGame(){

}*/
