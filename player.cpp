#include "player.h"

using namespace std;

player::player(shared_ptr<gameBoard> current) {
    currGame = current;
}

player::~player() {

}

void player::setQueen() {

}

void player::setupTurn() {
    makeAMove();
}

bool player::winner() {
    return 1;
}

User::User(shared_ptr<gameBoard> current) : player(current) {}

void User::makeAMove() {
    currGame->changeBox(1,2,"xq");
    currGame->displayBoard();
}

AI::AI(shared_ptr<gameBoard> current) : player(current) {}

void AI::makeAMove() {
    
}