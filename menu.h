#ifndef H_MENU
#define H_MENU

#include "player.h"
 
 using namespace std;

class gameMenu {
    struct Properties{
        vector<string> Options;
        int Select[5];
    };

    Properties p1;
public:
    gameMenu();
    int Interface();
    void title();
    bool inputCheck(int);
    void saveGame(gameBoard);
};

#endif