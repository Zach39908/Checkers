#include "menu.h"

using namespace std;

gameMenu::gameMenu() {
    Options.push_back("Play Game");
    Options.push_back("Save Game");
    Options.push_back("Directions");
    Options.push_back("Personal Stats");
    Options.push_back("Quit");

    Select[0] = 1;
    Select[1] = 2;
    Select[2] = 3;
    Select[3] = 4;
    Select[4] = 5;
}

void gameMenu::Interface() {
    title();

    for(unsigned int i = 0; i < Options.size(); i++)
        cout << "(" << i + 1 << ")\t" << Options[i] << endl;

    cout << endl; 
}

void gameMenu::title() {
    cout << endl;
    cout << "XOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXO" << endl;
    cout << "X                                                                              O" << endl;
    cout << "X      /`````  |     |   |`````    /`````   |   /   |`````   |````/   /```     O" << endl;
    cout << "X     /        |     |   |        /         | /`    |        |   /   /         O" << endl;
    cout << "X     |        |_____|   |___     |         /`      |___     |__/    \\__       O" << endl;
    cout << "X     |        |     |   |        |         \\_      |        |  \\       \\      O" << endl;
    cout << "X     \\        |     |   |        \\         | \\_    |        |   |       |     O" << endl;
    cout << "X      \\____   |     |   |_____    \\_____   |   \\   |_____   |   |   ___/      O" << endl;
    cout << "X                                                                              O" << endl;
    cout << "XOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXO" << endl;
    cout << endl;
}

int main() {
    gameMenu g1;
    g1.Interface();
}