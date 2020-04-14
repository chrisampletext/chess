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
}
/*
void Piece::set(int x, int y){
    row = x;
    col = y;
}
*/

string Piece::getPlayer(){
    return type;
}



void Piece::setMoves(int playerNum){

}

void Piece::deleteMoves(int playerNum){
    
}

/*void setGame(){

}*/
