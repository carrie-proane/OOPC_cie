#ifndef CLUE_H
#define CLUE_H

#include <iostream>
using namespace std;

class Clue
{
private:
    string clueText;
    bool found;

public:
    Clue();

    void setClue(string text);

    void discoverClue();

    bool isFound();

    void showClue();
};

#endif