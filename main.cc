#include <iostream>
#include "board.h"
#include "piece.h"
#include "player.h"

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


int main() {
    Player *fp = new Player;
    Player *sp = new Player;
    fp->number = 1;
    sp->number = 2;
    fp->start();
    sp->start();
    fp->opponent = sp;
    sp ->opponent = fp;
    Board *b = new Board(fp,sp);
    cout<<b<<endl;
    //test case 1: valid move
    fp->curCol = 0;
    fp->curRow = 1;
    fp->nextCol = 0;
    fp->nextRow = 3;
    fp->move();
    b->move(fp,sp);
    cout<<b;

    //test 2: invalid move
    sp->curCol = 6;
    sp->curRow = 6;
    sp->nextCol = 5;
    sp->nextRow = 6;
    sp->move();
    b->move(fp,sp);
    cout<<b;

    //test 2: invalid move
    sp->curCol = 6;
    sp->curRow = 6;
    sp->nextCol = 6;
    sp->nextRow = 5;
    sp->move();
    b->move(fp,sp);
    cout<<b;
    delete fp;
    delete sp;
    delete b;

}