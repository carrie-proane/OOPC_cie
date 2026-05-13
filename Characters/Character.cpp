#include "Character.h"

Character::Character()
{
    name      = "";
    alive     = true;
    colorCode = "\033[0m";
}

Character::Character(string n, string c)
{
    name      = n;
    alive     = true;
    colorCode = c;
}

string Character::getName() const { return name; }
string Character::getColor() const { return colorCode; }
bool   Character::isAlive()  const { return alive; }

void Character::killCharacter()
{
    alive = false;
}

void Character::showStatus() const
{
    cout << colorCode;
    cout << "| ";
    if(alive) cout << "ALIVE | ";
    else      cout << "DEAD  | ";
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
    size_t colonPos = line.find(": ");
    name  = line.substr(0, colonPos);
    alive = (line.substr(colonPos + 2) == "ALIVE");
}


// ─── Derived Class Implementations ───────────────────────────────────────────
AnthonyMarston::AnthonyMarston()
{
    name      = "Anthony Marston";
    colorCode = "\033[1;36m";
}

MrsRogers::MrsRogers()
{
    name      = "Mrs Rogers";
    colorCode = "\033[1;33m";
}

GeneralMacarthur::GeneralMacarthur()
{
    name      = "General Macarthur";
    colorCode = "\033[1;32m";
}

MrRogers::MrRogers()
{
    name      = "Mr Rogers";
    colorCode = "\033[1;31m";
}

EmilyBrent::EmilyBrent()
{
    name      = "Emily Brent";
    colorCode = "\033[1;35m";
}

JudgeWargrave::JudgeWargrave()
{
    name      = "Judge Wargrave";
    colorCode = "\033[1;37m";
}

DrArmstrong::DrArmstrong()
{
    name      = "Dr Armstrong";
    colorCode = "\033[1;34m";
}

WilliamBlore::WilliamBlore()
{
    name      = "William Blore";
    colorCode = "\033[0;36m";
}

PhilipLombard::PhilipLombard()
{
    name      = "Philip Lombard";
    colorCode = "\033[0;33m";
}

VeraClaythorne::VeraClaythorne()
{
    name      = "Vera Claythorne";
    colorCode = "\033[0;35m";
}