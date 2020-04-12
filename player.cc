#include "player.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <utility>

using namespace std;

Player::~Player(){
    
}

int Player::getPiece(){
    //cout<<"curCol "<< curCol << " curRow "<<curRow<<endl;

    for(int i=0; i < pieces.size(); i++){
        //cout<<"pieces[i]->col "<< pieces[i]->col << " pieces[i]->row "<<pieces[i]->row<<endl;
        if(pieces[i]->col==curCol && pieces[i]->row==curRow){
            return i;
        }
    }
    //error check
    return 0;
}

bool Player::isSpotTaken(){
    for(int i=0; i < pieces.size(); i++){
        if(pieces[i]->col==nextCol && pieces[i]->row==nextRow){
            return true;
        }
    }
        for(int i=0; i < opponent->pieces.size(); i++){
        if(opponent->pieces[i]->col==nextCol && opponent->pieces[i]->row==nextRow){
            return true;
        }
    }
    return false;
}

void Player::move(){
    //change to peice
    
    Piece* movePiece = pieces[getPiece()];
    //cout<<movePiece->col<<" "<<movePiece->row<<endl;
    //test case
    cout <<"player "<<number<<endl;
    //cout <<movePiece->pieceCanMove(nextCol,nextRow,number)<<endl;
    //cout <<!(this->isSpotTaken())<<endl;
    if(movePiece->pieceCanMove(nextCol,nextRow,number) && !(this->isSpotTaken())){
        pieces[getPiece()]->col=nextCol;
        pieces[getPiece()]->row=nextRow;
    }
    



}


void Player::start(){
    if(number == 1){
        pieces.push_back(new Pawn(0, 0, 'p'));
        pieces.push_back(new Pawn(1, 0, 'p'));
        pieces.push_back(new Pawn(2, 0, 'p'));
        pieces.push_back(new Pawn(3, 0, 'p'));
        pieces.push_back(new Pawn(4, 0, 'p'));
        pieces.push_back(new Pawn(5, 0, 'p'));
        pieces.push_back(new Pawn(6, 0, 'p'));
        pieces.push_back(new Pawn(7, 0, 'p'));
            for(int x =0; x<8; x++){
                pieces.push_back(new Pawn(x, 1, 'p'));
            }
    }else if(number == 2){
        pieces.push_back(new Pawn(0, 6, 'P'));
        pieces.push_back(new Pawn(1, 6, 'P'));
        pieces.push_back(new Pawn(2, 6, 'P'));
        pieces.push_back(new Pawn(3, 6, 'P'));
        pieces.push_back(new Pawn(4, 6, 'P'));
        pieces.push_back(new Pawn(5, 6, 'P'));
        pieces.push_back(new Pawn(6, 6, 'P'));
        pieces.push_back(new Pawn(7, 6, 'P'));
            for(int x =0; x<8; x++){
                pieces.push_back(new Pawn(x, 7, 'P'));
            } 
    }
    
}