#ifndef H_BOARD
#define H_BOARD

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "exception.h"

using namespace std;

const int ROWS = 8, COLS = 8, BOX_WIDTH = 14, ROW_AMOUNT = 5;   // ROW_AMOUNT is the amount of "row" strings per-"boardRow.".      

class gameBoard {
    vector<vector<string>> board;
    vector<string> boardRow;     
    string row1, row2, row3, row4, row5;    // Each row string is one individual row of the larger hierarchy vector "boardRow."

    vector<string> eBox = {                // eBox = emptyBox       - Different types of game pieces
        "|~~~~~~~~~~~~|",
        "|            |",
        "|            |",
        "|            |",
        "|~~~~~~~~~~~~|"
    };
    vector<string> cBox = {                // cBox = colorBox
        "|~~~~~~~~~~~~|",
        "|------------|",
        "|------------|",
        "|------------|",
        "|~~~~~~~~~~~~|"
    };
    vector<string> xBox = {                // xBox = X player's piece ('X' pieces are the AI's pieces)
        "|~~~~~~~~~~~~|",
        "|    \\ /     |",
        "|     x      |",
        "|    / \\     |",
        "|~~~~~~~~~~~~|"
    };
    vector<string> oBox = {                // oBox = O player's piece ('O' pieces are the Player's pieces)
        "|~~~~~~~~~~~~|",
        "|    /``\\    |",
        "|   |    |   |",
        "|    \\__/    |",
        "|~~~~~~~~~~~~|"
    };
    vector<string> xqBox = {               // xqBox = 'X' player's Queen piece (AI's queen piece)
        "|~~~~~~~~~~~~|",
        "|    /``\\    |",
        "| X  \\__/  X |",
        "|       \\    |",
        "|~~~~~~~~~~~~|"
    };
    vector<string> oqBox = {               // oqBox = 'O' player's Queen piece (Player's queen piece)
        "|~~~~~~~~~~~~|",
        "|    /``\\    |",
        "| O  \\__/  O |",
        "|       \\    |",
        "|~~~~~~~~~~~~|"
    };
public:                                     // Hierarchy = board -> boardRow -> row#
    gameBoard();
    void displayBoard();
    void changeBox(int, int, string);
    void defaultBoard();
    void writeToFile(ofstream&);

    friend class player;
};

#endif