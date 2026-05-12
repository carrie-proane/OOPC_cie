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
    Character(string n = "", string c = "\033[0m");
    virtual ~Character() = default;

    void setCharacter(string n);

    void setColor(string c);

    string getName() const;

    string getColor() const;

    bool isAlive() const;

    void killCharacter();

    virtual void speak() const;

    virtual void showStatus() const;

    virtual void saveCharacter(ofstream& file) const;

    virtual void loadCharacter(ifstream& file);
};

#endif
