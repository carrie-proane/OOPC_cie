#include "Character.h"

Character::Character()
{
    alive = true;
    colorCode = "\033[0m";
}

void Character::setCharacter(string n)
{
    name = n;
}

void Character::setColor(string c)
{
    colorCode = c;
}

string Character::getName()
{
    return name;
}

string Character::getColor()
{
    return colorCode;
}

bool Character::isAlive()
{
    return alive;
}

void Character::killCharacter()
{
    alive = false;
}

void Character::speak()
{
    cout << name << ": Something feels wrong here." << endl;
}

void Character::showStatus()
{
    cout << colorCode;
    cout << "| ";

    if(alive)
    {
        cout << "ALIVE | ";
    }
    else
    {
        cout << "DEAD  | ";
    }

    cout << name << "\033[0m" << endl;
}

void Character::saveCharacter(ofstream& file)
{
    file << name << endl;
    file << alive << endl;
}

void Character::loadCharacter(ifstream& file)
{
    getline(file, name);
    file >> alive;
    file.ignore();
}
