#ifndef GAME_H
#define GAME_H

#include "../Characters/Character.h"

class Game
{
private:
    Character characters[10];
    int currentChapter;

    void playGame();

    bool showChapterOptions();

    void saveGame();

    bool loadGame();

public:
    void startGame();

    void setupCharacters();

    void showSurvivors();

    void chapter1();

    void chapter2();

    void chapter3();

    void chapter4();

    void chapter5();

    void chapter6();

    void chapter7();

    void chapter8();

    void chapter9();

    void chapter10();

    void chapter11();

    void chapter12();

    void chapter13();

    void chapter14();
};

#endif
