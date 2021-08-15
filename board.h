#include <iostream>
#include <string>
#include <vector>

#include "exception.h"

using namespace std;

const int ROWS = 8, COLS = 8, BOX_WIDTH = 14, ROW_AMOUNT = 5;       // ROW_AMOUNT is the amount of "row" strings per-"boardRow" (row1, row2, row3, row4 ,row5).      

class gameBoard {
    vector<vector<string>> board;
    vector<string> eBox, xBox, oBox, qBox, boardRow;
    string row1, row2, row3, row4, row5;
public:
    gameBoard();
    void displayBoard();
    void changeBox(int, int, char);
    void defaultBoard();
};