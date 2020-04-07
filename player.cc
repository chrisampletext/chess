#include "player.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <utility>

using namespace std;


Player::~Player(){

}

void Player::start(){
    pieces.push_back('r');
    pieces.push_back('b');
    pieces.push_back('n');
    pieces.push_back('k');
    pieces.push_back('q');
    pieces.push_back('n');
    pieces.push_back('b');
    pieces.push_back('r');
        for(int y =0; y<8; y++){
            pieces.push_back('p');
        }
    
}