#include "Clue.h"

Clue::Clue()
{
    found = false;
}

void Clue::setClue(string text)
{
    clueText = text;
}

void Clue::discoverClue()
{
    found = true;
}

bool Clue::isFound()
{
    return found;
}

void Clue::showClue()
{
    if(found)
    {
        cout << clueText << endl;
    }
}