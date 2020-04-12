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
    
    delete[] curBoard;
}

//to start
Board::Board(Player* fp,Player* sp){
    curBoard = new char*[8];

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




