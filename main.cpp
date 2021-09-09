#include "menu.h"

using namespace std;

int main() {
    gameMenu activeMenu;
    shared_ptr<gameBoard> activeBoard(new gameBoard);
    int path;
    bool exit = 0, title = 1;

    while(exit == 0) {
        path = activeMenu.Interface(title);

        if(path == 1) {
            User u1(activeBoard);
            u1.setupTurn();
            cout << "Game functionality coming soon..." << endl << endl;
        }
        else if(path == 2) {
            activeMenu.saveGame(*activeBoard);
        }
        else if(path == 3) {
            cout << "Directions coming soon..." << endl;
        }
        else if(path == 4) {
            cout << "Personal Stats coming soon..." << endl;
        }
        else if(path == 5) {
            cout << "Quitting Checkers..." << endl;
            exit = 1;
        }

        title = 0;
    }
}