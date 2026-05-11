#include "TextEffects.h"

string resetColor()
{
    return "\033[0m";
}

void typeText(string text)
{
    for(char c : text)
    {
        cout<< c <<flush;

        this_thread::sleep_for(chrono::milliseconds(25));
    }

    cout << endl;
}

void typeText(string text, string color)
{
    cout << color;
    typeText(text);
    cout << resetColor();
}

void waitForEnter()
{
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "Press Enter to continue...";

    if(cin.peek() == '\n')
    {
        cin.ignore();
    }

    cin.get();
}

void showHeading(string title)
{
    cout << endl;
    cout << "==========================================" << endl;
    cout << " " << title << endl;
    cout << "==========================================" << endl;
}

void showHeading(string title, string color)
{
    cout << color;
    showHeading(title);
    cout << resetColor();
}

void showMainBanner()
{
    cout << "******************************************" << endl;
    cout << "*           SOLDIER ISLAND               *" << endl;
    cout << "*        Mystery Story Program           *" << endl;
    cout << "******************************************" << endl;
}

void clearScreen()
{
    cout << "\033[2J\033[H" << flush;
}
