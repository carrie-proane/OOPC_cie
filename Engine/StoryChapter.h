#ifndef STORYCHAPTER_H
#define STORYCHAPTER_H

class Game;

class StoryChapter
{
public:
    virtual ~StoryChapter() = default;
    virtual void play(Game& game) = 0;
};

class ScriptedChapter : public StoryChapter
{
private:
    typedef void (Game::*ChapterAction)();
    ChapterAction action;

public:
    explicit ScriptedChapter(ChapterAction chapterAction);

    void play(Game& game) override;
};

#endif
