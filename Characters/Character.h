#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <fstream>
using namespace std;

class Character
{
protected:
    string name;
    bool alive;
    string colorCode;

public:
    Character();

    void setCharacter(string n);

    void setColor(string c);

    string getName();

    string getColor();

    bool isAlive();

    void killCharacter();

    virtual void speak();

    void showStatus();

    void saveCharacter(ofstream& file);

    void loadCharacter(ifstream& file);
};

#endif
