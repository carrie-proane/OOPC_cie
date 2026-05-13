#ifndef PLAY_H
#define PLAY_H

#include "../Characters/Character.h"
#include <string>
using namespace std;

class Play
{
private:
    Character* characters[10];
    int currentChapter;

    string getChapterColor(int chapterNumber) const;

    
    void chapter1();   void chapter2();   void chapter3();
    void chapter4();   void chapter5();   void chapter6();
    void chapter7();   void chapter8();   void chapter9();
    void chapter10();  void chapter11();  void chapter12();
    void chapter13();  void chapter14();

    void runChapter();
    void playGame();
    bool showChapterOptions();
    void saveGame();
    bool loadGame();

public:
    Play();
    ~Play();

    void startGame();
    void showSurvivors();

    Character& getCharacter(int index);
};

#endif