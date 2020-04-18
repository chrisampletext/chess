#include <iostream>
#include <sstream>
#include "board.h"
#include "piece.h"
#include "player.h"

using namespace std;


int main() {

    int whiteWin = 0;
    int blackWin = 0;
    Player *fp = new Player(1);
    Player *sp = new Player(2);
    fp->start();
    sp->start();
    fp->opponent = sp;
    sp ->opponent = fp;
    fp->opponent->opponent = fp;
    sp->opponent->opponent = sp;
    Board *b = new Board(fp,sp);

    string s;

    while (cin >> s){
        s = b->checkString(s);
        if (s == "setup"){
            cout << "SETUP MODE" << endl;
            b->setup();
        }
        else if (s == "game"){

            //setting up human/bot matchup
            string inp1;
            string inp2;
            cin >> inp1;
            inp1 = b->checkString(inp1);
            cin >> inp2;
            inp2 = b->checkString(inp2);
            if (((inp1 == "human") || (inp1 == "computer[1]")|| (inp1 == "computer[2]")|| (inp1 == "computer[3]")) &&
                ((inp2 == "human") || (inp2 == "computer[1]")|| (inp2 == "computer[2]")|| (inp2 == "computer[3]"))){
                if (inp1 == "human"){
                    cout << "white-player is human" << endl;
                }
                else{
                    cout << "white-player is "<< inp2 << endl;
                    //start the computer
                    if (inp1 == "computer[1]"){
                    }
                    else if(inp1 == "computer[2]"){
                    }
                    else if(inp1 == "computer[3]"){
                    }
                    else{
                    }
                }
                if (inp2 == "human"){
                    cout << "black-player is human" << endl;
                }
                else{
                    cout << "black-player is "<< inp2 << endl;
                    //start the computer
                    if (inp2 == "computer[1]"){
                    }
                    else if(inp2 == "computer[2]"){
                    }
                    else if(inp2 == "computer[3]"){
                    }
                    else{
                    }
                }
                cout << "Beginning the game... good luck have fun!!" << endl;
                b->game(fp,sp);
                whiteWin = b->whiteWin;
                blackWin = b->blackWin;
                //reset the players boards below
            }
            else{
                cout << "Invalid Command" <<endl;
            }
        }
        else{
            cout << "Invalid Command." << endl;
        }
    }
    cout << "Final Score:" <<endl;
    cout << "White: " << whiteWin << endl;
    cout << "Black: " << blackWin << endl;
    delete fp;
    delete sp;
    delete b;

}