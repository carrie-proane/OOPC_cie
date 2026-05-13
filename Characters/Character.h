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
    Character(string n, string c);
    virtual ~Character() = default;

    string getName() const;
    string getColor() const;
    bool isAlive() const;

    void killCharacter();
    virtual void showStatus() const;

    virtual void saveCharacter(ofstream& file) const;
    virtual void loadCharacter(ifstream& file);
};


class AnthonyMarston : public Character
{
public:
    AnthonyMarston();
};

class MrsRogers : public Character
{
public:
    MrsRogers();
};

class GeneralMacarthur : public Character
{
public:
    GeneralMacarthur();
};

class MrRogers : public Character
{
public:
    MrRogers();
};

class EmilyBrent : public Character
{
public:
    EmilyBrent();
};

class JudgeWargrave : public Character
{
public:
    JudgeWargrave();
};

class DrArmstrong : public Character
{
public:
    DrArmstrong();
};

class WilliamBlore : public Character
{
public:
    WilliamBlore();
};

class PhilipLombard : public Character
{
public:
    PhilipLombard();
};

class VeraClaythorne : public Character
{
public:
    VeraClaythorne();
};

#endif