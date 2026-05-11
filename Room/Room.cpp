#include "Room.h"

void Room::setRoom(string n, string d)
{
    roomName = n;
    description = d;
}

void Room::displayRoom()
{
    cout << roomName << endl;
    cout << description << endl;
}

string Room::getRoomName()
{
    return roomName;
}