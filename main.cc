#include <iostream>
#include "board.h"

using namespace std;

ostream& operator<<(ostream& out, Board* board){
    for(int x = 0; x<8; x++){
        for(int y =0; y<8; y++){
            out<<board->curBoard[x][y];
        }
        out<<endl;
    }

    return out;

}


int main() {

    Board *b = new Board;
    b->start();
    cout<<b;
    

    delete b;

}