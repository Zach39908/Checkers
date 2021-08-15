#include "board.h"

using namespace std;

gameBoard::gameBoard() {
    eBox = {
        "|~~~~~~~~~~~~|",
        "|            |",
        "|            |",
        "|            |",
        "|~~~~~~~~~~~~|"
        };
    xBox = {
        "|~~~~~~~~~~~~|",
        "|    \\ /     |",
        "|     x      |",
        "|    / \\     |",
        "|~~~~~~~~~~~~|"
        };
    oBox = {
        "|~~~~~~~~~~~~|",
        "|    /``\\    |",
        "|   |    |   |",
        "|    \\__/    |",
        "|~~~~~~~~~~~~|"
    };
    qBox = {
        "|~~~~~~~~~~~~|",
        "|    /``\\    |",
        "|    \\__/    |",
        "|       \\    |",
        "|~~~~~~~~~~~~|"
        };

    for(int i = 0; i < ROWS; i++) {
        row1 += eBox[0];
        row2 += eBox[1];
        row3 += eBox[2];
        row4 += eBox[3];
        row5 += eBox[4];
    }

    boardRow.push_back(row1);
    boardRow.push_back(row2);
    boardRow.push_back(row3);
    boardRow.push_back(row4);
    boardRow.push_back(row5);

    for(int j = 0; j < COLS; j++) {
        board.push_back(boardRow);
    }
}

void gameBoard::displayBoard() {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < boardRow.size(); j++) {
                cout << board[i][j] << endl;
            }
        }
    }

void gameBoard::changeBox(int r, int c, char value) {
    int rangeC = (c-1) * (BOX_WIDTH), indexR = (r-1);

    try {
        if(r > 8 || r < 1)
            throw inputExc("Error: Row out of range.");
        else if(c > 8 || c < 1)
            throw inputExc("Error: Column out of range.");

        if(value == 'x' || value == 'X') {
            for(int i = 1; i < ROW_AMOUNT - 1; i++) {
                board[indexR][i].erase(rangeC, 14);
                board[indexR][i].insert(rangeC, xBox[i]);
            }
        }
        else if(value == 'o' || value == 'O') {
            for(int i = 1; i < ROW_AMOUNT - 1; i++) {
                board[indexR][i].erase(rangeC, 14);
                board[indexR][i].insert(rangeC, oBox[i]);
            }
        }
        else if(value == 'q' || value == 'Q') {
            for(int i = 1; i < ROW_AMOUNT - 1; i++) {
                board[indexR][i].erase(rangeC, 14);
                board[indexR][i].insert(rangeC, qBox[i]);
            }
        }
    }
    catch(inputExc error) {
        cout << error.what() << endl;
    }
}

void gameBoard::defaultBoard() {
    for(int i = 1; i < ROWS + 1; i++) {
        if(i == 1 || i == 2 || i == 3) {
            for(int j = 2; j < COLS + 1; j += 2) {
                if(i == 2)
                    changeBox(i, j - 1, 'x');
                else
                    changeBox(i, j, 'x');
            }
        }
        else if(i == 6 || i == 7 || i == 8) {
            for(int j = 1; j < COLS + 1; j += 2) {
                if(i == 7)
                    changeBox(i, j + 1, 'o');
                else
                    changeBox(i, j, 'o');
            }
        }
    }
}

int main() {
    gameBoard g1;
    g1.displayBoard();
    cout << "..." << endl;
    g1.defaultBoard();
    g1.displayBoard();
}