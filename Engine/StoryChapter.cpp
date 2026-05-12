#include "StoryChapter.h"
#include "Game.h"

ScriptedChapter::ScriptedChapter(ChapterAction chapterAction)
{
    action = chapterAction;
}

void ScriptedChapter::play(Game& game)
{
    (game.*action)();
}
