#include "board.h"
#include "player.h"
#include "piece.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <string>
#include <utility>

using namespace std;

ostream& operator<<(ostream& out, Board* board){
    for(int y = 0; y<8; y++){
        for(int x =0; x<8; x++){
            out<<board->curBoard[x][y];
        }
        out<<endl;
    }

    return out;

}


Board::~Board(){
    for(int i = 0; i < 8; ++i) {
        delete[] curBoard[i];   
    }
    
    delete[] curBoard;
}

//to start
Board::Board(Player* fp,Player* sp){
    curBoard = new char*[8];
    whichTurn = 'w';
    whiteWin = 0;
    blackWin = 0;
    for(int x = 0; x<8; x++){
        curBoard[x] = new char[8];
        for(int y =0; y<8; y++){
            curBoard[x][y]='*';
        }
    }
    //set first and second
    for (int x=0;x<8;x++){
        curBoard[x][0] = fp->pieces[x]->name;
        curBoard[x][1] = fp->pieces[x+8]->name;
        curBoard[x][6] = sp->pieces[x+8]->name;
        curBoard[x][7] = sp->pieces[x]->name;
    }
    fp->inCheck = false;
    sp->inCheck = false;
}

void Board::move(Player* fp,Player* sp){
    for(int x = 0; x<8; x++){
            for(int y =0; y<8; y++){
            curBoard[x][y]='*';
        }
    }

    for(int i=0; i < fp->pieces.size(); i++){
        //cout<<"fp->pieces[i]->col "<< fp->pieces[i]->col << " fp->pieces[i]->row "<<fp->pieces[i]->row<<endl;
        curBoard[fp->pieces[i]->col][fp->pieces[i]->row] = fp->pieces[i]->name;
        
    }

    for(int i=0; i < sp->pieces.size(); i++){
        curBoard[sp->pieces[i]->col][sp->pieces[i]->row] = sp->pieces[i]->name;

    }
}


bool Board::checkBoard(Board *board){
    //implement that neither king is already in check
    int whiteKingCount = 0;
    int blackKingCount = 0;
    int y = 0;
    for (int x = 1; x < 7; ++x){
        if (board->curBoard[x][y] == 'k'){
            blackKingCount++;
        }
        else if (board->curBoard[x][y] == 'K'){
            whiteKingCount++;
        }
        else if (board->curBoard[x][y] == 'p' || board->curBoard[x][y] == 'P'){
            return false;
        }
    }

    for (y = 1; y < 7; ++y){
        for (int x = 1; x < 7; ++x){
            if (board->curBoard[x][y] == 'k'){
                blackKingCount++;
            }
            else if (board->curBoard[x][y] == 'K'){
                whiteKingCount++;
            }
        }
    }

    y = 7;
    for (int x = 1; x < 7; ++x){
        if (board->curBoard[x][y] == 'k'){
            blackKingCount++;
        }
        else if (board->curBoard[x][y] == 'K'){
            whiteKingCount++;
        }
        else if (board->curBoard[x][y] == 'p' || board->curBoard[x][y] == 'P'){
            return false;
        }
    }

    if (blackKingCount != 1 || whiteKingCount != 1){
        return false;
    }
    return true;
}


void Board::setup(){
    string s;
    istringstream ss(s);

    while (cin >> s){
        if (s == "+"){ //add a piece

        //add the piece to the players list of pieces 
            cin >> s;
            char c = s[0];
            cin >> s;
            int x = s[0] - 97;
            int y = abs(s[1] - 48 - 1 - 7);
            this->curBoard[x][y] = c;

            cout << this << endl;

        }
        else if (s == "-"){ //remove a piece

        //remove the piece to the palyers list of pieces
            cin >> s;
            int x = s[0] - 97;
            int y = abs(s[1] - 48 - 1 - 7);
            if (this->curBoard[x][y] != '*'){
                this->curBoard[x][y] = '*';
                cout << this << endl;
            }
            
        }
        
        else if (s == "="){//change who starts the game
            cin >> s;
            if (s != "white" && s != "black"){
                cout << "Invalid choice. " "Please enter one of: \"black\" or \"white\"" << endl;
            }
            else{
            this->whichTurn = s[0];
            cout << this->whichTurn << endl;
            }

        }
        else if (s == "done"){ //main menu
            if (checkBoard(this) == false){
                cout << "BOARD IS INVALID, PLEASE CREATE A VALID BOARD" << endl;
            }
            else{
                cout << "MAIN MENU" << endl;
            return;
            }
        }
        else{
            cout << "Invalid Command" << endl;
        }
    }
}





void Board::game(Player* fp,Player* sp){
    string s;
    istringstream ss();

    while (cin >> s){
        if (s == "resign"){
            cout << "haha noob" << endl;
            //end game and dispaly scores
            return;
        }
        else if (s == "move"){
            cout << "Player "<<whichTurn<<" Turn"<< endl;
            
            string initPos; //take in our two positions
            string finalPos;
            cin >> initPos;
            cin >> finalPos;
                /*this->curBoard[x2][y2] = this->curBoard[x1][y1]; //this is the swap.
                this->curBoard[x1][y1] = '*';*/
                
            if (whichTurn == 'w'){
                fp->curCol = initPos[0] - 97; //converting using ASCII
                fp->curRow = abs(initPos[1] - 48 - 1 - 7); //subtract 1 to get arrary coords then subtract 7 to invert to correct space.
                fp->nextCol = finalPos[0] - 97; 
                fp->nextRow = abs(finalPos[1] - 48 - 1 - 7);
                if(fp->canMove()){
                    fp->move();
                    this->move(fp,sp);
                    cout << this << endl; //output the board
                    whichTurn = 'b';
                }else{
                    cout << this << endl; //output the board
                    cout << "INVALID COMMAND (still player1(w) turn)" << endl;
                }
                        
            }else{
                sp->curCol = initPos[0] - 97; //converting using ASCII
                sp->curRow = abs(initPos[1] - 48 - 1 - 7); //subtract 1 to get arrary coords then subtract 7 to invert to correct space.
                sp->nextCol = finalPos[0] - 97; 
                sp->nextRow = abs(finalPos[1] - 48 - 1 - 7);
                if(sp->canMove()){
                    
                    sp->move();
                    this->move(fp,sp);
                    cout << this << endl; //output the board
                    whichTurn = 'w';
                }else{
                    cout << this << endl; //output the board
                    cout << "INVALID COMMAND (still player2(b) turn)" << endl;
                }
                        
            }
                    
        }
                
                
            
    }
        
}
