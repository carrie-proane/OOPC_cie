#ifndef GAME_H
#define GAME_H

#include "../Characters/Character.h"
#include "StoryChapter.h"
#include <array>
#include <memory>
#include <string>

class Game
{
private:
    array<unique_ptr<Character>, 10> characters;
    array<unique_ptr<StoryChapter>, 14> chapters;
    int currentChapter;

    void buildChapters();

    Character& getCharacter(int index);

    const Character& getCharacter(int index) const;

    string getChapterColor(int chapterNumber) const;

    void playGame();

    bool showChapterOptions();

    void saveGame();

    bool loadGame();

public:
    Game();

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
