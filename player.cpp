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
    int column, rowNum;

    currGame->displayBoard();

    while(checkPiece == 0) {
        cout << "Choose your piece to move (ex. F3, G4, H7...): "; cin >> piece;

        if(piece.length() < 2 || piece.length() > 2)
            cout << endl << endl << "Error: Invalid Input, Try Again." << endl << endl;
        else {
            row = piece[0];
            col = piece[1];
            column = (int)col - 48;

            rowNum = validPiece(row, column);

            if(rowNum == -1)
                cout << endl << "Error: Invalid Piece Selection, Try Again." << endl << endl;
            else if(rowNum == -2)
                cout << endl << "Error: Piece Selected Can't Advance Forward, Try Again." << endl << endl;
            else
                checkPiece = 1;
        }
    }

    cout << endl << "............." << endl << endl << "Enter your next space to move to (ex. E4, E2, E7...): "; cin >> nextSpace;
    cout << endl << endl;

    makeAMove();
}

bool player::winner() {
    return 1;
}

bool player::validMove() {
    return 0;
}

int player::validPiece(char row, int column) {
    string rowSegment;
    char letters[] = {'a','b','c','d','e','f','g','h'};
    bool loopControl = 0;
    int rowNum = -1, rowIndex;

    for(int i = 0; loopControl == 0; i++) {
        if(row == letters[i] || row == toupper(letters[i])) {
            loopControl = 1;
            rowNum = i;
        }
        else if(i > 8)
            loopControl = 1;
    }

    if(rowNum == -1)
        return -1;

    rowIndex = (column - 1) * BOX_WIDTH;
    rowSegment = currGame->board[rowNum][2].substr(rowIndex, 14);

    if(rowSegment == currGame->oBox[2] || rowSegment == currGame->oKingBox[2]) {
        rowNum--;

        if(rowNum < 0)
            return -2;

        column--;

        if(column >= 1) {
            rowIndex = (column - 1) * BOX_WIDTH;
            rowSegment = currGame->board[rowNum][2].substr(rowIndex, 14);

            if(rowSegment == currGame->emptyBox[2])
                return rowNum;
        }
        
        column += 2;

        if(column > 8)
            return -2;
    
        rowIndex = (column - 1) * BOX_WIDTH;
        rowSegment = currGame->board[rowNum][2].substr(rowIndex, 14);

        if(rowSegment == currGame->emptyBox[2])
            return rowNum;

        return -2;
    }
    else 
        return -1;
}

User::User(shared_ptr<gameBoard> current) : player(current) {}

void User::makeAMove() {
    
}

AI::AI(shared_ptr<gameBoard> current) : player(current) {}

void AI::makeAMove() {
    
}