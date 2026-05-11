#ifndef ROOM_H
#define ROOM_H

#include <iostream>
using namespace std;

class Room
{
private:
    string roomName;
    string description;

public:
    void setRoom(string n, string d);

    void displayRoom();

    string getRoomName();
};

#endif