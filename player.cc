#include "player.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <utility>

using namespace std;

Player::~Player(){
    this->opponent = nullptr;
}
Player::Player(int num){
    number = num;
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

int Player::getKing(){
    
    for(int i=0; i < pieces.size(); i++){
        
        if(pieces[i]->name =='K'||pieces[i]->name =='k'){
            return i;
        }
    }
    //error check
    return -1;
}


Player::Player(const Player*&&p){
    number = p->number;
    curCol = p->curCol;
    curRow = p->curRow;
    nextCol = p->nextCol;
    nextRow = p->nextRow;
   
    //cout<<p->opponent->pieces.size()<<endl;
    for(int i=0; i<p->pieces.size(); i++){
        if(p->pieces[i]->name == 'r' || p->pieces[i]->name == 'R'){ 
            pieces.push_back(new Rook(p->pieces[i]->col, p->pieces[i]->row, p->pieces[i]->name));
        }
        if(p->pieces[i]->name == 'n' || p->pieces[i]->name == 'N'){ 
            pieces.push_back(new Knight(p->pieces[i]->col, p->pieces[i]->row, p->pieces[i]->name));
        }
        if(p->pieces[i]->name == 'b' || p->pieces[i]->name == 'B'){ 
            pieces.push_back(new Bishop(p->pieces[i]->col, p->pieces[i]->row, p->pieces[i]->name));
        }
        if(p->pieces[i]->name == 'k' || p->pieces[i]->name == 'K'){ 
            pieces.push_back(new King(p->pieces[i]->col, p->pieces[i]->row, p->pieces[i]->name));
        }
        if(p->pieces[i]->name == 'q' || p->pieces[i]->name == 'Q'){ 
            pieces.push_back(new Queen(p->pieces[i]->col, p->pieces[i]->row, p->pieces[i]->name));
        }
        if(p->pieces[i]->name == 'p' || p->pieces[i]->name == 'P'){ 
            pieces.push_back(new Pawn(p->pieces[i]->col, p->pieces[i]->row, p->pieces[i]->name));
        }

        pieces[i]->moves = new char*[8];
        for(int x = 0; x<8; x++){
            pieces[i]->moves[x] = new char[8];
            for(int y =0; y<8; y++){
                pieces[i]->moves[x][y]=p->pieces[i]->moves[x][y];
            }
        }  
        
    }
 
    
}

bool Player::isCheckMate(){
    //try moving anything
    for(int i=0; i < opponent->pieces.size(); i++){
        
              /*  cout<<"Piece: "<<opponent->pieces[i]->name<<endl;
            for(int y = 0; y<8; y++){
                for(int x =0; x<8; x++){
                    cout<<opponent->pieces[i]->moves[x][y];
                }
                cout<<endl;
            }
            cout<<endl;           */


        for(int x = 0; x<8; x++){
            for(int y =0; y<8; y++){                
                //reset might not work right
                //constantly refresh
                Player* currentPlayerState = new Player(this);
                Player* currentOppPlayerState = new Player(this->opponent);
                //cout<<currentPlayerState->pieces[i]->name<<endl;
                            
                
                //cout<<"currentOppPlayerState->getPiece() "<<currentOppPlayerState->getPiece()<<endl;
                //char logo =currentOppPlayerState->pieces[i]->moves[x][y];
                //if(logo == 'k' || logo =='m'){            
                    //cout<<"size isCheckmate(pieces opponent has): "<<currentOppPlayerState->pieces.size()<<endl;       
                    currentOppPlayerState->opponent=currentPlayerState;
                    currentPlayerState->opponent=currentOppPlayerState;
                    currentOppPlayerState->curCol=currentOppPlayerState->pieces[i]->col;
                    currentOppPlayerState->curRow=currentOppPlayerState->pieces[i]->row;
                    currentOppPlayerState->nextCol=x;
                    currentOppPlayerState->nextRow=y;
                    //cout<<currentOppPlayerState->pieces[i]->name<<endl;
                    //cout<<"next move x "<<currentOppPlayerState->nextCol<<endl;
                    //cout<<"next move y "<<currentOppPlayerState->nextRow<<endl<<endl;
                    if(currentOppPlayerState->canMove()){
                        
                        currentOppPlayerState->move();
                        
                        if(!currentPlayerState->isCheck()){
                            //something getting modified
                            return false;
                        }
                    }
                //}
                delete currentOppPlayerState;
                delete currentPlayerState;
            }
        }
        
    }    
    return true;

}

/*bool Player::isStaleMate(){

}*/

void Player::botMove(int level){
    if (level == 1){
        cout << "level 1 bot move" << endl;
        int pieceTotal = pieces.size();
        pieceTotal--;
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        while (true){
            int randInd = rand() % pieceTotal;
            cout << randInd << endl;
            cout << "Testing: " << pieces[randInd]->name << endl;
            //obtain the random pieces current row and col
            curCol = pieces[randInd]->col;
            curRow = pieces[randInd]->row;
            for(int i = 0; i < 1000; ++i){
                //randomly choose a next row and col
                nextCol = rand() % 7;
                nextRow = rand() % 7;
                cout << curCol << "," << curRow << "     " << nextCol << "," << nextRow << endl;
                //check if its a valid move, if it is we can return it to the user
                // otherwise we wll pick a new piece
                if(canMove()){
                    //return the coords and then continue with the program
                    cout << "FINALLY FREEDOM" << endl;
                    cout << curCol << "," << curRow << "     " << nextCol << "," << nextRow << endl;
                    return;
                }
            }
            return;
        }
    }
    else if (level == 2){
        cout << "level 2 bot move" << endl;
    }
    else{
        cout << "what" << endl;
    }

}






bool Player::isCheck(){
    //opponents king
    Piece* king = opponent->pieces[opponent->getKing()];
    //cout<<"size isCheck(pieces you have): "<<pieces.size()<<endl;
    for(int i=0; i < pieces.size(); i++){
        //the person who is tryna kill
        Piece* curPiece = pieces[i];
        curCol=curPiece->col;
        curRow=curPiece->row;
        curPiece->setMoves(number);
        if(curPiece->name=='n'||curPiece->name=='N'){
            this->updateMovesKnight();
        }else{
            this->updateMoves();
            if(curPiece->name=='p'||curPiece->name=='P'){
                this->updateMovesPawn();
            }
        }
/*
        cout<<"potential moves:"<<endl;
    for(int y = 0; y<8; y++){
        for(int x =0; x<8; x++){
            cout<<curPiece->moves[x][y];
        }
        cout<<endl;
    }
    cout<<endl;*/
        
        if(curPiece->moves[king->col][king->row]=='k'){
            /*if(number == 1){
                
            }else{
                
            }*/
            return true;
        }
    }
    return false;
}
int Player::getOpponentPiece(int x, int y){
    //cout<<"curCol "<< curCol << " curRow "<<curRow<<endl;

    for(int i=0; i < opponent->pieces.size(); i++){
        //cout<<"pieces[i]->col "<< pieces[i]->col << " pieces[i]->row "<<pieces[i]->row<<endl;
        if(opponent->pieces[i]->col==x && opponent->pieces[i]->row==y){
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
        
    movePiece->setMoves(number);
        
    
    if(movePiece->name=='n'||movePiece->name=='N'){
        this->updateMovesKnight();
    }else{
        this->updateMoves();
        if(movePiece->name=='p'||movePiece->name=='P'){
            this->updateMovesPawn();
        }
    }
    //cout<<"tryna go nextCol: "<<nextCol<<endl;
    //cout<<"tryna go nextRol: "<<nextRow<<endl;
    /*for(int y = 0; y<8; y++){
        for(int x =0; x<8; x++){
            cout<<movePiece->moves[x][y];
        }
        cout<<endl;
    }
    cout<<endl;*/
    

        char** temp = movePiece->moves;
        if(temp[nextCol][nextRow] == 'm'){
            return true;
        }//kills the oppoent piece
        else if(temp[nextCol][nextRow] == 'k'){
            //cout<<"gotem"<<endl;
            opponent->pieces.erase(opponent->pieces.begin()+getOpponentPiece(nextCol,nextRow));
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
            //cout<<"piece here: "<<opponent->pieces[i]->name<<endl;
            return true;
        }
    }
    return false;
}
void Player::updateMovesPawn(){
    Piece* movePiece = pieces[getPiece()];
    int row =curRow;
    int col =curCol;
    if(number == 2){
        if(row + 1 <= 7 && col - 1 >= 0 && this->isOpponentPieceHere(col-1,row+1)){
            movePiece->moves[col-1][row+1] = 'k';
        }
        if(row + 1 <= 7 && col + 1 <=7 && this->isOpponentPieceHere(col+1,row+1)){
            movePiece->moves[col+1][row+1] = 'k';
        }
    }else{
        if(row - 1 >= 0 && col - 1 >= 0 && this->isOpponentPieceHere(col-1,row-1)){
            movePiece->moves[col-1][row-1] = 'k';
        }
        if(row - 1 >= 0 && col + 1 <=7  && this->isOpponentPieceHere(col+1,row-1)){
            movePiece->moves[col+1][row-1] = 'k';
        }

    }
}
void Player::updateMovesKnight(){
    Piece* movePiece = pieces[getPiece()];
    int row =curRow;
    int col =curCol;
    if(row - 2 >= 0 && col + 1 <= 7 && !this->isSpotTaken(col+1,row-2)){
        
        movePiece->moves[col+1][row-2] = 'm';
        if(this->isOpponentPieceHere(col+1,row-2)){
            movePiece->moves[col+1][row-2] = 'k';
        }
    }
    if(row - 1 >= 0 && col + 2 <= 7&& !this->isSpotTaken(col+2,row-1)){
        
        movePiece->moves[col+2][row-1] = 'm';
        if(this->isOpponentPieceHere(col+2,row-1)){
            movePiece->moves[col+2][row-1] = 'k';
        }
    }
    if(row + 1 <= 7 && col + 2 <= 7&& !this->isSpotTaken(col+2,row+1)){
        //cout<<this->isSpotTaken(row+1,col+2)<<endl;
        movePiece->moves[col+2][row+1] = 'm';
        if(this->isOpponentPieceHere(col+2,row+1)){
            movePiece->moves[col+2][row+1] = 'k';
        }
    }
    if(row + 2 <= 7 && col + 1 <= 7&& !this->isSpotTaken(col+1,row+2)){
        
        movePiece->moves[col+1][row+2] = 'm';
        if(this->isOpponentPieceHere(col+1,row+2)){
            movePiece->moves[col+1][row+2] = 'k';
        }
    }
    if(row + 2 <= 7 && col - 1 >= 0&& !this->isSpotTaken(col-1,row+2)){
        
        movePiece->moves[col-1][row+2] = 'm';
        if(this->isOpponentPieceHere(col-1,row+2)){
            movePiece->moves[col-1][row+2] = 'k';
        }
    }
    if(row + 1 <= 7 && col - 2 >= 0&& !this->isSpotTaken(col-2,row+1)){
        
        movePiece->moves[col-2][row+1] = 'm';
        if(this->isOpponentPieceHere(col-2,row+1)){
            movePiece->moves[col-2][row+1] = 'k';
        }
    }
    if(row - 1 >=0 && col - 2 >= 0&& !this->isSpotTaken(col-2,row-1)){
        
        movePiece->moves[col-2][row-1] = 'm';
        if(this->isOpponentPieceHere(col-2,row-1)){
            movePiece->moves[col-2][row-1] = 'k';
        }
    }
    if(row - 2 >=0 && col - 1 >= 0&& !this->isSpotTaken(col-1,row-2)){
        
        movePiece->moves[col-1][row-2] = 'm';
        if(this->isOpponentPieceHere(col-1,row-2)){
            movePiece->moves[col-1][row-2] = 'k';
        }
    }
}

void Player::updateMoves(){
    //cout<<"piece "<<getPiece()<<endl;
    //cout<<"col "<<curCol<<endl;
    //cout<<"row "<<curRow<<endl;
    Piece* movePiece = pieces[getPiece()];
    
    //check north
    for(int y = movePiece->row; y>= 0; y--){
        //cout<<"weouewh"<<endl;
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[movePiece->col][y]=='m'){
            if(this->isSpotTaken(movePiece->col,y) ||(isOpponentPieceHere(movePiece->col,y)&&(movePiece->name=='p'||movePiece->name=='P'))){
                for(int delY = y; delY>= 0; delY--){
                movePiece->moves[movePiece->col][delY] = '*'; 
                }
                break;
            }else if(this->isOpponentPieceHere(movePiece->col,y)){
                movePiece->moves[movePiece->col][y] = 'k';
                y--; 
                for(int delY = y; delY>= 0; delY--){
                    movePiece->moves[movePiece->col][delY] = '*'; 
                }
                break;
            }
        }
    }
    //check northeast
    for(int x=movePiece->col, y = movePiece->row; y>= 0 && x <= 7; y--, x++){
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[x][y]=='m'){
            if(this->isSpotTaken(x,y)){
                for(int delX=x,delY = y; delY>= 0 && delX <=7; delY--,delX++){
                movePiece->moves[delX][delY] = '*'; 
                }
                break;
            }else if(this->isOpponentPieceHere(x,y)){
                movePiece->moves[x][y] = 'k';
                y--;
                x++; 
                for(int delX=x,delY = y; delY>= 0 && delX <=7; delY--,delX++){
                    movePiece->moves[delX][delY] = '*'; 
                }
                break;
            }
        }
    }
    //check east
    for(int x = movePiece->col; x<= 7; x++){
        //cout<<"weouewh"<<endl;
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[x][movePiece->row]=='m'){
            if(this->isSpotTaken(x,movePiece->row)){
                for(int delX = x; delX<= 7; delX++){
                movePiece->moves[delX][movePiece->row] = '*'; 
                }
                break;
            }else if(this->isOpponentPieceHere(x,movePiece->row)){
                movePiece->moves[x][movePiece->row] = 'k'; 
                x++;
                for(int delX = x; delX<= 7; delX++){
                    movePiece->moves[delX][movePiece->row] = '*'; 
                }
                break;
            }
        }
    }
    //check southeast
    for(int x=movePiece->col, y = movePiece->row; y<=7 && x <= 7; y++, x++){
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[x][y]=='m'){
            if(this->isSpotTaken(x,y)){
                for(int delX=x,delY = y; delY<= 7 && delX <=7; delY++,delX++){
                movePiece->moves[delX][delY] = '*'; 
                }
                break;
            }else if(this->isOpponentPieceHere(x,y)){
                movePiece->moves[x][y] = 'k'; 
                y++;
                x++;
                for(int delX=x,delY = y; delY<= 7 && delX <=7; delY++,delX++){
                    movePiece->moves[delX][delY] = '*'; 
                }
                break;
            }
        }
    }
    //check south
    for(int y = movePiece->row; y<= 7; y++){
        //cout<<"weouewh"<<endl;
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[movePiece->col][y]=='m'){
            if(this->isSpotTaken(movePiece->col,y)||(isOpponentPieceHere(movePiece->col,y)&&(movePiece->name=='p'||movePiece->name=='P'))){
                for(int delY = y; delY <=7; delY++){
                movePiece->moves[movePiece->col][delY] = '*'; 
                }
                break;
            }else if(this->isOpponentPieceHere(movePiece->col,y)){
                movePiece->moves[movePiece->col][y] = 'k'; 
                y++;
                for(int delY = y; delY <=7; delY++){
                    movePiece->moves[movePiece->col][delY] = '*'; 
                }
                break;
            }
        }
    }
    //check southwest
    for(int x=movePiece->col, y = movePiece->row; y<=7 && x >=0; y++, x--){
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[x][y]=='m'){
            if(this->isSpotTaken(x,y)){
                for(int delX=x,delY = y; delY<= 7 && delX >=0; delY++,delX--){
                movePiece->moves[delX][delY] = '*'; 
                }
                break;
            }else if(this->isOpponentPieceHere(x,y)){
                movePiece->moves[x][y] = 'k'; 
                y++;
                x--;
                for(int delX=x,delY = y; delY<= 7 && delX >=0; delY++,delX--){
                movePiece->moves[delX][delY] = '*'; 
                }
                break;
            }
        }
    }

    //check west
    for(int x = movePiece->col; x>= 0; x--){
        //cout<<"weouewh"<<endl;
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[x][movePiece->row]=='m'){
            if(this->isSpotTaken(x,movePiece->row)){
                for(int delX = x; delX>= 0; delX--){
                movePiece->moves[delX][movePiece->row] = '*'; 
                }
                break;
            }else if(this->isOpponentPieceHere(x,movePiece->row)){
                movePiece->moves[x][movePiece->row] = 'k'; 
                x--;
                for(int delX = x; delX>= 0; delX--){
                    movePiece->moves[delX][movePiece->row] = '*'; 
                }
                break;
            }
        }
    }
    //check northwest
    for(int x=movePiece->col, y = movePiece->row; y>= 0 && x>=0; y--, x--){
        //cout<<movePiece->moves[movePiece->col][y]<<endl;
        if(movePiece->moves[x][y]=='m'){
            if(this->isSpotTaken(x,y)){
                for(int delX=x,delY = y; delY>= 0 && delX >=0; delY--,delX--){
                    movePiece->moves[delX][delY] = '*'; 
                }
                break;
            }else if(this->isOpponentPieceHere(x,y)){
                movePiece->moves[x][y] = 'k';
                y--;
                x--;
                for(int delX=x,delY = y; delY>= 0 && delX >=0; delY--,delX--){
                    movePiece->moves[delX][delY] = '*'; 
                }
                break;
            }
        }
    }


//////////////////////////



    /*for(int y = 0; y<8; y++){
        for(int x =0; x<8; x++){
            cout<<movePiece->moves[x][y];
        }
        cout<<endl;
    }
    cout<<endl;*/
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
    
    if((movePiece->name=='p'|| movePiece->name=='P')&&(nextRow == 0 || nextRow==8) ){
        delete movePiece;
        char s;
        while(cin>>s){
            if(number==2){
                if(s=='n'){
                    movePiece =new Knight(nextCol, nextRow, 'n');
                    break;
                }else if(s=='q'){
                    movePiece =new Queen(nextCol, nextRow, 'q');
                    break;
                }else if(s=='b'){
                    movePiece =new Bishop(nextCol, nextRow, 'b');
                    break;
                }else if(s=='r'){
                    movePiece =new Rook(nextCol, nextRow, 'r');
                    break;
                }else{
                    cout<<"wrong"<<endl;
                }
            }
            if(number==1){
                if(s=='N'){
                    movePiece =new Knight(nextCol, nextRow, 'N');
                    break;
                }else if(s=='Q'){
                    movePiece =new Queen(nextCol, nextRow, 'Q');
                    break;
                }else if(s=='B'){
                    movePiece =new Bishop(nextCol, nextRow, 'B');
                    break;
                }else if(s=='R'){
                    movePiece =new Rook(nextCol, nextRow, 'R');
                    break;
                }else{
                    cout<<"wrong"<<endl;
                }
            }
        }

    }
    pieces[pieceIndex]->col=nextCol;
    pieces[pieceIndex]->row=nextRow;
    //cout<<"col: "<<pieces[pieceIndex]->col<<endl;
    //cout<<"row: "<<pieces[pieceIndex]->row<<endl;
    
    //} 

}


void Player::start(){
    if(number == 2){
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
    }else if(number == 1){
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


void Player::restart(){
    pieces.clear();
    if(number == 2){
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
    }else if(number == 1){
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