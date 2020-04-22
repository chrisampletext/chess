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


std::string Board::checkString(const std::string &s){
    string loFiles[9] = { "move.txt", "game.txt", "setup.txt", "done.txt", "human.txt",
    "black.txt", "white.txt", "resign.txt", "computer.txt" };
    for (int i = 0; i < 9; i++){
        ifstream file(loFiles[i]);
        string curWord;
        string potWord;
        file >> potWord;
        while(file >> curWord){
            if (curWord == s){
                file.close();
                return potWord;
            
            }
        }
        file.close();
    }
    return s;
}


void Board::reset(Player* fp,Player* sp){
        for(int x = 0; x<8; x++){
        for(int y =0; y<8; y++){
            curBoard[x][y]='*';
        }
    }
    //set first and second
    for (int x=0;x<8;x++){
        curBoard[x][0] = sp->pieces[x]->name;
        curBoard[x][1] = sp->pieces[x+8]->name;
        curBoard[x][6] = fp->pieces[x+8]->name;
        curBoard[x][7] = fp->pieces[x]->name;
    }
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
        curBoard[x][0] = sp->pieces[x]->name;
        curBoard[x][1] = sp->pieces[x+8]->name;
        curBoard[x][6] = fp->pieces[x+8]->name;
        curBoard[x][7] = fp->pieces[x]->name;
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

bool Board::checkBoard(Board *board){
    //implement that neither king is already in check
    int whiteKingCount = 0;
    int blackKingCount = 0;
    int y = 0;
    for (int x =0; x < 8; ++x){
        if (board->curBoard[x][y] == 'p' || board->curBoard[x][y] == 'P'){
            return false;
        }
    }

    for (y = 0; y < 8; ++y){
        for (int x = 0; x < 8; ++x){
            if (board->curBoard[x][y] == 'k'){
                blackKingCount++;
            }
            else if (board->curBoard[x][y] == 'K'){
                whiteKingCount++;
            }
        }
    }

    y = 7;
    for (int x = 0; x < 8; ++x){
        if (board->curBoard[x][y] == 'p' || board->curBoard[x][y] == 'P'){
            return false;
        }
    }

    if (blackKingCount != 1 || whiteKingCount != 1){
        return false;
    }
    return true;
}

void Board::setup(Player* fp,Player* sp){
    
    string s;
    istringstream ss(s);

    while (cin >> s){
        s = checkString(s);
        if (s == "+"){ //add a piece
    
        //add the piece to the players list of pieces 
            cin >> s;
            char c = s[0];
            cin >> s;
            int x = s[0] - 97;
            int y = abs(s[1] - 48 - 1 - 7);
            this->curBoard[x][y] = c;
            cout<<this<<endl;

            //check if the coordinates are valid
            if (x > 7 || x < 0 || y > 7 || y < 0){
                cout << "The coordinates you have entered does not exist on this board." << endl;
            }

            else{
                if(c == 'r'){ 
                    fp->pieces.push_back(new Rook(x, y, 'r'));
                }else if(c == 'R'){ 
                    sp->pieces.push_back(new Rook(x, y, 'R'));
                }else if(c == 'n'){ 
                    fp->pieces.push_back(new Knight(x, y, 'n'));
                }else if(c == 'N'){ 
                    sp->pieces.push_back(new Knight(x, y, 'N'));
                }else if(c == 'k'){ 
                    fp->pieces.push_back(new King(x, y, 'k'));
                }else if(c == 'K'){ 
                    sp->pieces.push_back(new King(x, y, 'K'));
                }else if(c == 'q'){ 
                    fp->pieces.push_back(new Queen(x, y, 'q'));
                }else if(c == 'Q'){ 
                    sp->pieces.push_back(new Queen(x, y, 'Q'));
                }else if(c == 'p'){ 
                    fp->pieces.push_back(new Pawn(x, y, 'p'));
                }else if(c == 'P'){ 
                    sp->pieces.push_back(new Pawn(x, y, 'P'));
                }
                else{
                    cout << "The piece you have specified does not exist, please add a valid piece." << endl;
                }
            }         
        }
        else if (s == "-"){ //remove a piece

        //remove the piece to the palyers list of pieces
            cin >> s;
            int x = s[0] - 97;
            int y = abs(s[1] - 48 - 1 - 7);
            
            fp->curCol = x;
            fp->curRow = y;
            sp->curCol = x;
            sp->curRow = y;
            if (x > 7 || x < 0 || y > 7 || y < 0){
                cout << "The coordinates you have entered does not exist on this board." << endl;
            }
            else{
                if(fp->getPiece() != -1){
                    fp->pieces.erase(fp->pieces.begin()+fp->getPiece());
                    this->curBoard[x][y] = '*';
                    cout << this << endl;
                }else if(sp->getPiece() != -1){
                    sp->pieces.erase(sp->pieces.begin()+sp->getPiece());
                    this->curBoard[x][y] = '*';
                    cout << this << endl;
                }
                else{
                    cout << "There was no piece located at: " << s << endl;
                }
            }
        }
        
        else if (s == "="){//change who starts the game 
            cin >> s;
            s = checkString(s);
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
                cout << "The board is currently invalid, you must have a valid board before playing." << endl;
            }
            else{
                cout << "MAIN MENU" << endl;
            
            return;
            }
        }
        else{
            cout << "Invalid Command." << endl;
        }
    }
}


void Board::game(Player* fp,Player* sp){
    cout<<this<<endl;
    string s;
    istringstream ss();

    while (cin >> s){
        s = checkString(s);
        if (s == "resign"){
            if (whichTurn == 'b'){
                cout << "White wins!" << endl;
                whiteWin++;
            }
            else{
                cout << "Black wins!" << endl;
                blackWin++;
            }
            return;
        }
        else if (s == "move"){  
            if (whichTurn == 'w' && fp->bot == true){
                fp->botMove(1);
                this->move(fp,sp);
                cout << this << endl;
                if (fp->isCheck()){
                        if(fp->isCheckMate()){
                            cout<<"Checkmate! "<<"Black"<<" wins!"<<endl;
                            blackWin++;
                            return;
                        }else{
                            cout<<"White"<<" is in check."<<endl;
                    }
                }
                whichTurn = 'b';
            }
            else if (whichTurn == 'b' && sp->bot == true){
                sp->botMove(1);
                this->move(fp,sp);
                cout << this << endl;
                if (fp->isCheck()){
                        if(fp->isCheckMate()){
                            cout<<"Checkmate! "<<"White"<<" wins!"<<endl;
                            whiteWin++;
                            return;
                        }else{
                            cout<<"Black"<<" is in check."<<endl;
                    }
                }
                whichTurn = 'w';
            }
            else{


            string initPos; //take in our two positions
            string finalPos;
            cin >> initPos;
            cin >> finalPos;
            int x1 = initPos[0] - 97;//converting using ASCII
            int y1 = abs(initPos[1] - 48 - 1 - 7);//subtract 1 to get arrary coords then subtract 7 to invert to correct space.
            int x2 = finalPos[0] - 97; 
            int y2 = abs(finalPos[1] - 48 - 1 - 7);
            
            if (x1 > 7 || x1 < 0 || y1 > 7 || y1 < 0 || x2 > 7 || x2 < 0 || y2 > 7 || y2 < 0){
                cout << "The coordinates you have entered does not exist on this board, please enter valid coordinates." << endl;
            }
            else{  
            if (whichTurn == 'w'){
                fp->curCol = initPos[0] - 97; 
                fp->curRow = abs(initPos[1] - 48 - 1 - 7); 
                fp->nextCol = finalPos[0] - 97; 
                fp->nextRow = abs(finalPos[1] - 48 - 1 - 7);
                if(fp->canMove()){
                    fp->move();
                    this->move(fp,sp);
                    cout << this << endl; //output the board
                    if(fp->isCheck()){
                        if(fp->isCheckMate()){
                            cout<<"Checkmate! "<<"Black"<<" wins!"<<endl;
                            whiteWin++;
                            return;
                        }else{
                            cout<<"White"<<" is in check."<<endl;
                        }
                    }  
                    whichTurn = 'b';
                }
                else{
                    cout << this << endl; //output the board
                    cout << "Your command is invalid, please enter a valid command for White." << endl;
                }             
            }
            else{
                sp->curCol = initPos[0] - 97; //converting using ASCII
                sp->curRow = abs(initPos[1] - 48 - 1 - 7); //subtract 1 to get arrary coords then subtract 7 to invert to correct space.
                sp->nextCol = finalPos[0] - 97; 
                sp->nextRow = abs(finalPos[1] - 48 - 1 - 7);
                if(sp->canMove()){
                    
                    sp->move();
                    this->move(fp,sp);
                    cout << this << endl; //output the board
                    
                    if(sp->isCheck()){
                        if(sp->isCheckMate()){
                            cout<<"Checkmate! "<<"White"<<" wins!"<<endl;
                            blackWin++;
                            return;
                        }else{
                            cout<<"Black"<<" is in check."<<endl;
                        }
                    }   
                whichTurn = 'w';
                }
                else{
                    cout << this << endl; //output the board
                    cout << "Your command is invalid, please enter a valid command for Black." << endl;
                }         
            }
        }                      
    }
        }
        else{
            cout << "Invalid Command." << endl;
        } 
    }
}
