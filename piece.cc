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


/*void setGame(){

}*/

bool Piece::pieceCanMove(int newx, int newy, int playerNum){
    //if first player
    if(playerNum == 1){
        //if at tile where you can move two steps (this will be the only time moving twice since no backward moving is allowed)
        if(row == 1){
            cout<<"";
            if((newy - 1 == row && newx ==col) || (newy - 2 == row && newx ==col)){
                return true;
            }
            return false;
        }else{
            if(newy - 1 == row && newx == col){
                return true;
            }else{
                return false;
            }
        }

    }else{ 
        if(row == 6){
            if((newy + 1 ==row && newx ==col)||(newy + 2 == row && newx ==col)){
                return true;
            }
            return false;
        }else{
            if(newy + 1 == row && newx == col){
                return true;
            }else{
                return false;
            }
        }
    }
}