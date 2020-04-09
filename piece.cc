#include "piece.h"
#include <iostream>
#include <sstream>


using namespace std;


Piece::Piece(char c){
    if (c == ' '){
        type = "none"
    }
    else if (c == 'P' || c == 'R' || c == 'Q' || c == 'K' || c == 'N' || c == 'B'){
        type = "white";
    }
    else{
        type = black;
    }
    name = c;
}

Piece::~Piece(){
}

void Piece::set(int x, int y){
    row = x;
    col = y;
}

int Piece::getCol(){
    return col;
}

int Piece::getRow(){
    return row;
}

string Piece::getPlayer(){
    return type;
}

bool Piece::canMove(){
    
}
