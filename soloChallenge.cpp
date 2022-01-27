#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <random>
#include <chrono>

int main();
void showClass(char, std::string*, std::string*, std::string*);
void showWeapons(std::string*, std::string*, std::string*);
void showMods(std::string*);
void showActivity(std::string*);


int main(){
    // Random number testing
    // unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    // std::default_random_engine eng(seed);

    // int num1 = -1;
    // for (int i = 0 ; i < 11 ; i++){
    //     while (num1 != i){
    //         num1 = eng() % 10;
    //         std::cout << num1 << std::endl;
    //     }
    //     std::cout << "====================== ^^ i: " << i << std::endl;
    // 
    // int num1 = -1;
    // for (int i = 0 ; i < 11 ; i++){
    //     std::default_random_engine generator;
    //     std::uniform_int_distribution<int> distribution(0,10);
    //     while (num1 != i){
    //         num1 = distribution(generator);  // generates number in the range 1..6 
    //         std::cout << num1 << std::endl;
    //     }
    //     std::cout << "====================== ^^ i: " << i << std::endl;
    // }
    
    ////////////////////////////////////////////
    std::string * mods = new std::string [3];
    mods[0] = "Charged With Light";
    mods[1] = "Wells";
    mods[2] = "Resist";

    std::string * activity = new std::string [6];
    activity[0] = "Prophecy";
    activity[1] = "Pit of Heresy";
    activity[2] = "Grasp of Avarice";
    activity[3] = "Shattered Throne";
    activity[4] = "Presage";
    activity[5] = "Harbinger";

    std::string * primaries = new std::string [6];
    primaries[0] = "Weapon of your Choice";
    primaries[1] = "SMG";
    primaries[2] = "Hand Cannon";
    primaries[3] = "Auto Rifle";
    primaries[4] = "Pulse Rifle";
    primaries[5] = "Bow";

    std::string * specials = new std::string [6];
    specials[0] = "Weapon of your Choice";
    specials[1] = "Slug Shotgun";
    specials[2] = "Pellet Shotgun";
    specials[3] = "Grenade Launcher";
    specials[4] = "Sniper Rifle";
    specials[5] = "Fusion Rifle";

    std::string * heavies = new std::string [6];
    heavies[0] = "Weapon of your Choice";
    heavies[1] = "Rocket Launcher";
    heavies[2] = "Grenade Launcher";
    heavies[3] = "Machine Gun";
    heavies[4] = "Sword";
    heavies[5] = "Linear Fusion Rifle";

    std::string * wClass = new std::string [10];
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

    std::string * hClass = new std::string [10];
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

    std::string * tClass = new std::string [10];
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

    // Program loop
    char input = 'a';
    char exitInput = 'a';
    while (input != 'x' && input != 'X'){
        std::cout << "Please enter what letter corresponds to your class or enter 'x' to exit the program...\n" << std::endl;
        std::cout << "[H]unter - [T]itan - [W]arlock" << std::endl;

        // std::cin >> input;
        input = getch();
        // std::cout << "-" << input << "-" << std::endl;
        input = tolower(input);

        while (input != 'h' && input != 't' && input != 'w' && input != 'x'){

            std::cout << "Sorry, thats not an 'H', 'T', 'W', or 'X'..." << std::endl;
            std::cout << "Please try again..." << std::endl;

            // std::cin >> input;
            input = getch();
            input = tolower(input);
            system("cls");

            if (!(input != 'h' && input != 't' && input != 'w' && input != 'x')){
                break;
            }
        }

        //std::cout << "test: " << input << std::endl;
        if(input == 'x'){
            break;
        }

        showClass(input, wClass, tClass, hClass);
        showWeapons(primaries, specials, heavies);
        showMods(mods);
        showActivity(activity);

        // Asking to exit or go again
        std::cout << std::endl;
        std::cout << "Would you like to roll again? Press 'X' to exit, or anything else to roll again..." << std::endl;
        exitInput = getch();
        exitInput = tolower(exitInput);
        if (exitInput == 'x'){
            break;
        }
        else{
            system("cls");
        }
    }

    /////////////////////////////////////////////////////
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
}

void showClass(char input, std::string* wClass, std::string* tClass, std::string* hClass){
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    int num = eng() % 10;

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
        std::cout << "Error Finding Subclass" << std::endl;
    }
    std::cout << std::endl;
}

void showWeapons(std::string* primaries, std::string* specials, std::string* heavies){
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);

    int primaryNum = eng() % 6;
    int specialNum = eng() % 6;
    int heavyNum = eng() % 6;

    std::cout << "Today your PRIMARY weapon will be a: " << primaries[primaryNum] << std::endl;
    std::cout << "Today your SPECIAL weapon will be a: " << specials[specialNum] << std::endl;
    std::cout << "Today your HEAVY weapon will be a: " << heavies[heavyNum] << std::endl;
    std::cout << std::endl;
}

void showMods(std::string* mods){
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    int num = eng() % 3;

    std::cout << "Today your combat/resist mods will ONLY be: " << mods[num] << std::endl;
    std::cout << "stat mods/finders/scavs etc allowed" << std::endl;
    if (num == 0){
        std::cout << "NO PROTECTIVE" << std::endl;
    }
    std::cout << std::endl;
}

void showActivity(std::string* activities){
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    int num = eng() % 6;

    std::cout << "Today your activity will be: " << activities[num] << std::endl;
}