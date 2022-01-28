// Created by: Podio
// 26/01/2022

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <random>
#include <chrono>

// Declarations
int main();
void showClass(char, std::string*, std::string*, std::string*, int, int&);
void showWeapons(std::string*, std::string*, std::string*, int, int, int, int&, int&, int&);
void showMods(std::string*, int, int&);
void showActivity(std::string*, int, int&);
char userInput();
bool exitInput();
std::string* readFile(std::string);
int getSize(std::string);
bool reroll(int&, int&, int&, int&, int&, int&);

// Global variable, I know Im sorry, i didnt want to go through the hassle of passing it around everywhere :(
double difficulty = 0;

int main(){
    system("cls");
    std::cout << "Preparing Files..." << std::endl;

    // All txt filenames
    std::string modFile = "mods.txt";
    std::string activityFile = "activities.txt";
    std::string primaryFile = "primaries.txt";
    std::string specialFile = "specials.txt";
    std::string heavyFile = "heavies.txt";
    std::string wFile = "wSubclasses.txt";
    std::string hFile = "hSubclasses.txt";
    std::string tFile = "tsubClasses.txt";

    // Sizes for all arrays - would use std::size_t but too lazy
    int modsSize = getSize(modFile);
    int activitySize = getSize(activityFile);
    int primariesSize = getSize(primaryFile);
    int specialsSize = getSize(specialFile);
    int heaviesSize = getSize(heavyFile);
    int wSize = getSize(wFile); 
    int hSize = getSize(hFile);
    int tSize = getSize(tFile);

    // Filling arrays from files
    std::cout << "Loading Data..." << std::endl;
    std::string * mods = readFile(modFile);
    std::string * activity = readFile(activityFile);
    std::string * primaries = readFile(primaryFile);
    std::string * specials = readFile(specialFile);
    std::string * heavies = readFile(heavyFile);
    std::string * wClass = readFile(wFile);
    std::string * hClass = readFile(hFile);
    std::string * tClass = readFile(tFile);

    /*
    /////////////////////////////////////////////////////
    // Storing all missions/mods etc in arrays
    std::sstring * mods = new std::string [modsSize];
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
    tClass[9] = "Code Of The Missile - Middle Tree Striker";*/
    /////////////////////////////////////////////////////
    /////////////////////////////////////////////////////

    //system("cls");
    // Program loop
    char input = 'a';
    int subclassSize = 0;

    // bool classReroll = false;
    // bool activityReroll = false;
    // bool primaryReroll = false;
    // bool specialReroll = false;
    // bool heavyReroll = false;
    // bool heavyReroll = false;
    // bool heavyReroll = false;
    // bool heavyReroll = false;

    int classReroll = -1;
    int activityReroll = -1;
    int primaryReroll = -1;
    int specialReroll = -1;
    int heavyReroll = -1;
    int modReroll = -1;

    while (input != 'x' && input != 'X'){
        std::cout << "Please enter what letter corresponds to your class or enter 'x' to exit the program...\n" << std::endl;
        std::cout << "[H]unter - [T]itan - [W]arlock" << std::endl;

        // User input
        input = userInput();

        // Checking to see if user wants to leave
        if(input == 'x'){
            break;
        }

        if (input == 'w'){
            subclassSize = wSize;
        }
        else if (input == 'h'){
            subclassSize = hSize;
        }
        else if (input == 't'){
            subclassSize = tSize;
        }

        classReroll = -1;
        activityReroll = -1;
        primaryReroll = -1;
        specialReroll = -1;
        heavyReroll = -1;
        modReroll = -1;

        do{
        
        // Shows the randomized subclass based on the selected class
        showClass(input, wClass, tClass, hClass, subclassSize, classReroll);

        // Shows the randomized weapons
        showWeapons(primaries, specials, heavies, primariesSize, specialsSize, heaviesSize, primaryReroll, specialReroll, heavyReroll);

        // Shows the randomized mods
        showMods(mods, modsSize, modReroll);

        // Shows the randomized activities
        showActivity(activity, activitySize, activityReroll);

        difficulty /= 6;
        std::cout << std::endl;
        std::cout << "The approximate difficulty of this challenge is: " << difficulty << "/5 - " << difficulty*20 << "%" << std::endl;
        }
        while(reroll(classReroll, activityReroll, primaryReroll, specialReroll, heavyReroll, modReroll));

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

    return 0;
}

bool reroll(int& subclass, int& activity, int& primary, int& special, int& heavy, int& mods){
    char input = 'q';
    std::cout << std::endl;
    std::cout << "Would you like to reroll a specific category? Or press [X] to skip..." << std::endl;
    std::cout << "[C]Subclass - [A]ctivity - [P]rimary - [S]pecial - [H]eavy - [M]ods" << std::endl;

    input = getch();
    input = tolower(input);

    if(input != 'c' && input != 'a' && input != 'p' && input != 's'&& input != 'h'&& input != 'm'){
        subclass = -1;
        activity = -1;
        primary = -1;
        special = -1;
        heavy = -1;
        mods = -1;
        return false;
    }
    else if(input == 'c'){
        subclass = -1;
    }
    else if(input == 'a'){
        activity = -1;
    }
    else if(input == 'p'){
        primary = -1;
    }
    else if(input == 's'){
        special = -1;
    }
    else if(input == 'h'){
        heavy = -1;
    }
    else if(input == 'm'){
        mods = -1;
    }
    system("cls");
    return true;
}

int calculateDifficulty(std::string thing){

    // File names
    std::string level5File = "level5.txt";
    std::string level4File = "level4.txt";
    std::string level3File = "level3.txt";
    std::string level2File = "level2.txt";
    std::string level1File = "level1.txt";

    // Sizes
    int level5Size = getSize(level5File);
    int level4Size = getSize(level4File);
    int level3Size = getSize(level3File);
    int level2Size = getSize(level2File);
    int level1Size = getSize(level1File);

    // Reading into arrays
    std::string* level5 = readFile(level5File);
    std::string* level4 = readFile(level4File);
    std::string* level3 = readFile(level3File);
    std::string* level2 = readFile(level2File);
    std::string* level1 = readFile(level1File);
    /////////////////////////////////////////////

    std::string** bigArray = new std::string* [5];
    bigArray[0] = level1;
    bigArray[1] = level2;
    bigArray[2] = level3;
    bigArray[3] = level4;
    bigArray[4] = level5;

    int * sizes = new int [5];
    sizes[0] = level1Size;
    sizes[1] = level2Size;
    sizes[2] = level3Size;
    sizes[3] = level4Size;
    sizes[4] = level5Size;

    for (int i = 0 ; i < 5 ; i++){

        for (int j = 0 ; j < sizes[i] ; j++){

            if ( thing == (bigArray[i])[j] ){
                return i+1;
            }
        }
    }

    /////////////////////////////////////////////
    // Memory De-allocation
    delete[] level5;
    delete[] level4;
    delete[] level3;
    delete[] level2;
    delete[] level1;
    delete[] sizes;
    delete[] bigArray;
    level5 = nullptr;
    level4 = nullptr;
    level3 = nullptr;
    level2 = nullptr;
    level1 = nullptr;
    sizes = nullptr;
    bigArray = nullptr;

    return 0;
}

bool isPresent(std::string* array, std::string word, int size){
    for (int i = 0 ; i < size ; i++){

        if (word == array[i]){
            return true;
        }
    }
    return false;
}

std::string* readFile(std::string filename){

    // Variables
    int size = 0;
    std::fstream file;
    file.open(filename,std::ios::in); //open a file to perform read operation using file object
    
    size = getSize(filename);
    // std::cout << "size: " << size << std::endl;

    std::string * mods = new std::string [size];
    
    if (file.is_open()){   //checking whether the file is open
        for (int i = 0 ; i < size ; i++){
            getline(file, mods[i]); //read data from file object and put it into string.  
        }
        file.close(); //close the file object.
    }
    return mods;
}

int getSize(std::string filename){

    int size = 0;
    std::string temp;
    std::fstream file;

    file.open(filename,std::ios::in); //open a file to perform read operation using file object

    if (file.is_open()){   //checking whether the file is open
        while(getline(file, temp)){
            size++; //read data from file object and put it into string.  
        }
        file.close(); //close the file object.
    }
    //std::cout << size << std::endl;
    return size;
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
void showClass(char input, std::string* wClass, std::string* tClass, std::string* hClass, int size, int & reroll){
    // Random seed for the modern random engine
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();

    // Random engine
    std::default_random_engine eng(seed);

    // Random number to put into the array
    int num = 0;
    if (reroll == -1){
        num = eng() % size;
        reroll = num;
    }
    else{
        num = reroll;
    }

    // Printing
    std::cout << "Your subclass today will be: ";
    if (input == 'w'){
        std::cout << wClass[num] << std::endl;
        difficulty += calculateDifficulty(wClass[num]);
    }
    else if (input == 't'){
        std::cout << tClass[num] << std::endl;
        difficulty += calculateDifficulty(tClass[num]);
    }
    else if(input == 'h'){
        std::cout << hClass[num] << std::endl;
        difficulty += calculateDifficulty(hClass[num]);
    }
    else{
        std::cout << "Input Error" << std::endl;
    }
    std::cout << std::endl;
}

// Shows the random weapon types
// PLANNING ON MAKING THIS A LOT BETTER - feels basic right now idk
void showWeapons(std::string* primaries, std::string* specials, std::string* heavies, int pSize, int sSize, int hSize, int& pReroll, int& sReroll, int& hReroll){
    // Random seed for the modern random engine
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();

    // Random engine
    std::default_random_engine eng(seed);

    // Random numbers to put into the arrays
    int primaryNum = 0;
    int specialNum = 0;
    int heavyNum = 0;

    // Primary
    if (pReroll == -1){
        primaryNum = eng() % pSize;
        pReroll = primaryNum;
    }
    else{
        primaryNum = pReroll;
    }

    // Special
    if (sReroll == -1){
        specialNum = eng() % sSize;
        sReroll = specialNum;
    }
    else{
        specialNum = sReroll;
    }

    // Heavy
    if (hReroll == -1){
        heavyNum = eng() % hSize;
        hReroll = heavyNum;
    }
    else{
        heavyNum = hReroll;
    }

    // Printing
    std::cout << "Today your PRIMARY weapon will be a: " << primaries[primaryNum] << std::endl;
    std::cout << "Today your SPECIAL weapon will be a: " << specials[specialNum] << std::endl;
    std::cout << "Today your HEAVY weapon will be a: " << heavies[heavyNum] << std::endl;
    std::cout << std::endl;

    // Difficulty
    difficulty += calculateDifficulty(primaries[primaryNum]);
    difficulty += calculateDifficulty(specials[specialNum]);
    difficulty += calculateDifficulty(heavies[heavyNum]);
}

// Shows the random mod types
// PLANNING ON MAKING THIS A LOT BETTER - feels basic right now idk
void showMods(std::string* mods, int size, int& reroll){
    // Random seed for the modern random engine
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();

    // Random engine
    std::default_random_engine eng(seed);

    // Random number to put into the array
    int num = 0;
    if (reroll == -1){
        num = eng() % size;
        reroll = num;
    }
    else{
        num = reroll;
    }
    // std::cout << num << std::endl;

    // Printing
    std::cout << "Today your combat/resist mods will ONLY be: " << mods[num] << std::endl;
    std::cout << "stat mods/finders/scavs etc allowed" << std::endl;
    // if (num == 0){
    //     std::cout << "No Wells - No Resist" << std::endl;
    //     std::cout << "NO PROTECTIVE" << std::endl;
    // }
    // else if (num == 1){
    //     std::cout << "No Charged with Light - No Resist" << std::endl;
    // }
    // else if (num == 2){
    //     std::cout << "No Charged with Light - No Wells" << std::endl;
    // }
    // else{
    //     std::cout << "test" << std::endl;
    // }

    // Prints every mod type not allowed
    for (int i = 0 ; i < size ; i++){

        if (i != num){

            std::cout << "No " << mods[i] << " - ";
        }
    }
    std::cout << "NO PROTECTIVE!!!" << std::endl;
    std::cout << std::endl;

    difficulty += calculateDifficulty(mods[num]);
}

// Shows the random activty
// PLANNING ON ADDING ACTIVITES BUT IDK WHAT - no content sadge - maybe master NFs ???? would be annoying to code it to acocunt for champ mods
void showActivity(std::string* activities, int size, int& reroll){
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    int num = 0;
    if (reroll == -1){
        num = eng() % size;
        reroll = num;
    }
    else{
        num = reroll;
    }

    std::cout << "Today your activity will be: " << activities[num] << std::endl;

    difficulty += calculateDifficulty(activities[num]);
}