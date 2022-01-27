#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <random>
#include <chrono>

int main();
void showClass(char, std::string*, std::string*, std::string*, int);
void showWeapons(std::string*, std::string*, std::string*, int, int, int);
void showMods(std::string*, int);
void showActivity(std::string*, int);
char userInput();
bool exitInput();

int main(){

    // Sizes for all arrays - would use std::size_t but too lazy
    int modsSize = 3;
    int activitySize = 6;
    int primariesSize = 6;
    int specialsSize = 6;
    int heaviesSize = 6;
    int subclassSize = 10; // Only this one int for all 3 classes because they always have the same amount of subclasses.

    /////////////////////////////////////////////////////
    // Storing all missions/mods etc in arrays
    std::string * mods = new std::string [modsSize];
    mods[0] = "Charged With Light";
    mods[1] = "Wells";
    mods[2] = "Resist";

    std::string * activity = new std::string [activitySize];
    activity[0] = "Prophecy";
    activity[1] = "Pit of Heresy";
    activity[2] = "Grasp of Avarice";
    activity[3] = "Shattered Throne";
    activity[4] = "Presage";
    activity[5] = "Harbinger";

    std::string * primaries = new std::string [primariesSize];
    primaries[0] = "Weapon of your Choice";
    primaries[1] = "SMG";
    primaries[2] = "Hand Cannon";
    primaries[3] = "Auto Rifle";
    primaries[4] = "Pulse Rifle";
    primaries[5] = "Bow";

    std::string * specials = new std::string [specialsSize];
    specials[0] = "Weapon of your Choice";
    specials[1] = "Slug Shotgun";
    specials[2] = "Pellet Shotgun";
    specials[3] = "Grenade Launcher";
    specials[4] = "Sniper Rifle";
    specials[5] = "Fusion Rifle";

    std::string * heavies = new std::string [heaviesSize];
    heavies[0] = "Weapon of your Choice";
    heavies[1] = "Rocket Launcher";
    heavies[2] = "Grenade Launcher";
    heavies[3] = "Machine Gun";
    heavies[4] = "Sword";
    heavies[5] = "Linear Fusion Rifle";

    std::string * wClass = new std::string [subclassSize];
    wClass[0] = "Attunement of Hunger - Bottom Tree Voidwalker";
    wClass[1] = "Attunement of Conduction - Top Tree Stormcaller";
    wClass[2] = "Attunement of Control - Middle Tree Stormcaller";
    wClass[3] = "Attunement of the Elements - Bottom Tree Stormcaller";
    wClass[4] = "Attunement of Flame - Bottom Tree Dawnblade";
    wClass[5] = "Attunement of Fission - Middle Tree Voidwalker";
    wClass[6] = "Attunement of Chaos - Top Tree Voidwalker";
    wClass[7] = "Attunement of Sky - Top Tree Dawnblade";
    wClass[8] = "Shadebinder";
    wClass[9] = "Attunement of Grace - Middle Tree Dawnblade";

    std::string * hClass = new std::string [subclassSize];
    hClass[0] = "Way Of A Thousand Cuts - Middle Tree Gunslinger";
    hClass[1] = "Way Of The Warrior - Top Tree Arcstrider";
    hClass[2] = "Way Of The Outlaw - Top Tree Gunslinger";
    hClass[3] = "Way Of The Current - Middle Tree Arcstrider";
    hClass[4] = "Way Of The Trapper - Top Tree Nightstalker";
    hClass[5] = "Way Of The Wraith - Middle Tree Nightstalker";
    hClass[6] = "Way Of The Wind - Bottom Tree Arcstrider";
    hClass[7] = "Way Of The Sharpshooter - Bottom Tree Gunslinger";
    hClass[8] = "Revenant";
    hClass[9] = "Way Of The Pathfinder - Bottom Tree Nightstalker";

    std::string * tClass = new std::string [subclassSize];
    tClass[0] = "Code Of The Aggressor - Bottom Tree Sentinel";
    tClass[1] = "Code Of The Devastator - Middle Tree Sunbreaker";
    tClass[2] = "Code Of The Juggernaut - Bottom Tree Striker";
    tClass[3] = "Code Of The Earthshaker - Top Tree Striker";
    tClass[4] = "Code Of The Fire-Forged - Top Tree Sunbreaker";
    tClass[5] = "Code Of The Commander - Middle Tree Sentinel";
    tClass[6] = "Behemoth";
    tClass[7] = "Code Of The Siegebreaker - Bottom Tree Sunbreaker";
    tClass[8] = "Code Of The Protector - Top Tree Sentinel";
    tClass[9] = "Code Of The Missile - Middle Tree Striker";
    /////////////////////////////////////////////////////
    /////////////////////////////////////////////////////

    // Program loop
    char input = 'a';
    while (input != 'x' && input != 'X'){
        std::cout << "Please enter what letter corresponds to your class or enter 'x' to exit the program...\n" << std::endl;
        std::cout << "[H]unter - [T]itan - [W]arlock" << std::endl;

        // User input
        input = userInput();

        // Checking to see if user wants to leave
        if(input == 'x'){
            break;
        }

        // Shows the randomized subclass based on the selected class
        showClass(input, wClass, tClass, hClass, subclassSize);

        // Shows the randomized weapons
        showWeapons(primaries, specials, heavies, primariesSize, specialsSize, heaviesSize);

        // Shows the randomized mods
        showMods(mods, modsSize);

        // Shows the randomized activities
        showActivity(activity, activitySize);

        // Checks to see if the user wants to exit or continue
        if (exitInput()){
            break;
        }
    }

    /////////////////////////////////////////////////////
    // Memory De-allocation
    delete[] mods;
    delete[] activity;
    delete[] primaries;
    delete[] specials;
    delete[] heavies;
    delete[] wClass;
    delete[] hClass;
    delete[] tClass;
    mods = nullptr;
    activity = nullptr;
    primaries = nullptr;
    specials = nullptr;
    heavies = nullptr;
    wClass = nullptr;
    hClass = nullptr;
    tClass = nullptr;
    /////////////////////////////////////////////////////
}

// Checks to see if the user wants to exit or continue
bool exitInput(){
    char exitInput = 'a';

    // Asking to exit or go again
    std::cout << std::endl;
    std::cout << "Would you like to roll again? Press 'X' to exit, or anything else to roll again..." << std::endl;
    exitInput = getch();
    exitInput = tolower(exitInput);
    if (exitInput == 'x'){
        return true;
    }
    else{
        system("cls");
    }
    return false;
}

// Takes input from user until they enter a valid input
char userInput(){
    char input = getch();
    input = tolower(input);

    // While the character is invalid
    while (input != 'h' && input != 't' && input != 'w' && input != 'x'){

        system("cls");
        std::cout << "Sorry, thats not an 'H', 'T', 'W', or 'X'..." << std::endl;
        std::cout << "Please try again..." << std::endl;
        std::cout << "Please enter what letter corresponds to your class or enter 'x' to exit the program...\n" << std::endl;
        std::cout << "[H]unter - [T]itan - [W]arlock" << std::endl;

        // Take input
        input = getch();
        input = tolower(input);
        system("cls");

        // If the new input is valid, break, if not, keep asking
        if (!(input != 'h' && input != 't' && input != 'w' && input != 'x')){
            break;
        }
    }

    // Return the valid input
    return input;
}

// Shows the randomized subclass based on what class was chosen
void showClass(char input, std::string* wClass, std::string* tClass, std::string* hClass, int size){
    // Random seed for the modern random engine
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();

    // Random engine
    std::default_random_engine eng(seed);

    // Random number to put into the array
    int num = eng() % size;

    // Printing
    std::cout << "Your subclass today will be: ";
    if (input == 'w'){
        std::cout << wClass[num] << std::endl;
    }
    else if (input == 't'){
        std::cout << tClass[num] << std::endl;
    }
    else if(input == 'h'){
        std::cout << hClass[num] << std::endl;
    }
    else{
        std::cout << "Input Error" << std::endl;
    }
    std::cout << std::endl;
}

// Shows the random weapon types
// PLANNING ON MAKING THIS A LOT BETTER - feels basic right now idk
void showWeapons(std::string* primaries, std::string* specials, std::string* heavies, int pSize, int sSize, int hSize){
    // Random seed for the modern random engine
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();

    // Random engine
    std::default_random_engine eng(seed);

    // Random numbers to put into the arrays
    int primaryNum = eng() % pSize;
    int specialNum = eng() % sSize;
    int heavyNum = eng() % hSize;

    // Printing
    std::cout << "Today your PRIMARY weapon will be a: " << primaries[primaryNum] << std::endl;
    std::cout << "Today your SPECIAL weapon will be a: " << specials[specialNum] << std::endl;
    std::cout << "Today your HEAVY weapon will be a: " << heavies[heavyNum] << std::endl;
    std::cout << std::endl;
}

// Shows the random mod types
// PLANNING ON MAKING THIS A LOT BETTER - feels basic right now idk
void showMods(std::string* mods, int size){
    // Random seed for the modern random engine
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();

    // Random engine
    std::default_random_engine eng(seed);

    // Random number to put into the array
    int num = eng() % size;

    // Printing
    std::cout << "Today your combat/resist mods will ONLY be: " << mods[num] << std::endl;
    std::cout << "stat mods/finders/scavs etc allowed" << std::endl;
    if (num == 0){
        std::cout << "No Wells - No Resist" << std::endl;
        std::cout << "NO PROTECTIVE" << std::endl;
    }
    else if (num == 1){
        std::cout << "No Charged with Light - No Resist" << std::endl;
    }
    else if (num == 2){
        std::cout << "No Charged with Light - No Wells" << std::endl;
    }
    std::cout << std::endl;
}

// Shows the random activty
// PLANNING ON ADDING ACTIVITES BUT IDK WHAT - no content sadge - maybe master NFs ???? would be annoying to code it to acocunt for champ mods
void showActivity(std::string* activities, int size){
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    int num = eng() % size;

    std::cout << "Today your activity will be: " << activities[num] << std::endl;
}