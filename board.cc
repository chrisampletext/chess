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




