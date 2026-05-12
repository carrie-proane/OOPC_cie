#include "Game.h"
#include "../Utils/TextEffects.h"
#include <fstream>
#include <filesystem>

namespace
{
    const string OCEAN_COLOR = "\033[1;36m";
    const string ACCUSATION_COLOR = "\033[1;33m";
    const string FEAR_COLOR = "\033[1;31m";
    const string END_COLOR = "\033[1;37m";
    const string SAVE_FILE_NAME = "SaveFile.txt";

    string getSaveFilePath()
    {
        try
        {
            std::filesystem::path exePath = std::filesystem::read_symlink("/proc/self/exe");
            return (exePath.parent_path() / SAVE_FILE_NAME).string();
        }
        catch(...)
        {
            return SAVE_FILE_NAME;
        }
    }

    struct GuestInfo
    {
        const char* name;
        const char* color;
    };
}

Game::Game() : currentChapter(1)
{
    buildChapters();
}

void Game::buildChapters()
{
    chapters[0] = make_unique<ScriptedChapter>(&Game::chapter1);
    chapters[1] = make_unique<ScriptedChapter>(&Game::chapter2);
    chapters[2] = make_unique<ScriptedChapter>(&Game::chapter3);
    chapters[3] = make_unique<ScriptedChapter>(&Game::chapter4);
    chapters[4] = make_unique<ScriptedChapter>(&Game::chapter5);
    chapters[5] = make_unique<ScriptedChapter>(&Game::chapter6);
    chapters[6] = make_unique<ScriptedChapter>(&Game::chapter7);
    chapters[7] = make_unique<ScriptedChapter>(&Game::chapter8);
    chapters[8] = make_unique<ScriptedChapter>(&Game::chapter9);
    chapters[9] = make_unique<ScriptedChapter>(&Game::chapter10);
    chapters[10] = make_unique<ScriptedChapter>(&Game::chapter11);
    chapters[11] = make_unique<ScriptedChapter>(&Game::chapter12);
    chapters[12] = make_unique<ScriptedChapter>(&Game::chapter13);
    chapters[13] = make_unique<ScriptedChapter>(&Game::chapter14);
}

Character& Game::getCharacter(int index)
{
    return *characters[index];
}

const Character& Game::getCharacter(int index) const
{
    return *characters[index];
}

string Game::getChapterColor(int chapterNumber) const
{
    if(chapterNumber == 1)
        return OCEAN_COLOR;
    else if(chapterNumber == 2)
        return ACCUSATION_COLOR;
    else if(chapterNumber == 3)
        return getCharacter(0).getColor();
    else if(chapterNumber == 4)
        return FEAR_COLOR;
    else if(chapterNumber == 5)
        return getCharacter(1).getColor();
    else if(chapterNumber == 6)
        return getCharacter(2).getColor();
    else if(chapterNumber == 7)
        return getCharacter(3).getColor();
    else if(chapterNumber == 8)
        return getCharacter(4).getColor();
    else if(chapterNumber == 9)
        return getCharacter(5).getColor();
    else if(chapterNumber == 10)
        return getCharacter(6).getColor();
    else if(chapterNumber == 11)
        return getCharacter(7).getColor();
    else if(chapterNumber == 12)
        return getCharacter(8).getColor();
    else if(chapterNumber == 13)
        return getCharacter(9).getColor();
    else
        return END_COLOR;
}

void Game::setupCharacters()
{
    const GuestInfo guestData[10] =
    {
        {"Anthony Marston", "\033[1;36m"},
        {"Mrs Rogers", "\033[1;33m"},
        {"General Macarthur", "\033[1;32m"},
        {"Mr Rogers", "\033[1;31m"},
        {"Emily Brent", "\033[1;35m"},
        {"Judge Wargrave", "\033[1;37m"},
        {"Dr Armstrong", "\033[1;34m"},
        {"William Blore", "\033[0;36m"},
        {"Philip Lombard", "\033[0;33m"},
        {"Vera Claythorne", "\033[0;35m"}
    };

    for(int i = 0; i < 10; i++)
    {
        characters[i] = make_unique<Character>(guestData[i].name, guestData[i].color);
    }
}

void Game::startGame()
{
    int choice;

    while(true)
    {
        clearScreen();
        showMainBanner();
        cout << endl;
        cout << "1. Start New Story" << endl;
        cout << "2. Load Saved Story" << endl;
        cout << "3. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        
        if(!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl;
            cout << "Invalid choice. Try again." << endl;
            waitForEnter();
            continue;
        }

        if(choice == 1)
        {
            cin.ignore();
            setupCharacters();
            currentChapter = 1;
            playGame();
            break;
        }
        else if(choice == 2)
        {
            cin.ignore();
            setupCharacters();

            if(loadGame())
            {
                playGame();
                break;
            }

            waitForEnter();
        }
        else if(choice == 3)
        {
            cout << endl;
            cout << "Closing program..." << endl;
            break;
        }
        else
        {
            cin.ignore();
            cout << endl;
            cout << "Invalid choice. Try again." << endl;
            waitForEnter();
        }
    }
}

void Game::playGame()
{
    while(currentChapter <= 14)
    {
        clearScreen();
        chapters[currentChapter - 1]->play(*this);

        if(currentChapter == 14)
        {
            break;
        }

        if(showChapterOptions() == false)
        {
            return;
        }

        currentChapter++;
    }
}

bool Game::showChapterOptions()
{
    int choice;

    while(true)
    {
        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Continue Story" << endl;
        cout << "2. Save and Exit" << endl;
        cout << "Enter your choice: ";
        
        if(!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Try again." << endl;
            continue;
        }

        if(choice == 1)
        {
            cin.ignore();
            return true;
        }
        else if(choice == 2)
        {
            cin.ignore();
            currentChapter++;
            saveGame();
            return false;
        }
        else
        {
            cin.ignore();
            cout << "Invalid choice. Try again." << endl;
        }
    }
}

void Game::saveGame()
{
    const string savePath = getSaveFilePath();
    ofstream file(savePath);
    if(!file)
    {
        cout << "Save file could not be created." << endl;
        return;
    }

    file << "Chapter: " << currentChapter << endl;
    file << "---" << endl;

    for(int i = 0; i < 10; i++)
    {
        getCharacter(i).saveCharacter(file);
    }

    file.close();
    cout << endl;
    cout << "Game saved in SaveFile.txt" << endl;
}

bool Game::loadGame()
{
    const string savePath = getSaveFilePath();
    ifstream file(savePath);
    if(!file)
    {
        cout << endl;
        cout << "No saved file was found." << endl;
        return false;
    }

    string chapterLine;
    getline(file, chapterLine);
    currentChapter = stoi(chapterLine.substr(9)); // skips "Chapter: "
    
    string divider;
    getline(file, divider);

    for(int i = 0; i < 10; i++)
    {
        getCharacter(i).loadCharacter(file);
    }

    file.close();
    cout << endl;
    cout << "Saved game loaded successfully." << endl;
    return true;
}

void Game::showSurvivors()
{
    showHeading("CURRENT SURVIVORS", END_COLOR);

    for(int i = 0; i < 10; i++)
    {
        getCharacter(i).showStatus();
    }
}

void Game::chapter1()
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

void Game::chapter2()
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

void Game::chapter3()
{
    cout << getChapterColor(3);
    showHeading("CHAPTER 3 - THE FIRST DEATH");

    typeText("~~One choked his little self and then there were nine~~");
    typeText("Anthony Marston laughs nervously.");
    typeText("He lifts his glass.");
    typeText("He drinks.");

    typeText("Then suddenly...");

    typeText("Anthony chokes violently.");
    typeText("The glass falls from his hand.");
    typeText("He collapses to the floor.");

    getCharacter(0).killCharacter();

    showSurvivors();

    cout << resetColor();
    waitForEnter();
}

void Game::chapter4()
{
    cout << getChapterColor(4);
    showHeading("CHAPTER 4 - FEAR");

    typeText("The storm grows stronger.");
    typeText("Nobody trusts anyone anymore.");
    typeText("Footsteps echo through the mansion.");
    typeText("Outside, thunder shakes the island.");

    typeText("You realize something horrifying.");

    typeText("The killer is still among them.");

    cout << resetColor();
    waitForEnter();
}

void Game::chapter5()
{
    cout << getChapterColor(5);
    showHeading("CHAPTER 5 - THE SECOND DEATH");

    typeText("~~One overslept himself and then there were eight.~~");
    typeText("Morning arrives slowly.");
    typeText("Rain lashes against the windows.");
    typeText("The mansion feels colder than before.");

    typeText("Nobody slept peacefully.");

    typeText("Vera notices something strange.");

    typeText("\"Where is Mrs Rogers?\"");

    typeText("The dining room falls silent.");

    typeText("Mr Rogers stares at the floor.");
    typeText("His hands tremble violently.");

    typeText("Dr Armstrong walks upstairs.");

    typeText("The guests wait in complete silence.");

    typeText("Only the storm can be heard.");

    typeText("Minutes later...");

    typeText("Dr Armstrong returns.");

    typeText("His face is pale.");

    typeText("\"Mrs Rogers is dead.\"");

    typeText("Nobody speaks.");

    typeText("Fear spreads through the mansion.");

    getCharacter(1).killCharacter();

    showSurvivors();

    cout << resetColor();
    waitForEnter();
}

void Game::chapter6()
{
    cout << getChapterColor(6);
    showHeading("CHAPTER 6 - THE THIRD DEATH");

    typeText("~~One said he'd stay there and then there were seven~~");
    typeText("The storm continues without mercy.");
    typeText("Waves crash violently against the cliffs.");
    typeText("Nobody speaks much anymore.");

    typeText("Fear hangs over the mansion like a shadow.");

    typeText("General Macarthur sits alone near the shore.");
    typeText("He stares silently at the sea.");

    typeText("\"I knew this was coming,\" he whispers.");

    typeText("The others remain inside the house.");
    typeText("No one notices how long he has been gone.");

    typeText("As evening approaches...");
    typeText("Lombard decides to search outside.");

    typeText("Rain pours heavily across the island.");

    typeText("Then suddenly—");

    typeText("\"Over here!\"");

    typeText("The group rushes toward the beach.");

    typeText("General Macarthur lies motionless on the ground.");

    typeText("There is a terrible wound on the back of his head.");

    typeText("Nobody moves.");

    typeText("Nobody breathes.");

    typeText("The realization strikes them all at once.");

    typeText("The killer has struck again.");

    getCharacter(2).killCharacter();

    showSurvivors();

    cout << resetColor();
    waitForEnter();
}

void Game::chapter7()
{
    cout << getChapterColor(7);
    showHeading("CHAPTER 7 - THE FOURTH DEATH");
    typeText("~~One chopped himself in halves and then there were six~~");
    typeText("The island feels completely isolated now.");
    typeText("The storm has cut off all hope of rescue.");

    typeText("Nobody sleeps anymore.");
    typeText("Every sound inside the mansion feels dangerous.");

    typeText("Mr Rogers tries to continue his duties.");
    typeText("He prepares breakfast in silence.");

    typeText("His face looks exhausted.");
    typeText("Fear has drained the color from his eyes.");

    typeText("Early in the morning...");
    typeText("The others wait in the dining room.");

    typeText("But Mr Rogers never arrives.");

    typeText("Minutes pass.");

    typeText("Then Blore stands up.");

    typeText("\"I'll go check the kitchen.\"");

    typeText("The hallway creaks beneath his footsteps.");

    typeText("Suddenly—");

    typeText("A horrified scream echoes through the mansion.");

    typeText("Everyone rushes toward the kitchen.");

    typeText("The room falls silent.");

    typeText("Mr Rogers lies collapsed near the fireplace.");

    typeText("A heavy axe rests nearby.");

    typeText("Nobody dares to speak.");

    typeText("The terror inside the mansion deepens.");

    typeText("One thought now dominates every mind.");

    typeText("\"Who will be next?\"");

    getCharacter(3).killCharacter();

    showSurvivors();

    cout << resetColor();
    waitForEnter();
}

void Game::chapter8()
{
    cout << getChapterColor(8);
    showHeading("CHAPTER 8 - THE FIFTH DEATH");

    typeText("~~A bumblebee stung one and then there were five.~~");
    typeText("The mansion grows quieter with every death.");
    typeText("Even the walls seem to carry fear now.");

    typeText("Emily Brent sits alone in the drawing room.");
    typeText("She keeps her hands tightly folded.");

    typeText("Nobody chooses to sit near her anymore.");

    typeText("Outside, the storm continues endlessly.");

    typeText("The clock ticks loudly in the silence.");

    typeText("Emily closes her eyes for a moment.");

    typeText("Then suddenly—");

    typeText("A faint movement behind her.");

    typeText("A sharp gasp escapes her lips.");

    typeText("The sound of a chair crashing to the floor echoes through the mansion.");

    typeText("The others rush into the room.");

    typeText("Emily Brent lies motionless beside the fireplace.");

    typeText("Dr Armstrong kneels beside her.");

    typeText("His expression darkens.");

    typeText("\"She's dead.\"");

    typeText("Nobody speaks.");

    typeText("The silence feels unbearable.");

    typeText("Vera notices something horrifying.");

    typeText("A syringe lies nearby.");

    typeText("The storm outside grows louder.");

    typeText("And somewhere inside the mansion...");

    typeText("The killer is still waiting.");

    getCharacter(4).killCharacter();

    showSurvivors();

    typeText("Only five remain.");

    cout << resetColor();
    waitForEnter();
}

void Game::chapter9()
{
    cout << getChapterColor(9);
    showHeading("CHAPTER 9 - THE SIXTH DEATH");

    typeText("~~One got in Chancery and then there were four~~");
    typeText("The mansion feels almost abandoned now.");
    typeText("Every hallway echoes with silence.");

    typeText("The remaining guests gather carefully in the dining room.");
    typeText("Nobody trusts anyone anymore.");

    typeText("Vera notices something strange.");

    typeText("\"Where is Judge Wargrave?\"");

    typeText("A terrible silence follows.");

    typeText("Lombard slowly stands.");

    typeText("\"We search together,\" he says firmly.");

    typeText("The group moves cautiously through the mansion.");

    typeText("Every door feels dangerous.");

    typeText("Then Blore stops suddenly.");

    typeText("\"In here...\"");

    typeText("The room is dimly lit.");

    typeText("Judge Wargrave sits motionless in a high-backed chair.");

    typeText("At first, nobody moves.");

    typeText("Nobody understands what they are seeing.");

    typeText("Then Vera gasps.");

    typeText("\"He's dead.\"");

    typeText("The scene feels horrifyingly unnatural.");

    typeText("The judge appears arranged almost like a figure in a courtroom.");

    typeText("Fear spreads instantly through the room.");

    typeText("If even Wargrave is dead...");

    typeText("Then nobody is safe anymore.");

    getCharacter(5).killCharacter();

    showSurvivors();

    typeText("Only four remain.");

    cout << resetColor();
    waitForEnter();
}

void Game::chapter10()
{
    cout << getChapterColor(10);
    showHeading("CHAPTER 10 - THE SEVENTH DEATH");

    typeText("~~A red herring swallowed one and then there were three~~");
    typeText("The night feels endless.");
    typeText("Rain crashes violently against the windows.");
    typeText("Only four people remain alive.");

    typeText("Fear controls every thought now.");

    typeText("Dr Armstrong has disappeared.");

    typeText("Nobody knows when he was last seen.");

    typeText("Vera paces nervously across the hallway.");

    typeText("\"He wouldn't just vanish,\" she whispers.");

    typeText("Lombard grabs a lantern.");

    typeText("\"We search outside.\"");

    typeText("The wind howls across the island.");
    typeText("Waves slam violently against the rocks below.");

    typeText("The group searches near the cliffs.");

    typeText("For several minutes...");
    typeText("Nobody speaks.");

    typeText("Then Blore suddenly freezes.");

    typeText("\"Look down there.\"");

    typeText("Far below the cliffs...");
    typeText("A body drifts between the crashing waves.");

    typeText("Vera covers her mouth in horror.");

    typeText("Lombard lowers his head silently.");

    typeText("Dr Armstrong is dead.");

    typeText("The sea slowly pulls the body further into darkness.");

    typeText("Nobody understands how the killer keeps succeeding.");

    typeText("And now...");

    typeText("Only three remain.");

    getCharacter(6).killCharacter();

    showSurvivors();

    cout << resetColor();
    waitForEnter();
}

void Game::chapter11()
{
    cout << getChapterColor(11);
    showHeading("CHAPTER 11 - THE EIGHTH DEATH");

    typeText("~~A big bear hugged one and then there were two~~");
    typeText("Morning arrives beneath dark clouds.");
    typeText("The island feels completely lifeless now.");

    typeText("Only three survivors remain.");

    typeText("Blore stands near the entrance hall.");
    typeText("Exhaustion covers his face.");

    typeText("\"We're being hunted one by one,\" he mutters.");

    typeText("Nobody answers.");

    typeText("The mansion creaks loudly in the wind.");

    typeText("Vera notices something outside.");

    typeText("\"Wait... what's that near the terrace?\"");

    typeText("Blore slowly walks toward the doorway.");

    typeText("Rainwater drips from the roof above.");

    typeText("The air feels unbearably tense.");

    typeText("Then suddenly—");

    typeText("*CRASH*");

    typeText("A massive object falls from above.");

    typeText("The sound echoes across the island.");

    typeText("Vera screams.");

    typeText("Lombard rushes forward.");

    typeText("Blore lies motionless beneath the shattered debris.");

    typeText("Nobody moves.");

    typeText("Nobody speaks.");

    typeText("The realization is unbearable now.");

    typeText("Only two survivors remain.");

    getCharacter(7).killCharacter();

    showSurvivors();

    cout << resetColor();
    waitForEnter();
}

void Game::chapter12()
{
    cout << getChapterColor(12);
    showHeading("CHAPTER 12 - THE NINTH DEATH");

    typeText("~~One got frizzled up and then there was one~~");
    typeText("The storm finally begins to weaken.");
    typeText("But the silence inside the mansion feels worse.");

    typeText("Only Vera and Lombard remain alive.");

    typeText("Every shadow feels threatening.");
    typeText("Every sound causes panic.");

    typeText("Vera grips the revolver tightly.");

    typeText("\"It has to be you,\" she whispers.");

    typeText("Lombard stares at her carefully.");

    typeText("\"You're frightened,\" he says quietly.");

    typeText("\"We're both frightened.\"");

    typeText("The wind moves through the empty halls.");

    typeText("Neither of them trusts the other anymore.");

    typeText("Lombard slowly steps forward.");

    typeText("\"Give me the gun, Vera.\"");

    typeText("She shakes her head immediately.");

    typeText("\"Stay back.\"");

    typeText("The tension becomes unbearable.");

    typeText("For one endless moment...");
    typeText("Nobody moves.");

    typeText("Then suddenly—");

    typeText("*BANG*");

    typeText("The sound tears through the mansion.");

    typeText("Lombard stumbles backward.");

    typeText("The revolver slips from Vera's trembling hands.");

    typeText("Lombard collapses silently onto the ground.");

    typeText("The island becomes completely still.");

    typeText("Vera realizes with horror...");

    typeText("She is now alone.");

    getCharacter(8).killCharacter();

    showSurvivors();

    cout << resetColor();
    waitForEnter();
}


void Game::chapter13()
{
    cout << getChapterColor(13);
    showHeading("CHAPTER 13 - THE FINAL DEATH");

    typeText("~~He went out and hanged himself and then there were none~~");
    typeText("The mansion is silent.");

    typeText("No voices remain.");
    typeText("No footsteps echo through the halls.");

    typeText("Only Vera remains alive.");

    typeText("She walks slowly through the empty rooms.");
    typeText("The house feels unreal now.");

    typeText("The storm outside has finally passed.");

    typeText("But the silence feels worse than the storm.");

    typeText("Vera's hands tremble.");
    typeText("Her thoughts begin to blur together.");

    typeText("Every memory feels unbearable.");

    typeText("The island feels like a prison with no escape.");

    typeText("She enters her room slowly.");

    typeText("Everything appears strangely calm.");

    typeText("Then she notices something waiting inside.");

    typeText("A rope hangs quietly from the ceiling.");

    typeText("Vera stares at it in silence.");

    typeText("The mansion feels completely still.");

    typeText("Somewhere deep inside her mind...");
    typeText("A terrible feeling takes hold.");

    typeText("Step by step...");
    typeText("She walks forward.");

    typeText("The silence swallows everything.");

    typeText("And Soldier Island is finally empty.");

    getCharacter(9).killCharacter();

    showSurvivors();

    showHeading("THE END");

    cout << resetColor();
    waitForEnter();
}


void Game::chapter14()
{
    cout << getChapterColor(14);
    showHeading("CHAPTER 14 - EPILOGUE");

    
    typeText("Days later...");

    typeText("The storm finally clears.");

    typeText("A rescue team arrives at Soldier Island.");

    typeText("The mansion stands silent against the gray sky.");

    typeText("No movement.");
    typeText("No voices.");

    typeText("Only the sound of waves against the rocks.");

    typeText("The investigators slowly enter the house.");

    typeText("Room by room...");
    typeText("They discover the truth.");

    typeText("Ten people came to the island.");

    typeText("None survived.");

    typeText("The mystery spreads quickly across the mainland.");

    typeText("Newspapers call it impossible.");

    typeText("No one understands how every death occurred.");

    typeText("No killer can be found.");

    typeText("The island itself begins to feel cursed.");

    typeText("Weeks later...");

    typeText("A sealed written confession is finally discovered.");

    typeText("The horrifying truth slowly comes to light.");

    typeText("Every event had been carefully planned from the beginning.");

    typeText("Justice, guilt, and punishment had all become twisted together.");

    typeText("And somewhere beyond the crashing sea...");

    typeText("The mystery of Soldier Island becomes legend.");

    showHeading("THANK YOU FOR READING");

    cout << resetColor();
    waitForEnter();
}
