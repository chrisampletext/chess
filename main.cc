#include <iostream>
#include <sstream>
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

/*
// Read and update Board object during setup.
istream &operator>>(istream &in, Board *&board){
    while (in >> s){
        istringstream ss(s);
        if (s == "+"){
            //place/replace piece on board
            // print out board after
        }
        else if (s == "-"){
            // removes piece from board
            // print out board after
            // if no piece do nothing
        }
        else if (s == "colour"){
            // set "colour" to go next
        }
        else if (s == "done"){

        }
        else{

        }
    }
}
*/

int main() {

    Board *b = new Board;
    b->start();
    cout<<b; //checker

    string s;

    // Command Interpreter
    while (cin >> s){
        if (s == "setup" ){
            //run the setup for the board
            b->setup();
        }
        else if (s == "game"){
            // "game white-player black-player" for final version
            cout<<b;
            b->game();
            return;
        }
    }
    

    delete b;

}