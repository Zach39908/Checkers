#include "menu.h"

using namespace std;

gameMenu::gameMenu() {
    p1.Options.push_back("Play Game");
    p1.Options.push_back("Save Game");
    p1.Options.push_back("Directions");
    p1.Options.push_back("Personal Stats");
    p1.Options.push_back("Quit");

    p1.Select[0] = 1;
    p1.Select[1] = 2;
    p1.Select[2] = 3;
    p1.Select[3] = 4;
    p1.Select[4] = 5;
}

int gameMenu::Interface() {
    int userEntry;

    title();

    while(!inputCheck(userEntry)) {
        for(unsigned int i = 0; i < p1.Options.size(); i++)
            cout << "(" << i + 1 << ")\t" << p1.Options[i] << "." << endl;

        cout << endl << "Enter an option (number): "; cin >> userEntry;
        cout << endl;

        if(isdigit(userEntry) == 0) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    return userEntry;
}

void gameMenu::title() {
    cout << endl;
    cout << "XOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOS" << endl;
    cout << "X                                                                                  O" << endl;
    cout << "X      /`````  |     |   |`````    /`````   |   /   |`````   |```\\    /```   |     O" << endl;
    cout << "X     /        |     |   |        /         | /`    |        |   /   /       |     O" << endl;
    cout << "X     |        |_____|   |___     |         /`      |___     |__/    \\__     |     O" << endl;
    cout << "X     |        |     |   |        |         \\_      |        |  \\       \\    |     O" << endl;
    cout << "X     \\        |     |   |        \\         | \\_    |        |   |       |         O" << endl;
    cout << "X      \\____   |     |   |_____    \\_____   |   \\   |_____   |   |   ___/    0     O" << endl;
    cout << "X                                                                                  O" << endl;
    cout << "XOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXO" << endl;
    cout << endl;
}

bool gameMenu::inputCheck(int entry) {
    for(unsigned int i = 0; i < p1.Options.size(); i++) {
        if(entry == p1.Select[i])
            return true;
    }

    return false;
}

void gameMenu::saveGame(gameBoard activeBoard) {
    ofstream writeFile;
    ifstream readFile;
    string choice;
    bool valid = false;

    readFile.open("save.txt");

    if(!readFile.good()) {
        cout << "Creating Game Save File..." << endl;
        writeFile.open("save.txt", ios_base::trunc);
        activeBoard.writeToFile(writeFile);
        cout << "Game Saved in \"save.txt\"" << endl;
    }
    else {
        while(valid == false) {
            try {
                cout << "This will overwrite the previous save. Are you sure you want to continue? (\"yes\" or \"no\"): "; cin >> choice;

                if(choice == "yes" || choice == "Yes" || choice == "YES") {
                    writeFile.open("save.txt", ios_base::trunc);
                    activeBoard.writeToFile(writeFile);
                    cout << "Game Save Overwritten in \"save.txt\"" << endl;
                    valid = true;
                }
                else if(choice == "no" || choice == "No" || choice == "NO") {
                    cout << "Returning to Main Menu..." << endl;
                    valid = true;
                    return;
                }
                else
                    throw inputExc("Error: Invalid Choice.");
            }
            catch(inputExc &error) {
                cout << error.what() << endl;
                cout << "Try Again." << endl;
                valid = false;
            }
        }
    }

    writeFile.close();
    readFile.close();
}