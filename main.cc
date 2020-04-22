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
            b->setup(fp,sp);
        }
        else if (s == "game"){

            //setting up human/bot matchup
            string inp1;
            string inp2;
            cin >> inp1;
            inp1 = b->checkString(inp1);
            cin >> inp2;
            inp2 = b->checkString(inp2);
            if (((inp1 == "human") || (inp1 == "computer")) &&
                ((inp2 == "human") || (inp2 == "computer"))){
                if (inp1 == "human"){
                    cout << "white-player is human" << endl;
                    fp->bot = false;
                }
                else{
                    //start the computer
                    if (inp1 == "computer"){
                    cout << "white-player is "<< inp2 << endl;
                    fp->bot = true;
                    }
                    else{
                        cout << "Invalid Command." << endl;
                    }
                }
                if (inp2 == "human"){
                    cout << "black-player is human" << endl;
                    sp->bot = false;
                }
                else{
                    //start the computer
                    if (inp2 == "computer"){
                    cout << "black-player is "<< inp2 << endl;
                    sp->bot = true;
                    }
                    else{
                        cout << "Invalid Command." << endl;
                    }
                }
                cout << "Beginning the game... good luck and have fun!!" << endl;
              
                b->game(fp,sp);
                whiteWin = b->whiteWin;
                blackWin = b->blackWin;
              
                fp->restart();
                sp->restart();
                b->reset(fp,sp);
            }
            else{
                cout << "Invalid Command, please use one of: human or computer" <<endl;
            }
        }
        else{
            cout << "Invalid Command, please use one of: game or setup." << endl;
        }
    }
    cout << "Final Score:" <<endl;
    cout << "White: " << whiteWin << endl;
    cout << "Black: " << blackWin << endl;
    delete fp;
    delete sp;
    delete b;

}