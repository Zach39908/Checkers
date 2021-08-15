#include <fstream>
#include "board.h"
 
 using namespace std;

class gameMenu {
    string Options[5];
    char Select[10];
public:
    gameMenu();
    void Interface();
    bool inputCheck(string);
};