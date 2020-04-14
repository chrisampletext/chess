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

bool Player::canMove(){
    //change maybe for style
    Piece* movePiece = pieces[getPiece()];
    if(number == 1){
        movePiece->setMoves(1);
    }
    if(number == 2){
        movePiece->setMoves(2);
    }
    for(int i=0; i<movePiece->moves.size(); i++){
        char** temp =movePiece->moves[i];
        if(temp[nextCol][nextRow] == 'm'){
            //cases for all 6 directions
            //for player 1:
            if(number == 1){
                //to go forward 
                 
                for(int y = curRow; y<curRow; y++){
                    //if there is a piece on anyof these spots
                    //should do a check to see which direction
                    if(this->isSpotTaken(curCol,y)){
                       return false; 
                    }

                }
                return true;
            }

            if(number == 2){
                //to go forward   
                for(int y = curRow; y<curRow; y--){
                    //if there is a piece on anyof these spots
                    if(this->isSpotTaken(curCol,y)){
                       return false; 
                    }

                }
                return true;
            }
        }       
        return false;
    }
    
    
  
    return false;
}


bool Player::isSpotTaken(int x, int y){
      for(int i=0; i < pieces.size(); i++){
        if(pieces[i]->col==x && pieces[i]->row==y){
            return true;
        }
    }
        for(int i=0; i < opponent->pieces.size(); i++){
        if(opponent->pieces[i]->col==x && opponent->pieces[i]->row==y){
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
    if(this->canMove()){
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