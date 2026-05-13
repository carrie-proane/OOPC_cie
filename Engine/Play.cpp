#include "Play.h"
#include "../Utils/TextEffects.h"
#include <fstream>
using namespace std;

const string OCEAN_COLOR      = "\033[1;36m";
const string ACCUSATION_COLOR = "\033[1;33m";
const string FEAR_COLOR       = "\033[1;31m";
const string END_COLOR        = "\033[1;37m";

void Play::startGame()
{
    while(currentChapter <= 14)
    {
        runChapter();
        currentChapter++;
    }
}

Play::Play()
{
    currentChapter = 1;

    characters[0] = new AnthonyMarston();
    characters[1] = new MrsRogers();
    characters[2] = new GeneralMacarthur();
    characters[3] = new MrRogers();
    characters[4] = new EmilyBrent();
    characters[5] = new JudgeWargrave();
    characters[6] = new DrArmstrong();
    characters[7] = new WilliamBlore();
    characters[8] = new PhilipLombard();
    characters[9] = new VeraClaythorne();
}

Play::~Play()
{
    for(int i = 0; i < 10; i++)
        delete characters[i];
}

Character& Play::getCharacter(int index)
{
    return *characters[index];
}

string Play::getChapterColor(int chapterNumber) const
{
    if(chapterNumber == 1)  return OCEAN_COLOR;
    if(chapterNumber == 2)  return ACCUSATION_COLOR;
    if(chapterNumber == 4)  return FEAR_COLOR;
    if(chapterNumber == 14) return END_COLOR;
    return characters[chapterNumber - 3]->getColor();
}

void Play::showSurvivors()
{
    showHeading("CURRENT SURVIVORS", END_COLOR);
    for(int i = 0; i < 10; i++)
        characters[i]->showStatus();
}

void Play::runChapter()
{
    if      (currentChapter == 1)  chapter1();
    else if (currentChapter == 2)  chapter2();
    else if (currentChapter == 3)  chapter3();
    else if (currentChapter == 4)  chapter4();
    else if (currentChapter == 5)  chapter5();
    else if (currentChapter == 6)  chapter6();
    else if (currentChapter == 7)  chapter7();
    else if (currentChapter == 8)  chapter8();
    else if (currentChapter == 9)  chapter9();
    else if (currentChapter == 10) chapter10();
    else if (currentChapter == 11) chapter11();
    else if (currentChapter == 12) chapter12();
    else if (currentChapter == 13) chapter13();
    else if (currentChapter == 14) chapter14();
}

void Play::chapter1()
{
    cout << getChapterColor(1);
    showHeading("CHAPTER 1 - SOLDIER ISLAND");
    typeText("The sea crashes violently against the rocks.");
    typeText("A cold wind moves through the island.");
    typeText("Ten strangers arrive at Soldier Island.");
    typeText("The mansion stands silently in the darkness.");
    cout << resetColor();
    waitForEnter();
}

void Play::chapter2()
{
    cout << getChapterColor(2);

    showHeading("CHAPTER 2 - THE ACCUSATION");

    typeText("Dinner begins quietly.");
    typeText("Suddenly...");
    typeText("A strange voice echoes through the room.");
    typeText("\"All of you are accused of murder.\"");
    typeText("Fear spreads across the table.");

    cout << resetColor();

    waitForEnter();
}

void Play::chapter3()
{
    cout << getChapterColor(3);
    showHeading("CHAPTER 3 - THE FIRST DEATH");
    typeText("Anthony Marston laughs nervously.");
    typeText("He lifts his glass and drinks.");
    typeText("Then suddenly...");
    typeText("Anthony chokes violently and collapses.");
    characters[0]->killCharacter();
    showSurvivors();
    cout << resetColor();
    waitForEnter();
}

void Play::chapter4()
{
    cout << getChapterColor(4);

    showHeading("CHAPTER 4 - FEAR");

    typeText("The storm grows stronger.");
    typeText("Nobody trusts anyone anymore.");
    typeText("Footsteps echo through the mansion.");
    typeText("Outside, thunder shakes the island.");
    typeText("The killer is still among them.");

    cout << resetColor();

    waitForEnter();
}

void Play::chapter5()
{
    cout << getChapterColor(5);

    showHeading("CHAPTER 5 - THE SECOND DEATH");

    typeText("Morning arrives slowly.");
    typeText("\"Where is Mrs Rogers?\"");
    typeText("Minutes later...");
    typeText("\"Mrs Rogers is dead.\"");

    characters[1]->killCharacter();

    showSurvivors();

    cout << resetColor();

    waitForEnter();
}

void Play::chapter6()
{
    cout << getChapterColor(6);

    showHeading("CHAPTER 6 - THE THIRD DEATH");

    typeText("General Macarthur sits alone near the shore.");
    typeText("\"I knew this was coming,\" he whispers.");
    typeText("Then suddenly...");
    typeText("General Macarthur lies motionless on the ground.");
    typeText("The killer has struck again.");

    characters[2]->killCharacter();

    showSurvivors();

    cout << resetColor();

    waitForEnter();
}

void Play::chapter7()
{
    cout << getChapterColor(7);

    showHeading("CHAPTER 7 - THE FOURTH DEATH");

    typeText("Mr Rogers never arrives for breakfast.");
    typeText("Blore goes to check the kitchen.");
    typeText("Mr Rogers lies collapsed near the fireplace.");
    typeText("\"Who will be next?\"");

    characters[3]->killCharacter();

    showSurvivors();

    cout << resetColor();

    waitForEnter();
}

void Play::chapter8()
{
    cout << getChapterColor(8);

    showHeading("CHAPTER 8 - THE FIFTH DEATH");

    typeText("Emily Brent sits alone in the drawing room.");
    typeText("A sharp gasp escapes her lips.");
    typeText("Emily Brent lies motionless beside the fireplace.");
    typeText("\"She's dead.\"");
    typeText("A syringe lies nearby.");

    characters[4]->killCharacter();

    showSurvivors();

    cout << resetColor();

    waitForEnter();
}

void Play::chapter9()
{
    cout << getChapterColor(9);

    showHeading("CHAPTER 9 - THE SIXTH DEATH");

    typeText("\"Where is Judge Wargrave?\"");
    typeText("Judge Wargrave sits motionless in a high-backed chair.");
    typeText("\"He's dead.\"");
    typeText("Nobody is safe anymore.");

    characters[5]->killCharacter();

    showSurvivors();

    cout << resetColor();

    waitForEnter();
}

void Play::chapter10()
{
    cout << getChapterColor(10);

    showHeading("CHAPTER 10 - THE SEVENTH DEATH");

    typeText("Dr Armstrong has disappeared.");
    typeText("A body drifts between the crashing waves.");
    typeText("Dr Armstrong is dead.");
    typeText("Only three remain.");

    characters[6]->killCharacter();

    showSurvivors();

    cout << resetColor();

    waitForEnter();
}

void Play::chapter11()
{
    cout << getChapterColor(11);

    showHeading("CHAPTER 11 - THE EIGHTH DEATH");

    typeText("Blore walks toward the doorway.");
    typeText("*CRASH*");
    typeText("Blore lies motionless beneath the shattered debris.");
    typeText("Only two survivors remain.");

    characters[7]->killCharacter();

    showSurvivors();

    cout << resetColor();

    waitForEnter();
}

void Play::chapter12()
{
    cout << getChapterColor(12);

    showHeading("CHAPTER 12 - THE NINTH DEATH");

    typeText("Only Vera and Lombard remain.");
    typeText("\"It has to be you,\" she whispers.");
    typeText("*BANG*");
    typeText("Lombard collapses silently onto the ground.");
    typeText("Vera is now alone.");

    characters[8]->killCharacter();

    showSurvivors();

    cout << resetColor();

    waitForEnter();
}

void Play::chapter13()
{
    cout << getChapterColor(13);

    showHeading("CHAPTER 13 - THE FINAL DEATH");

    typeText("The mansion is silent.");
    typeText("Only Vera remains alive.");
    typeText("A rope hangs quietly from the ceiling.");
    typeText("Soldier Island is finally empty.");

    characters[9]->killCharacter();

    showSurvivors();

    showHeading("THE END");

    cout << resetColor();

    waitForEnter();
}

void Play::chapter14()
{
    cout << getChapterColor(14);

    showHeading("CHAPTER 14 - EPILOGUE");

    typeText("Days later...");
    typeText("A rescue team arrives at Soldier Island.");
    typeText("Ten people came to the island.");
    typeText("None survived.");
    typeText("Every event had been carefully planned from the beginning.");
    typeText("And somewhere beyond the crashing sea...");
    typeText("The mystery of Soldier Island becomes legend.");

    showHeading("THANK YOU FOR READING");

    cout << resetColor();

    waitForEnter();
}