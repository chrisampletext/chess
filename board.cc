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
    string loFiles[12] = { "move.txt", "game.txt", "setup.txt", "done.txt", "human.txt",
    "black.txt", "white.txt", "resign.txt", "computer[1].txt", "computer[2].txt",
    "computer[3].txt", "computer[4].txt" };
    for (int i = 0; i < 12; i++){
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
            cout<<"x: "<<x<<" y: "<<y<<endl;
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
            cout<<"x: "<<x<<" y: "<<y<<endl;
            return false;
        }
    }

    if (blackKingCount != 1 || whiteKingCount != 1){
        cout<<blackKingCount<<endl;
        cout<<whiteKingCount<<endl;
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

        }
        else if (s == "-"){ //remove a piece

        //remove the piece to the palyers list of pieces
            cin >> s;
            int x = s[0] - 97;
            int y = abs(s[1] - 48 - 1 - 7);
            int curCol = x;
            int curRow = y;
            
            fp->curCol = x;
            fp->curRow = y;
            sp->curCol = x;
            sp->curRow = y;
            if(fp->getPiece() != -1){
                fp->pieces.erase(fp->pieces.begin()+fp->getPiece());
            }else if(sp->getPiece() != -1){
                sp->pieces.erase(sp->pieces.begin()+sp->getPiece());
            }
            if (this->curBoard[x][y] != '*'){
                this->curBoard[x][y] = '*';
               
            }

            cout << this << endl;
            
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
                cout << "BOARD IS INVALID, PLEASE CREATE A VALID BOARD" << endl;
            }
            else{
                cout << "MAIN MENU" << endl;
            
            return;
            }
        }
        else{
            cout << "Invalid Command" << endl;
        }
    }
}


void Board::game(Player* fp,Player* sp){
    cout<<this<<endl;
      for(int i =0; i< fp->pieces.size(); i++){
          cout<<fp->pieces[i]->col<<",";
            cout<<fp->pieces[i]->row<<" "<<fp->pieces[i]->name<<endl;
            
        }
        cout<<endl;
        for(int i =0; i< sp->pieces.size(); i++){
            cout<<sp->pieces[i]->col<<",";
            cout<<sp->pieces[i]->row<<" "<<sp->pieces[i]->name<<endl;;
            
                
        }
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
            
            //cout << "Player "<<whichTurn<<" Turn"<< endl;
            
            string initPos; //take in our two positions
            string finalPos;
            cin >> initPos;
            cin >> finalPos;
                /*this->curBoard[x2][y2] = this->curBoard[x1][y1]; //this is the swap.
                this->curBoard[x1][y1] = '*';*/
                
            if (whichTurn == 'w'){
                char otherTurn = 'b';
                fp->curCol = initPos[0] - 97; //converting using ASCII
                fp->curRow = abs(initPos[1] - 48 - 1 - 7); //subtract 1 to get arrary coords then subtract 7 to invert to correct space.
                fp->nextCol = finalPos[0] - 97; 
                fp->nextRow = abs(finalPos[1] - 48 - 1 - 7);
                if(fp->canMove()){

                    //check if the move was to the end of the board
                    // if it was a pawn then promote
                    // then run the following code on the newly constructed piece



                    //check if white is in check
                    //if white is in check and the move does not get them away from check
                    //cout Invalid move, White King is in check.
                    // else execute the move
                    fp->move();
                    this->move(fp,sp);
                    cout << this << endl; //output the board
                    if(fp->isCheck()){
                        if(fp->isCheckMate()){
                            cout<<"checkmate "<<whichTurn<<" wins"<<endl;
                            whiteWin++;
                            return;
                        }else{
                            cout<<otherTurn<<" is in check"<<endl;
                        }
                    }  

                    // check if it has put black in checkmate
                    // if checkmate then output "Checkmate! White wins!"
                    // whiteWin++
                    // else check if has put black in check
                    // if so then print "Black is in check."
                    // otherwise just execute the move and print the board out
                    //cout<<"hello";
                    whichTurn = 'b';


                }
                else{
                    cout << this << endl; //output the board
                    cout << "INVALID COMMAND (still player1(w) turn)" << endl;
                }
                        
            }
            else{
                char otherTurn = 'w';
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
                            cout<<"checkmate "<<whichTurn<<" wins"<<endl;
                            blackWin++;
                            return;
                        }else{
                            cout<<otherTurn<<" is in check"<<endl;
                        }
                    }   
                    whichTurn = 'w';
                }else{
                    cout << this << endl; //output the board
                    cout << "INVALID COMMAND (still player2(b) turn)" << endl;
                }
                        
            }
                    
        }
                
                
            
    }
        
}
