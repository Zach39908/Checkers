#include "board.h"

using namespace std;

// gameBoard() DEFAULT CONSTRUCTOR
gameBoard::gameBoard() {
    
    // Create individual rows for boardRow vector
    for(int i = 0; i < COLS; i++) {     
        row1 += emptyBox[0];                // row1 = first string from emptyBox vector concatenated 8 times
        row2 += emptyBox[1];                // row2 = second string from emptyBox vector concatenated 8 times
        row3 += emptyBox[2];                // row3...
        row4 += emptyBox[3];                // row4...
        row5 += emptyBox[4];                // row5...
    }

    // Add strings row1-row5 to boardRow vector
    boardRow.push_back(row1);           
    boardRow.push_back(row2);           
    boardRow.push_back(row3);
    boardRow.push_back(row4);
    boardRow.push_back(row5);

    // Add 8 boardRows to the board object
    for(int j = 0; j < ROWS; j++) {
        board.push_back(boardRow);      
    }

    // board now contains 8 boardRows of emptyBoxes
    // defaultBoard() will use changeBox() to reassign the board to the default checkers pieces/boxes
    defaultBoard();
}

// defaultBoard() SETS BOARD TO DEFAULT CHECKERS SETUP
void gameBoard::defaultBoard() {

    // Setting first three boardRows to alternating xBoxes
    for(int i = 1; i < ROWS - 4; i++) {                         // loop for boardRows 1-3           
        for(int j = 2; j < COLS + 1; j += 2) {                  
            if(i == 2)                                          // if i = boardRow2, then change boxes in odd columns
                changeBox(i, j - 1, "x");
            else                                                // if i = boardRow1 or boardRow3, then change boxes in even columns
                changeBox(i, j, "x");
        }
    }

    // Setting last three boardRows to alternating oBoxes
    for(int i = ROWS - 2; i < ROWS + 1; i++) {                  // loop for boardRows 6-8
        for(int j = 1; j < COLS + 1; j += 2) {
            if(i == 7)                                          // if i = boardRow7, then change boxes in odd columns
                changeBox(i, j + 1, "o");
            else                                                // if i = boardRow6 or boardRow8, then change boxes in even columns
                changeBox(i, j, "o");
        }
    }

    // Setting all non-playable boxes to filledBoxes
    for(int i = 1; i < ROWS + 1; i++) {                         // loop for boardRows 1-8
        for(int j = 1; j < COLS + 1; j += 2) {      
            if(i % 2 != 0)                                      // for odd rows, change boxes in even columns
                changeBox(i, j, "f");
            else                                                // for even rows, change boxes in odd columns
                changeBox(i, j + 1, "f");
        }
    }
}

// displayBoard() PRINTS BOARD TO TERMINAL
void gameBoard::displayBoard() {
        char letters[] = {'A','B','C','D','E','F','G','H'};         // array of letters for labeling each row to the user

        // Printing board loop
        for(unsigned int i = 0; i < board.size(); i++) {
            cout << "  " << letters[i];                             // print each row letter first

            for(unsigned int j = 0; j < boardRow.size(); j++) {     // print each boardRow vector from the board object
                cout << "   \t" << board[i][j] << endl;                
            }
        }

        cout << "\n\n               ";

        // Printing column numbers
        for(unsigned int i = 0; i < board.size(); i++)              // print numbers below the board to label each column
            cout << i+1 << "             ";

        cout << endl << endl;
}

// changeBox() CHANGES ONE BOX IN THE BOARD
// 3 parameters:
// (int row, int column, string boxType
void gameBoard::changeBox(int row, int column, string boxType) {   
    int rangeC = (column-1) * (BOX_WIDTH), indexR = (row-1);        // rangeC finds the starting index in boardRow vector at the column parameter

    try {
        if(row > 8 || row < 1)                                      // row must be 1-8
            throw inputExc("Error: Row out of range.");
        else if(column > 8 || column < 1)                           // column must be 1-8
            throw inputExc("Error: Column out of range.");
        
        // changeBox loop
        for(int i = 1; i < ROW_AMOUNT - 1; i++) {       
            board[indexR][i].erase(rangeC, 14);                     // start by erasing 14 characters from boardRow vector's row string starting at index (rangeC)     
            
            if(boxType == "x" || boxType == "X")
                board[indexR][i].insert(rangeC, xBox[i]);           // if boxType is 'x', then insert row string from xBox vector into the position erased in the previous step
            else if(boxType == "o" || boxType == "O")
                board[indexR][i].insert(rangeC, oBox[i]);           // if boxType is 'o', do above step for oBox
            else if(boxType == "xk" || boxType == "XK" || boxType == "Xk" || boxType == "xK")       
                board[indexR][i].insert(rangeC, xKingBox[i]);                                           // if boxType is 'xk', do above step for xKingBox
            else if(boxType == "ok" || boxType == "OK" || boxType == "Ok" || boxType == "oK")
                board[indexR][i].insert(rangeC, oKingBox[i]);                                           // if boxType is 'ok', do above step for oKingBox
            else if(boxType == "f" || boxType == "F")
                board[indexR][i].insert(rangeC, filledBox[i]);                                          // if boxType is 'f', do above step for filledBox
            else if(boxType == "e" || boxType == "E")
                board[indexR][i].insert(rangeC, emptyBox[i]);                                          // if boxType is 'e', do above step for emptyBox
            else
                throw inputExc("Error: Incorrect box value.");
        }
    }
    catch(inputExc &error) {
        cout << error.what() << endl;
    }
}

// writeToFile() WRITES board OBJECT TO OUTPUT FILE
// parameters:
// address to outputFile (outFile)
void gameBoard::writeToFile(ofstream &outFile) {

    // Loop to write board[][] elements to outFile
    for(unsigned int i = 0; i < board.size(); i++) {
        for(unsigned int j = 0; j < boardRow.size(); j++) {
            if(i + 1 == board.size() && j + 1 == boardRow.size())
                outFile << board[i][j];                             
            else
                outFile << board[i][j] << endl;
        }
    }
}