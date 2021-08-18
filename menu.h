#include <fstream>
#include "board.h"
 
 using namespace std;

class gameMenu {
    vector<string> Options;
    int Select[5];
public:
    gameMenu();
    void Interface();
    void title();
    bool inputCheck(string);
};