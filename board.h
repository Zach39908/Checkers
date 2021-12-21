#ifndef H_BOARD
#define H_BOARD

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "exception.h"

using namespace std;

const int ROWS = 8, COLS = 8, BOX_WIDTH = 14, ROW_AMOUNT = 5;   

class gameBoard {
    vector<vector<string>> board;
    vector<string> boardRow;     
    string row1, row2, row3, row4, row5;    

    vector<string> emptyBox = {                    
        "|~~~~~~~~~~~~|",
        "|            |",
        "|            |",
        "|            |",
        "|~~~~~~~~~~~~|"
    };
    vector<string> filledBox = {                
        "|~~~~~~~~~~~~|",
        "|------------|",
        "|------------|",
        "|------------|",
        "|~~~~~~~~~~~~|"
    };
    vector<string> xBox = {                
        "|~~~~~~~~~~~~|",
        "|    \\ /     |",
        "|     x      |",
        "|    / \\     |",
        "|~~~~~~~~~~~~|"
    };
    vector<string> oBox = {                
        "|~~~~~~~~~~~~|",
        "|    /``\\    |",
        "|   |    |   |",
        "|    \\__/    |",
        "|~~~~~~~~~~~~|"
    };
    vector<string> xKingBox = {               
        "|~~~~~~~~~~~~|",
        "|     | /     |",
        "| X   |/    X |",
        "|     | \\     |",
        "|~~~~~~~~~~~~|"
    };
    vector<string> oKingBox = {               
        "|~~~~~~~~~~~~|",
        "|     | /     |",
        "| O   |/    O |",
        "|     | \\     |",
        "|~~~~~~~~~~~~|"
    };
    
public:                                     
    gameBoard();
    void displayBoard();
    void changeBox(int, int, string);
    void defaultBoard();
    void writeToFile(ofstream&);

    friend class player;
};

#endif