#include "player.h"

using namespace std;

player::player(shared_ptr<gameBoard> current) {
    currGame = current;
}

player::~player() {

}

void player::setQueen() {

}

void player::setupTurn() {
    bool checkPiece = 0;
    string piece, nextSpace;
    char row, col;
    int column;

    currGame->displayBoard();

    while(checkPiece == 0) {
        cout << "Choose your piece to move (ex. F3, G4, H7...): "; cin >> piece;

        if(piece.length() < 2 || piece.length() > 2)
            cout << endl << endl << "Error: Invalid Input, Try Again." << endl << endl;
        else {
            row = piece[0];
            col = piece[1];
            column = (int)col - 48;

            if(validPiece(row, column) == 1)
                checkPiece = 1;
            else
                cout << endl << endl << "Error: Invalid Piece Selection, Try Again." << endl << endl;
        }

    cout << endl << endl << "Enter your next space to move to (ex. E4, E2, E7...): "; cin >> nextSpace;
    cout << endl << endl;
    }

    makeAMove();
}

bool player::winner() {
    return 1;
}

bool player::validMove() {
    return 0;
}

bool player::validPiece(char row, int column) {
    string rowSegment;
    char letters[] = {'a','b','c','d','e','f','g','h'};
    bool loopControl = 0;
    int rowNum = -1, i = 0, rowIndex;

    while(loopControl == 0) {
        if(row == letters[i] || row == toupper(letters[i])) {
            loopControl = 1;
            rowNum = i;
        }
        else if(i > 8)
            loopControl = 1;

        i++;
    }

    if(rowNum == -1)
        return 0;

    rowIndex = (column - 1) * BOX_WIDTH;
    rowSegment = currGame->board[rowNum][2].substr(rowIndex, 14);

    if(rowSegment == currGame->oBox[2] || rowSegment == currGame->oqBox[2])
        return 1;
    else 
        return 0;
}

User::User(shared_ptr<gameBoard> current) : player(current) {}

void User::makeAMove() {
    
}

AI::AI(shared_ptr<gameBoard> current) : player(current) {}

void AI::makeAMove() {
    
}