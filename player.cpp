#include "player.h"

using namespace std;

// player() CONSTRUCTOR
// parameters:
// smart pointer to a gameBoard object
player::player(shared_ptr<gameBoard> current) {
    currGame = current;
}

player::~player() {

}

void player::setQueen() {

}

// setupTurn() FUNCTION TO PROMPT USER WITH THEIR PIECE SELECTIONS
void player::setupTurn() {
    bool checkPiece = 0;
    string piece, nextSpace;
    char row, col;
    int column, rowNum;

    currGame->displayBoard();

    while(checkPiece == 0) {
        cout << "Choose your piece to move (ex. F3, G4, H7...): "; cin >> piece;            // Prompt user for their piece to move

        if(piece.length() < 2 || piece.length() > 2)                                        // Input must be a string of length 2
            cout << endl << "Error: Invalid Input, Try Again." << endl << endl;
        else if(isalpha(piece[0]) == 0 || isdigit(piece[1]) == 0)                           // First character must be a letter, Second character must be a digit
            cout << endl << "Error: Invalid Input, Try Again." << endl << endl;
        else {
            row = piece[0];
            col = piece[1];
            column = (int)col - 48;                 // convert 'col' from a character to an integer

            rowNum = validPiece(row, column);       // validPiece() evaluates if the piece selected is valid and returns value into rowNum

            if(rowNum == -1)                                                                        // if validPiece returns -1, then the piece selected is invalid
                cout << endl << "Error: Invalid Piece Selection, Try Again." << endl << endl;
            else if(rowNum == -2)                                                                   // if validPiece returns -2, then the piece selected is valid but can't move
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

// validPiece() FUNCTION TO VALIDATE WHETHER A USER'S SELECTED PIECE IS A VALID CHOICE OR NOT
// parameters:
// char row, int column
int player::validPiece(char row, int column) {
    string rowSegment;
    char letters[] = {'a','b','c','d','e','f','g','h'};
    bool loopControl = 0;
    int rowNum = -1, rowIndex, validate;

    for(int i = 0; loopControl == 0; i++) {                         // converting 'row' parameter from a letter to an integer
        if(row == letters[i] || row == toupper(letters[i])) {       // loops starting from i = 0 until 'row' matches 'letters[i]'
            loopControl = 1;    
            rowNum = i;                                             // sets rowNum = i
        }
        else if(i > 8)                                              // if 'row' doesn't match anything from 'letters[]', then rowNum = -1
            loopControl = 1;
    }

    if(rowNum == -1)        // if rowNum == -1, then return -1                                                                                  // example:
        return -1;                                                                                                                              // |~~~~~~~~~~~~|
                                                                                                                                                // |    /``\    |
    rowIndex = (column - 1) * BOX_WIDTH;                            // rowIndex is used to get rowSegment                                       // |   |    |   |  <-- rowSegment
    rowSegment = currGame->board[rowNum][2].substr(rowIndex, 14);   // rowSegment = middle row of a boardRow vector                             // |    \__/    |
                                                                                                                                                // |~~~~~~~~~~~~|
    if(rowSegment == currGame->oBox[2]) {                           // if current piece is an oBox, continue on...
        validate = checkNextBox(rowNum, column, rowSegment);            // calling checkNextBox() to validate if there's a path for the current piece to move to

        if(validate == -2)                                              // if not, return -2
            return -2;
        else if(rowNum == -1) {                                         // if the next box is an xBox or xKingBox, then continue...
            validate = checkNextBox(rowNum, column, rowSegment);            // checkNextBox() to validate a path for a jump over an xBox/xKingBox

            if(validate == -2)                                              // if no path exists, return -2
                return -2;
            else if(validate == -1)                                         // if the next box is another xBox/xKingBox, return -2
                return -2;
            else                                                            // if a path does exist, return validate
                return validate;
        }
        else                                                            // if the original piece has an empty path already, return validate
            return validate;
    }
    else if(rowSegment == currGame->oKingBox[2]) {                  // TEMPORARY RETURN UNTIL KING PIECES ARE SUPPORTED
        return -1;
    }
    else                                                            // if current piece != oBox/oKingBox, then return -1
        return -1;
}

// checkNextBox() FUNCTION TO VALIDATE IF THE SELECTED PIECE HAS A PATH TO MOVE TO
int player::checkNextBox(int &rowNum, int &column, string rowSegment) {
    int rowIndex;

    rowNum--;                                                                       // move to the next row above
                                                                                        
        if(rowNum < 0)                                                              // check if the rowNum is in bounds                                 
            return -2;                                                                  
                                                                                        
        column--;                                                                   // then go to the column to the left

        if(column >= 1) {                                                           // if column is in bounds, then check current (rowNum, column) piece
            rowIndex = (column - 1) * BOX_WIDTH;                                    
            rowSegment = currGame->board[rowNum][2].substr(rowIndex, 14);           

            if(rowSegment == currGame->emptyBox[2])                                             // check if updated piece is an emptyBox, then return rowNum
                return rowNum;
            else if(rowSegment == currGame->xBox[2] || rowSegment == currGame->xKingBox[2])     // check if next boxes are xBox or xKingBox, return -1
                return -1;
        }
        
        column += 2;                                                                // next, advance 2 columns to the right

        if(column > 8)                                                              // check if column is out of bounds
            return -2;
    
        rowIndex = (column - 1) * BOX_WIDTH;                                        // if column is in bounds...
        rowSegment = currGame->board[rowNum][2].substr(rowIndex, 14);               

        if(rowSegment == currGame->emptyBox[2])                                              // check if updated piece is an emptyBox, then return rowNum
            return rowNum;
        else if(rowSegment == currGame->xBox[2] || rowSegment == currGame->xKingBox[2])     // check if next boxes are xBox or xKingBox, return -1
            return -1;

        return -2;                                                                  // if the row/column are in bounds, but the pieces on each side are not emptyBoxes or xBoxes/xKingBoxes, then return -2
}

// User CONSTRUCTOR INVOKES BASE CLASS CONSTRUCTOR (player())
User::User(shared_ptr<gameBoard> current) : player(current) {}

void User::makeAMove() {
    
}

// AI CONSTRUCTOR INVOKES BASE CLASS CONSTRUCTOR (player())
AI::AI(shared_ptr<gameBoard> current) : player(current) {}

void AI::makeAMove() {
    
}