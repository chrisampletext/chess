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
    return -1;
}

bool Player::canMove(){
    //change maybe for style
    //player selected blank tile
    int pieceIndex = getPiece();

    //cout<<"Piece: "<<getPiece()<<endl;
    if(pieceIndex==-1){
        return false;
    }
    Piece* movePiece = pieces[pieceIndex];
    
    if(number == 1){
        
        movePiece->setMoves(1);
        
    }
    if(number == 2){
        movePiece->setMoves(2);
        
    }
    if(movePiece->name=='n'||movePiece->name=='N'){
        this->updateMovesKnight();
    }else{
    this->updateMoves();
    }
    cout<<"potential moves:"<<endl;
    for(int y = 0; y<8; y++){
        for(int x =0; x<8; x++){
            cout<<movePiece->moves[x][y];
        }
        cout<<endl;
    }
    cout<<endl;

        char** temp = movePiece->moves;
        if(temp[nextCol][nextRow] == 'm'){
            return true;
        }       
        return false;
}

//checks if spot is taken
bool Player::isSpotTaken(int x, int y){
      for(int i=0; i < pieces.size(); i++){
        if(pieces[i]->col==x && pieces[i]->row==y){
            return true;
        }
    }
    return false;
}

bool Player::isOpponentPieceHere(int x,int y){
    for(int i=0; i < opponent->pieces.size(); i++){
        if(opponent->pieces[i]->col==x && opponent->pieces[i]->row==y){
            return true;
        }
    }
    return false;
}

void Player::updateMovesKnight(){
    Piece* movePiece = pieces[getPiece()];
    int row =curRow;
    int col =curCol;
    if(row - 2 >= 0 && col + 1 <= 7 && !this->isSpotTaken(row-2,col+1)){
        
        movePiece->moves[col+1][row-2] = 'm';
    }
    if(row - 1 >= 0 && col + 2 <= 7&& !this->isSpotTaken(row-1,col+2)){
        
        movePiece->moves[col+2][row-1] = 'm';
    }
    if(row + 1 <= 7 && col + 2 <= 7&& !this->isSpotTaken(row+1,col+2)){
        
        movePiece->moves[col+2][row+1] = 'm';
    }
    if(row + 2 <= 7 && col + 1 <= 7&& !this->isSpotTaken(row+2,col+1)){
        
        movePiece->moves[col+1][row+2] = 'm';
    }
    if(row + 2 <= 7 && col - 1 >= 0&& !this->isSpotTaken(row+2,col-1)){
        
        movePiece->moves[col-1][row+2] = 'm';
    }
    if(row + 1 <= 7 && col - 2 >= 0&& !this->isSpotTaken(row+1,col-2)){
        
        movePiece->moves[col-2][row+1] = 'm';
    }
    if(row - 1 >=0 && col - 2 >= 0&& !this->isSpotTaken(row-1,col-2)){
        
        movePiece->moves[col-2][row-1] = 'm';
    }
    if(row - 2 >=0 && col - 1 >= 0&& !this->isSpotTaken(row-2,col-1)){
        
        movePiece->moves[col-1][row-2] = 'm';
    }
}

void Player::updateMoves(){
    Piece* movePiece = pieces[getPiece()];
    //cout<<(movePiece->row>=0)<<endl;
    //check north
    for(int y = movePiece->row; y>= 0; y--){
        //cout<<"weouewh"<<endl;
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[movePiece->col][y]=='m'&& (this->isSpotTaken(movePiece->col,y)|| this->isOpponentPieceHere(movePiece->col,y))){
            for(int delY = y; delY>= 0; delY--){
               movePiece->moves[movePiece->col][delY] = '*'; 
            }
            break;
        }
    }
    //check northeast
    for(int x=movePiece->col, y = movePiece->row; y>= 0 && x <= 7; y--, x++){
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[x][y]=='m'&& (this->isSpotTaken(x,y)|| this->isOpponentPieceHere(x,y))){
            for(int delX=x,delY = y; delY>= 0 && delX <=7; delY--,delX++){
               movePiece->moves[delX][delY] = '*'; 
            }
            break;
        }
    }
    //check east
    for(int x = movePiece->col; x<= 7; x++){
        //cout<<"weouewh"<<endl;
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[x][movePiece->row]=='m'&& (this->isSpotTaken(x,movePiece->row)|| this->isOpponentPieceHere(x,movePiece->row))){
            for(int delX = x; delX<= 7; delX++){
               movePiece->moves[delX][movePiece->row] = '*'; 
            }
            break;
        }
    }
    //check southeast
    for(int x=movePiece->col, y = movePiece->row; y<=7 && x <= 7; y++, x++){
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[x][y]=='m'&& (this->isSpotTaken(x,y)|| this->isOpponentPieceHere(x,y))){
            for(int delX=x,delY = y; delY<= 7 && delX <=7; delY++,delX++){
               movePiece->moves[delX][delY] = '*'; 
            }
            break;
        }
    }
    //check south
    for(int y = movePiece->row; y<= 7; y++){
        //cout<<"weouewh"<<endl;
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[movePiece->col][y]=='m'&& (this->isSpotTaken(movePiece->col,y)|| this->isOpponentPieceHere(movePiece->col,y))){
            for(int delY = y; delY <=7; delY++){
               movePiece->moves[movePiece->col][delY] = '*'; 
            }
            break;
        }
    }
    //check southwest
    for(int x=movePiece->col, y = movePiece->row; y<=7 && x >=0; y++, x--){
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[x][y]=='m'&& (this->isSpotTaken(x,y)|| this->isOpponentPieceHere(x,y))){
            for(int delX=x,delY = y; delY<= 7 && delX >=0; delY++,delX--){
               movePiece->moves[delX][delY] = '*'; 
            }
            break;
        }
    }

    //check west
    for(int x = movePiece->col; x>= 0; x--){
        //cout<<"weouewh"<<endl;
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[x][movePiece->row]=='m'&& (this->isSpotTaken(x,movePiece->row)|| this->isOpponentPieceHere(x,movePiece->row))){
            for(int delX = x; delX>= 0; delX--){
               movePiece->moves[delX][movePiece->row] = '*'; 
            }
            break;
        }
    }
    //check northwest
    for(int x=movePiece->col, y = movePiece->row; y>= 0 && x>=0; y--, x--){
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[x][y]=='m'&& (this->isSpotTaken(x,y)|| this->isOpponentPieceHere(x,y))){
            for(int delX=x,delY = y; delY>= 0 && delX >=0; delY--,delX--){
               movePiece->moves[delX][delY] = '*'; 
            }
            break;
        }
    }
}

void Player::move(){
    //change to peice
  
    int pieceIndex = getPiece();
    Piece* movePiece = pieces[pieceIndex];
    //cout<<movePiece->col<<" "<<movePiece->row<<endl;
    //test case
    //cout <<"player "<<number<<endl;
    //cout <<movePiece->pieceCanMove(nextCol,nextRow,number)<<endl;
    //cout <<!(this->isSpotTaken())<<endl;
    //if(this->canMove()){
    pieces[pieceIndex]->col=nextCol;
    pieces[pieceIndex]->row=nextRow;
    
    //cout<<"col: "<<pieces[pieceIndex]->col<<endl;
    //cout<<"row: "<<pieces[pieceIndex]->row<<endl;
    
    //} 

}


void Player::start(){
    if(number == 1){
        pieces.push_back(new Rook(0, 0, 'r'));
        pieces.push_back(new Knight(1, 0, 'n'));
        pieces.push_back(new Bishop(2, 0, 'b'));
        pieces.push_back(new Queen(3, 0, 'q'));
        pieces.push_back(new King(4, 0, 'k'));
        pieces.push_back(new Bishop(5, 0, 'b'));
        pieces.push_back(new Knight(6, 0, 'n'));
        pieces.push_back(new Rook(7, 0, 'r'));
            for(int x =0; x<8; x++){
                pieces.push_back(new Pawn(x, 1, 'p'));
            }
    }else if(number == 2){
        pieces.push_back(new Rook(0, 7, 'R'));
        pieces.push_back(new Knight(1, 7, 'N'));
        pieces.push_back(new Bishop(2, 7, 'B'));
        pieces.push_back(new King(3, 7, 'K'));
        pieces.push_back(new Queen(4, 7, 'Q'));
        pieces.push_back(new Bishop(5, 7, 'B'));
        pieces.push_back(new Knight(6, 7, 'N'));
        pieces.push_back(new Rook(7, 7, 'R'));
            for(int x =0; x<8; x++){
                pieces.push_back(new Pawn(x, 6, 'P'));
            } 
    }
    
}