#include "board.h"

using namespace std;

gameBoard::gameBoard() {
    eBox = {                // eBox = emptyBox
        "|~~~~~~~~~~~~|",
        "|            |",
        "|            |",
        "|            |",
        "|~~~~~~~~~~~~|"
    };
    cBox = {                // cBox = colorBox
        "|~~~~~~~~~~~~|",
        "|------------|",
        "|------------|",
        "|------------|",
        "|~~~~~~~~~~~~|"
    };
    xBox = {                // xBox = X player's piece ('X' pieces are the AI's pieces)
        "|~~~~~~~~~~~~|",
        "|    \\ /     |",
        "|     x      |",
        "|    / \\     |",
        "|~~~~~~~~~~~~|"
    };
    oBox = {                // oBox = O player's piece ('O' pieces are the Player's pieces)
        "|~~~~~~~~~~~~|",
        "|    /``\\    |",
        "|   |    |   |",
        "|    \\__/    |",
        "|~~~~~~~~~~~~|"
    };
    xqBox = {               // xqBox = 'X' player's Queen piece (AI's queen piece)
        "|~~~~~~~~~~~~|",
        "|    /``\\    |",
        "| X  \\__/  X |",
        "|       \\    |",
        "|~~~~~~~~~~~~|"
    };
    oqBox = {               // oqBox = 'O' player's Queen piece (Player's queen piece)
        "|~~~~~~~~~~~~|",
        "|    /``\\    |",
        "| O  \\__/  O |",
        "|       \\    |",
        "|~~~~~~~~~~~~|"
    };

    for(int i = 0; i < COLS; i++) {     
        row1 += eBox[0];                // Filling row1 with 8 iterations of the first row of eBox.
        row2 += eBox[1];                // Filling row2 with 8 iterations of the second row of eBox and so on...
        row3 += eBox[2];
        row4 += eBox[3];
        row5 += eBox[4];
    }

    boardRow.push_back(row1);           // Adding row1 to the first element of boardRow.
    boardRow.push_back(row2);           // Adding row2 to the second element of boardRow and so on...
    boardRow.push_back(row3);
    boardRow.push_back(row4);
    boardRow.push_back(row5);

    for(int j = 0; j < ROWS; j++) {
        board.push_back(boardRow);      // Adding 8 full "boardRow" vectors to the "board" 2D vector.
    }

    defaultBoard();
}

void gameBoard::defaultBoard() {
    for(int i = 1; i < ROWS - 4; i++) {             // The top 3 rows of the default board are filled with 'X' pieces as the AI's pieces.
        for(int j = 2; j < COLS + 1; j += 2) {
            if(i == 2)
                changeBox(i, j - 1, "x");
            else
                changeBox(i, j, "x");
        }
    }

    for(int i = ROWS - 2; i < ROWS + 1; i++) {      // Bottom 3 rows of the default board are filled with 'O' pieces as the player's pieces.
        for(int j = 1; j < COLS + 1; j += 2) {
            if(i == 7)
                changeBox(i, j + 1, "o");
            else
                changeBox(i, j, "o");
        }
    }

    for(int i = 1; i < ROWS + 1; i++) {
        for(int j = 1; j < COLS + 1; j += 2) {      // Changing all unoccupied boxes to filled-in color boxes.
            if(i % 2 != 0)
                changeBox(i, j, "c");
            else
                changeBox(i, j + 1, "c");
        }
    }
}

void gameBoard::displayBoard() {
        for(unsigned int i = 0; i < board.size(); i++) {
            for(unsigned int j = 0; j < boardRow.size(); j++) {
                cout << board[i][j] << endl;                // Displaying each "boardRow" vector in the "board" followed by an endl.
            }
        }

        cout << endl << ".............." << endl << endl;;
    }

void gameBoard::changeBox(int r, int c, string value) {   // r = selected row, c = selected column, value = type of box to change to
    int rangeC = (c-1) * (BOX_WIDTH), indexR = (r-1);

    try {
        if(r > 8 || r < 1)      // If you pass a row outside of 1-8, it doesn't exist on the board.
            throw inputExc("Error: Row out of range.");
        else if(c > 8 || c < 1)     // If you pass a column outside of 1-8, it doesn't exist on the board.
            throw inputExc("Error: Column out of range.");
        
        for(int i = 1; i < ROW_AMOUNT - 1; i++) {       // Looping 3 times to only fill the middle portion of each box (not the upper/lower boundaries).
            board[indexR][i].erase(rangeC, 14);         // Erasing from the specified (row, col) parameters to the next box boundaries.
            
            if(value == "x" || value == "X")
                board[indexR][i].insert(rangeC, xBox[i]);   // Inserting each row of the new box type into the position we just erased.
            else if(value == "o" || value == "O")
                board[indexR][i].insert(rangeC, oBox[i]);
            else if(value == "xq" || value == "XQ" || value == "Xq" || value == "xQ")
                board[indexR][i].insert(rangeC, xqBox[i]);
            else if(value == "oq" || value == "OQ" || value == "Oq" || value == "oQ")
                board[indexR][i].insert(rangeC, oqBox[i]);
            else if(value == "c" || value == "C")
                board[indexR][i].insert(rangeC, cBox[i]);
            else
                throw inputExc("Error: Incorrect box value.");
        }
    }
    catch(inputExc &error) {
        cout << error.what() << endl;
    }
}

void gameBoard::writeToFile(ofstream &outFile) {
    for(unsigned int i = 0; i < board.size(); i++) {
        for(unsigned int j = 0; j < boardRow.size(); j++) {
            if(i + 1 == board.size() && j + 1 == boardRow.size())
                outFile << board[i][j];                             // Writing each row of the board to the ofstream file, on the last row we exclude the endl
            else
                outFile << board[i][j] << endl;
        }
    }
}