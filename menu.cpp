#include "menu.h"

using namespace std;

gameMenu::gameMenu() {
    Options[0] = "Play Game";
    Options[1] = "Save Game";
    Options[2] = "Directions";
    Options[3] = "Mutliplayer Mode";
    Options[4] = "Quit";

    Select[0] = 'P';
    Select[1] = 'p';
    Select[2] = 'S';
    Select[3] = 's';
    Select[4] = 'D';
    Select[5] = 'd';
    Select[6] = 'M';
    Select[7] = 'm';
    Select[8] = 'Q';
    Select[9] = 'q';
}

void gameMenu::Interface() {
    
}