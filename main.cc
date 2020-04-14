#include <iostream>
#include <sstream>
#include "board.h"
#include "piece.h"
#include "player.h"

using namespace std;


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

    string s;

    while (cin >> s){
        if (s == "setup"){
            cout << "SETUP MODE" << endl;
            b->setup();
        }
        else if (s == "kill"){
            break;
        }
        else if (s == "game"){
            cout << "BEGINNING GAME.... GOOD LUCK HAVE FUN" << endl;
            b->game(fp,sp);
            break;
        }
        else{
            cout << "INVALID COMMAND" << endl;
        }
    }

    delete fp;
    delete sp;
    delete b;




    /*
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
    */

}