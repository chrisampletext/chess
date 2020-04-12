#include "board.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <utility>

using namespace std;


Board::~Board(){
    for(int i = 0; i < 8; ++i) {
        delete[] curBoard[i];   
    }
    delete fp;
    delete sp;
    delete[] curBoard;
}

void Board::start(){
    curBoard = new char*[8];
    fp = new Player;
    sp = new Player;
    turn = "w";
    fp->start();
    sp->start();
    for(int x = 0; x<8; x++){
        curBoard[x] = new char[8];
        for(int y =0; y<8; y++){
            curBoard[x][y]='*';
        }
    }
    //set first and second
    for (int y=0;y<8;y++){
        curBoard[0][y] = fp->pieces[y];
        curBoard[1][y] = fp->pieces[y+8];
        curBoard[6][y] = sp->pieces[y+8];
        curBoard[7][y] = sp->pieces[y];
    }
}

void Board::movePiece(const int x1y1, const int x2y2){
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    
    x1 = x1y1%10;
    x2 = x2y2%10;
    y1 = x1y1/10;
    y2 = x2y2/10;

    this->curBoard[x2][y2] = this->curBoard[x1][y1];
    this->curBoard[x1][y1] = ' ';

}


void Board::setup(){
    //work on this later
    /*Upon completion of setup mode, you must verify that the board 
    contains exactly one white king and exactly one black king; 
    that no pawns are on the first or last row of the board; 
    and that neither king is in check. 
    The user cannot leave setup mode until these conditions are satisfied. 
    We recommend doing setup mode early, as it may facilitate testing.
    */
}

void Board::game(){
    string s;
    istringstream ss(s);

    while (cin >> s){
        if (s == "resign"){
            cout << "HAH YOU NOOB" << endl;
            //end game
            return;
        }
        else if(s == "move"){
            //checking if its a valid move
            //check if king is in "check"/"checkmate"
            //check if its a pawn promoting


            cout << "this ran" << endl;
            //check
            int initPos;
            int finalPos;
            cin >> initPos;
            cin >> finalPos;
            cout << initPos << "      " << finalPos << endl;
            //check
            movePiece(initPos, finalPos);
            cout << curBoard << endl;

        }
        else{
            
        }
    }
}




