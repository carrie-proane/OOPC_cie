#include "Character.h"

Character::Character(string n, string c)
{
    name = n;
    alive = true;
    colorCode = c;
}

void Character::setCharacter(string n)
{
    name = n;
}

void Character::setColor(string c)
{
    colorCode = c;
}

string Character::getName() const
{
    return name;
}

string Character::getColor() const
{
    return colorCode;
}

bool Character::isAlive() const
{
    return alive;
}

void Character::killCharacter()
{
    alive = false;
}

void Character::speak() const
{
    cout << name << ": Something feels wrong here." << endl;
}

void Character::showStatus() const
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

void Character::saveCharacter(ofstream& file) const
{
    file << name << ": " << (alive ? "ALIVE" : "DEAD") << endl;
}

void Character::loadCharacter(ifstream& file)
{
    string line;
    getline(file, line);

    // Split "Anthony Marston: DEAD" into name and status
    size_t colonPos = line.find(": ");
    name  = line.substr(0, colonPos);
    alive = (line.substr(colonPos + 2) == "ALIVE");
}
