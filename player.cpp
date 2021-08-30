#include "player.h"

using namespace std;

player::player(gameBoard &current) {
    currGame = &current;
}

player::~player() {
    delete currGame;
    currGame = NULL;
}

void player::setQueen() {

}

void player::setupTurn() {

}

bool player::winner() {

}

void User::makeAMove() {

}

void AI::makeAMove() {
    
}