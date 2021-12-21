#ifndef H_PLAYER
#define H_PLAYER

#include<memory>
#include "board.h"

using namespace std;

class player {
protected:
    shared_ptr<gameBoard> currGame;

public:
    player(shared_ptr<gameBoard>);
    virtual void makeAMove() = 0;
    void setQueen();
    void setupTurn();
    bool validMove();
    bool winner();
    int validPiece(char,int);
    ~player();
};

class AI : public player {
public:
    AI(shared_ptr<gameBoard>);
    virtual void makeAMove();
};

class User : public player {
public:
    User(shared_ptr<gameBoard>);
    virtual void makeAMove();
};

#endif