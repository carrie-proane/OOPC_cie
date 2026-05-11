#ifndef TEXTEFFECTS_H
#define TEXTEFFECTS_H

#include <iostream>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

void typeText(string text);
void typeText(string text, string color);

void waitForEnter();

void showHeading(string title);
void showHeading(string title, string color);

void showMainBanner();

void clearScreen();

string resetColor();

#endif
