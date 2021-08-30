#ifndef H_PLAYER
#define H_PLAYER

#include "board.h"

using namespace std;

class player {
protected:
    gameBoard *currGame;

public:
    player(gameBoard&);
    virtual void makeAMove() = 0;
    void setQueen();
    void setupTurn();
    bool winner();
    ~player();
};

class AI : public player {
public:
    virtual void makeAMove();
};

class User : public player {
public:
    virtual void makeAMove();
};

#endif