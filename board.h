#include <iostream>
#include <string>
#include <vector>

#include "exception.h"

using namespace std;

const int ROWS = 8, COLS = 8, BOX_WIDTH = 14, ROW_AMOUNT = 5;   // ROW_AMOUNT is the amount of "row" strings per-"boardRow.".      

class gameBoard {
    vector<vector<string>> board;
    vector<string> eBox, cBox, xBox, oBox, xqBox, oqBox, boardRow;     // These are the different types of boxes/pieces in the game.
    string row1, row2, row3, row4, row5;    // Each row string is one individual row of the larger hierarchy vector "boardRow."
public:                                     // Hierarchy = board -> boardRow -> row#
    gameBoard();
    void displayBoard();
    void changeBox(int, int, char);
    void defaultBoard();
};