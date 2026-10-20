// CSCI1300 Fall 2022
// Author: Harrison Perlstein and Robby Toomey
// CSCI 1300-307 TA: Zachary Atkins
// Project 3 - Dungeon Escape - Main Menu Class

#include "MainMenu.h"
#include "Map.h"
#include "Party.h"
#include "Player.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;
 
MainMenu::MainMenu(){
    sorcerors_anger = 0;
}
int MainMenu::getSorcerorsAnger(){
    return sorcerors_anger;
}
 
void MainMenu::beginGame(Party& p_in){
    string partyLeader;
    string players[5];
    for(int i = 0; i < 50; i++){ //just adding some space between compiling and execution for it to look nice
        cout << endl;
    }
    cout << "Hello, and welcome to Dungeon Escape!" << endl;
    cout << "In this game, you will navigate through a dungeon, attempting to clear all 5 rooms" << endl;
    cout << "To win this game, you must beat the sorceror in the 5th and final room and exit the dungeon" << endl;

    //adds all players to the party
    cout << "Now, to start. What is your name?" << endl;
    cin >> partyLeader;
    Player leader(partyLeader);
    p_in.addPlayer(leader);
    cout << partyLeader << " an excellent name for a leader. Now, who will you be traveling with?" << endl;
    for(int i = 0; i < 4; i++){
        string temp;
        cout << "Enter traveler " << i+2 << "'s name: ";
        cin >> players[i];
        Player a(players[i]);
        p_in.addPlayer(a);
    }
    p_in.setPartyLeader();
  
    char tutorial;
    //gives info about the world
    cout << endl;
    cout << "Would you like a brief rundown of how this dungeon works? (y/n)" << endl;
    cin >> tutorial;
    if(tutorial == 'y'){
        cout << endl;
        cout << "In this dungeon, spaces are marked differently based on how you can interact with them" << endl; //print message
        cout << "Spaces marked with '-' are normal spaces" << endl;
        cout << "Spaces marked 'N' are spaces that hold the wandering merchant" << endl;
        cout << "Spaces marked 'R' contain a room" << endl;
        cout << "The space marked 'E' is the dungeon exit" << endl;
        cout << "Every turn, there will be a status update of your party" << endl;
        cout << "If you look, you will see the sorcerors anger as one part of the status" << endl;
        cout << "If the sorcerors anger reaches 100, he will blow up the dungeon and the game will end" << endl;
        cout << "If all of your party members die, you will lose the game" << endl;
        cout << "If you die to hunger, you will lose the game" << endl;
        cout << "Many times throughout the dungeon, you will find the merchant who you can buy items from to help you" << endl;
        cout << "Would you like to hear more information? (y/n)" << endl;
        char moreIns;
        while(!(cin >> moreIns) || (moreIns != 'y' && moreIns != 'n')){
            cout << "You must type y or n and then enter to continue" << endl;
        }
        cout << endl;
        if(moreIns == 'y'){
            cout << "To enter a room space, you must either posess a key or win a game of rock paper scissors vs the AI" << endl; //print message
            cout << "If you fail rock paper scissors, you are forced into a fight with a monster" << endl;
            cout << "In addition, you are not able to enter that room until you either get a key or win rock paper scissors" << endl;
            cout << "Keys are found by investigating spaces and beating monsters" << endl;
            cout << "Battling a monster involves a complex equation. Your chances of winning increase based on weapons and armor" << endl;
            cout << "Wandering merchant spaces are hidden until you walk over them. To buy items from the merchant, you must answer a riddle" << endl;
            cout << "Answer the riddle incorrectly and you must fight a monster yet again" << endl;
            cout << "Every turn, there is a large chance for a random misfortune to occur which will damage your party" << endl; 
            cout << "That's all the information I have for you. Press y and then enter when you are ready to start" << endl;
            char start;
            while(!(cin >> start) || (start != 'y')){
                cout << "Please enter y to start the game." << endl;
            }
        }
    }
    cout << endl;
    cout << "Ok then, let's get right into it!" << endl; //print message
    cout << endl;
    cout << "Between the 5 of you, you have 100 gold pieces. " <<endl;
    cout << " You will need to spend the some of your money on the following items:" <<endl;
    cout <<endl;
    cout << " - INGREDIENTS. To make food, you have to cook raw ingredients." <<endl;
    cout << " - COOKWARE. If you want to cook, you have to have cookware first." <<endl;
    cout << " - WEAPONS. You'll want at least one weapon per party member to fend off monsters." <<endl;
    cout << " - ARMOR. Armor increases the chances of surviving a monster attack." <<endl;
    cout <<endl; 
    cout << " You can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way. " <<endl;
    cout << " But beware, some of the merchants in this dungeon are shady characters, and they won't always give you a fair price..." <<endl;
    merchantCom(p_in);
}
 
void MainMenu::displayStatus(Party& p_in){
    cout << "+-------------+" << endl;
    cout << "| STATUS      |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Rooms Cleared: " << p_in.getRoomsCleared() << " | Keys: " << p_in.getKeysFound() << " | Anger Level: " << sorcerors_anger << endl;
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << p_in.gold_count() << endl;
    cout << "| Ingredients | " << p_in.ingredients_count() << " kg" << endl;
    cout << "| Cookware    | P: " << p_in.ceramic_pot_count() << " | F: " << p_in.frying_pan_count() << " | C: " << p_in.cauldron_count() << endl;
    cout << "| Weapons     | C: " << p_in.stone_club_count() <<  "| S: " << p_in.iron_spear_count() << "| R: " << p_in.mythril_rapier_count() << "| B: " << p_in.flaming_battle_ax_count() << "| L: " << p_in.vorpal_longsword_count() << endl;
    cout << "| Armor       | " << p_in.armor_count() << endl;
    cout << "| Treasures   | R: " << p_in.silver_ring_count() << "| N: " << p_in.ruby_necklace_count() << "| B: " << p_in.emerald_bracelet_count() << "| C: " << p_in.diamond_circlet_count() << "| G: " << p_in.gem_encrusted_goblet_count() << endl;
    cout << "+-------------+" << endl;
    cout << "| PARTY       |" << endl;
    cout << "+-------------+" << endl;
    p_in.sort();
    cout << "+-------------+" << endl;
}
 
void MainMenu::moveHelper(Map& m_in){
    char direction;
    cout << "What direction would you like to move in? (w, a, s, d)" << endl; //print message
    cin >> direction;
    while(direction != 'a' && direction != 'w' && direction != 's' && direction != 'd'){ //makes sure direction is right
        cout << "Please enter either w, a, s, or d" << endl; //print message
        cout << "What direction would you like to move in? (w, a, s, d)" << endl;
        cin >> direction;
    }
    while(!m_in.move(direction)){
        cout << "You cannot move in that direction. Please try again." << endl; //print message
        cout << "What direction would you like to move in? (w, a, s, d)" << endl;
        cin >> direction;
    }
    return;
}
 
void MainMenu::loseFullness(int chance, int amount, Party& p_in){
    //50% chance to lose 1 fullness
    int newRandom = 0;
    srand(time(0));
    for(int i = 0; i < 5; i++){
        newRandom = rand()%101;
        if(p_in.getPlayerNameAtIndex(i) == "dead"){
            continue;
        }
        if(newRandom < chance){
            cout << p_in.subtractFullnessAtIndex(amount, i) << " has lost 1 fullness." << endl;
        }
    }
}
 
void MainMenu::merchantCom(Party& name)
{
    bool first_time = true; //declare variables
    int option = 0;
    double multiplier = 0;
    for (int i = 0; i < 6; i++) //loop to determine multiplier value for prices depending on the amount of rooms cleared
    {
        if (name.getRoomsCleared() == i) //find the number of rooms cleared
        {
            multiplier = 1 + i/4.0; //set the multiplier depending on the amount of rooms cleared
        }
    }
    while (option > 0 && option < 7 || first_time) //free one time entrance to loop that runs menu
    {
        first_time = false; //set bool to false for no more free entry
        cout << endl;
        cout << "If you're looking to get supplies, you've come to the right place." <<endl; //print menu
        cout << "I would be happy to part with some of my wares...for the proper price!" <<endl;
        cout << endl;
        cout << "+-------------+" <<endl;
        cout << "|  INVENTORY  |" <<endl;
        cout << "+-------------+" <<endl;
        cout << "| Gold        | " << name.gold_count() <<endl;
        cout << "| Ingredients | " << name.ingredients_count() <<endl;
        cout << "| Cookware    | P: " << name.ceramic_pot_count() << " | F: " << name.frying_pan_count() << " | C: " << name.cauldron_count() <<endl;
        cout << "| Weapons     | C: " << name.stone_club_count() << " | S: " << name.iron_spear_count() << " | R: " << name.mythril_rapier_count() << " | B: " << name.flaming_battle_ax_count() << " | L: " << name.vorpal_longsword_count() <<endl;
        cout << "| Armor       | " << name.armor_count() <<endl;
        cout << "| Treasures   | R: " << name.silver_ring_count() << " | N: " << name.ruby_necklace_count() << " | B: " << name.emerald_bracelet_count() << " | C: " << name.diamond_circlet_count() << " | G: " << name.gem_encrusted_goblet_count() <<endl;
        cout <<endl;
        cout << "Choose one of the following:" <<endl;
        cout << "1. Ingredients: To make food, you have to cook raw ingredients." <<endl;
        cout << "2. Cookware: You will need something to cook those ingredients." <<endl;
        cout << "3. Weapons: It's dangerous to go alone, take this!" <<endl;
        cout << "4. Armor: If you want to survive monster attacks, you will need some armor." <<endl;
        cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." <<endl;
        cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!" <<endl;
        cin >> option; //recieve user input
        while (option < 1 || option > 6) //loop to run until valid input is entered
        {
            cout << endl;
            cout << "Invalid input. Please enter 1-6." <<endl; //inform user of invalid input
            cout << endl;
            cout << "If you're looking to get supplies, you've come to the right place." <<endl; //print menu
            cout << "I would be happy to part with some of my wares...for the proper price!" <<endl;
            cout << endl;
            cout << "+-------------+" <<endl;
            cout << "|  INVENTORY  |" <<endl;
            cout << "+-------------+" <<endl;
            cout << "| Gold        | " << name.gold_count() <<endl;
            cout << "| Ingredients | " << name.ingredients_count() <<endl;
            cout << "| Cookware    | P: " << name.ceramic_pot_count() << " | F: " << name.frying_pan_count() << " | C: " << name.cauldron_count() <<endl;
            cout << "| Weapons     | C: " << name.stone_club_count() << " | S: " << name.iron_spear_count() << " | R: " << name.mythril_rapier_count() << " | B: " << name.flaming_battle_ax_count() << " | L: " << name.vorpal_longsword_count() <<endl;
            cout << "| Armor       | " << name.armor_count() <<endl;
            cout << "| Treasures   | R: " << name.silver_ring_count() << " | N: " << name.ruby_necklace_count() << " | B: " << name.emerald_bracelet_count() << " | C: " << name.diamond_circlet_count() << " | G: " << name.gem_encrusted_goblet_count() <<endl;
            cout <<endl;
            cout << "Choose one of the following:" <<endl;
            cout << "1. Ingredients: To make food, you have to cook raw ingredients." <<endl;
            cout << "2. Cookware: You will need something to cook those ingredients." <<endl;
            cout << "3. Weapons: It's dangerous to go alone, take this!" <<endl;
            cout << "4. Armor: If you want to survive monster attacks, you will need some armor." <<endl;
            cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." <<endl;
            cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!" <<endl;
            cin >> option; //recieve user input
        }
        if (option == 1) //menu option 1
        {
            int kg; //declare variables
            char answer;
            cout << "How many kg of ingredients do you need [" << multiplier << "Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)" <<endl; //prompt for user input
            cout << "I recommend you to purchase at least 10 kg of ingredients per person." <<endl;
            cin >> kg; //recieve user input
            if (kg == 0) //check for condition to cancel
            {
                continue; //return to main menu
            }
            while (kg % 5 != 0) //loop to run until valid input is recieved
            {
                cout << "Enter a positive mulitple of 5, or 0 to cancel." <<endl; //prompt for user input
                cin >> kg; //recieve user input
            }
            if (kg % 5 == 0) //check if input entered is a multiple of 5
            {
                cout << "You want to buy " << kg << "kg of ingredients for " << kg << "*" << multiplier << " Gold? (y/n)" <<endl; //prompt for user input
                cin >> answer; //recieve user input
                while (answer != 'y' && answer != 'n')
                {
                    cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                }
                if (answer == 'n') //checks to see if user responded no
                {
                    continue; //return to main menu
                }
                if (answer == 'y') //checks to see if user responded yes
                {
                    int test = name.gold_count(); //call getter function to check count
                    name.buy_ingredients(kg, name.getRoomsCleared()); //buy item
                    if (name.gold_count() == test) //tests to make sure the transaction went through
                    {
                        continue; //return to main menu
                    }
                    cout << "Thank you for your patronage!" <<endl; //print message
                    continue; //return to main menu
                }
            }
        }
        if (option == 2) //menu option 2
        {
            int choice = 0; //declare variables
            int number = 0;
            char answer;
            cout << endl;
            cout << "I have a several types of cookware, which one would you like?" <<endl; //print menu
            cout << "Each type has a different probability of breaking when used, marked with (XX%)." <<endl;
            cout <<endl;
            cout << "Choose one of the following:" <<endl;
            cout << "1. (25%) Ceramic Pot [2*" << multiplier << " Gold]" <<endl;
            cout << "2. (10%) Frying Pan [10*" << multiplier << " Gold]" <<endl;
            cout << "3. ( 2%) Cauldron [20*" << multiplier << " Gold]" <<endl;
            cout << "4. Cancel" <<endl;
            cin >> choice; //recieve user input
            while (choice < 1 && choice > 4)
            {
                cout << "Invalid input. Please enter 1-4." <<endl; //inform user of invalid input
                cout << "1. (25%) Ceramic Pot [2*" << multiplier << " Gold]" <<endl; //print menu
                cout << "2. (10%) Frying Pan [10*" << multiplier << " Gold]" <<endl;
                cout << "3. (2%) Cauldron [20*" << multiplier << " Gold]" <<endl;
                cout << "4. Cancel" <<endl;
                cin >> choice; //recieve user input
            }
            if (choice == 1) //menu choice 1
            {
                int test = name.ceramic_pot_count(); //call getter function to check count
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" <<endl; //prompt for user input
                cin >> number; //recieve user input
                while (number < 0) //runs loop to make sure a positive integer is entered
                {
                    cout << "Enter a positive integer, or 0 to cancel." <<endl; //prompt for user input
                    cin >> number; //recieve user input
                }
                if (number == 0) //check for condition to cancel
                {
                    continue; //return to main menu
                }
                if (number > 0) //checks that the number provided is above 0
                {
                    cout << "You want to buy " << number << " Ceramic Pot(s) for " << number * 2 << "*" << multiplier << "Gold? (y/n)" <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                    while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                    {
                        cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                        cin >> answer; //recieve user input
                    }
                    if (answer == 'n') //checks to see if user responded no
                    {
                        continue; //return to main menu
                    }
                    if (answer == 'y') //checks to see if user responded yes
                    {
                        name.buy_ceramic_pot(number, name.getRoomsCleared()); //buy item
                    }
                    if (name.ceramic_pot_count() == test) //tests to make sure the transaction went through
                    {
                        continue; //return to main menu
                    }
                }
                cout << "Thank you for your patronage!" <<endl; //print message
                continue; //return to main menu
            }
            if (choice == 2) //menu choice 2
            {
                int test = name.frying_pan_count(); //call getter function to check count
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" <<endl; //prompt for user input
                cin >> number; //recieve user input
                while (number < 0) //runs loop to make sure a positive integer is entered
                {
                    cout << "Enter a positive integer, or 0 to cancel." <<endl; //prompt for user input
                    cin >> number; //recieve user input
                }
                if (number == 0) //check for condition to cancel
                {
                    continue; //return to main menu
                }
                if (number > 0) //checks that the number provided is above 0
                {
                    cout << "You want to buy " << number << " Frying Pan(s) for " << number * 10 << "*" << multiplier << "Gold? (y/n)" <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                    while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                    {
                        cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                        cin >> answer; //recieve user input
                    }
                    if (answer == 'n') //checks to see if user responded no
                    {
                        continue; //return to main menu
                    }
                    if (answer == 'y') //checks to see if user responded yes
                    {
                        name.buy_frying_pan(number, name.getRoomsCleared()); //buy item
                    }
                    if (name.frying_pan_count() == test) //tests to make sure the transaction went through
                    {
                        continue; //return to main menu
                    }
                }
                cout << "Thank you for your patronage!" <<endl; //print message
                continue; //return to main menu
            }
            if (choice == 3) //menu choice 3
            {
                int test = name.cauldron_count(); //call getter function to check count
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" <<endl; //prompt for user input
                cin >> number; //recieve user input
                while (number < 0) //runs loop to make sure a positive integer is entered
                {
                    cout << "Enter a positive integer, or 0 to cancel." <<endl; //prompt for user input
                    cin >> number; //recieve user input
                }
                if (number == 0) //check for condition to cancel
                {
                    continue; //return to main menu
                }
                if (number > 0) //checks that the number provided is above 0
                {
                    cout << "You want to buy " << number << " Cauldron(s) for " << number * 20 << "*" << multiplier << "Gold? (y/n)" <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                    while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                    {
                        cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                        cin >> answer; //recieve user input
                    }
                    if (answer == 'n') //checks to see if user responded no
                    {
                        continue; //return to main menu
                    }
                    if (answer == 'y') //checks to see if user responded yes
                    {
                        name.buy_cauldron(number, name.getRoomsCleared()); //buy item
                    }
                    if (name.cauldron_count() == test) //tests to make sure the transaction went through
                    {
                        continue; //return to main menu
                    }
                }
                cout << "Thank you for your patronage!" <<endl; //print message
                continue; //return to main menu
            }
            if (choice == 4) //menu choice 4
            {
                continue; //return to main menu
            }
        }
        if (option == 3) //menu option 3
        {
            int check = name.weapon_count(); //call getter function to check count
            char swap; //declare variables
            char discard;
            if (check == name.getPartySize()) //check if the party has the max amount of weapons
            {
                cout << "You already have the max amount of weapons." <<endl; //print message
                cout << "Would you like to get rid of one of your current weapons in order to buy a better one? (y/n)" <<endl; //prompt for user input
                cin >> swap; //recieve input
                while (swap != 'n' && swap != 'y') //run loop until the user responds with y or n for yes or no
                {
                    cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                    cin >> swap; //recieve user input
                }
                if (swap == 'n') //check if user responded no
                {
                    continue; //return to main menu
                }
                if (swap == 'y') //check if user responded yes
                {
                    cout <<endl; //print message
                    cout << "You have "; //print message
                    if (name.stone_club_count() >= 1) //check if user has this weapon
                    {
                        if (name.stone_club_count() == name.getPartySize()) //check if this meets the max weapons
                        {
                            cout << name.stone_club_count() << " Stone Club(s)." <<endl; //print message
                        }
                        else
                        {
                            cout << name.stone_club_count() << " Stone Club(s), "; //print message
                        }
                    }
                    if (name.iron_spear_count() >= 1) //check if user has this weapon
                    {
                        if (name.stone_club_count() + name.iron_spear_count() == name.getPartySize()) //check if this meets the max weapons
                        {
                            cout << name.iron_spear_count() << " Iron Spear(s)." <<endl; //print message
                        }
                        else
                        {
                            cout << name.iron_spear_count() << " Iron Spear(s), "; //print message
                        }
                    }
                    if (name.mythril_rapier_count() >= 1) //check if user has this weapon
                    {
                        if (name.stone_club_count() + name.iron_spear_count() + name.mythril_rapier_count() == name.getPartySize()) //check if this meets the max weapons
                        {
                            cout << name.mythril_rapier_count() << " Mythril Rapier(s)." <<endl; //print message
                        }
                        else
                        {
                            cout << name.mythril_rapier_count() << " Mythril Rapier(s), "; //print message
                        }
                    }
                    if (name.flaming_battle_ax_count() >= 1) //check if user has this weapon
                    {
                        if (name.vorpal_longsword_count() >= 1)
                        {
                            cout << name.flaming_battle_ax_count() << " Flaming Battle Ax(es), and " << name.vorpal_longsword_count() << " Vorpal Longsword(s)." <<endl; //print message
                        }
                        if (name.stone_club_count() + name.iron_spear_count() + name.mythril_rapier_count() + name.flaming_battle_ax_count() == name.getPartySize()) //check if this meets the max weapons
                        {
                            cout << name.flaming_battle_ax_count() << " Flaming Battle Ax(es)." <<endl; //print message
                        }
                    }
                    if (name.vorpal_longsword_count() >= 1 && name.flaming_battle_ax_count() == 0) //check if user has this weapon and no flaming battle ax
                    {
                        cout << name.vorpal_longsword_count() << " Vorpal Longsword(s)." <<endl; //print message
                    }
                    cout <<endl; //print message
                    cout << "Which weapon would you like to discard? " <<endl; //print message
                    if (name.stone_club_count() >= 1) //check if user has this weapon
                    {
                        if (name.stone_club_count() == name.getPartySize()) //check if this meets the max weapons
                        {
                            cout << "Stone Club (s)." <<endl; //print message
                        }
                        else
                        {
                            cout << "Stone Club (s), "; //print message
                        }
                    }
                    if (name.iron_spear_count() >= 1) //check if user has this weapon
                    {
                        if (name.stone_club_count() + name.iron_spear_count() == name.getPartySize()) //check if this meets the max weapons
                        {
                            cout << "Iron Spear (i)." <<endl; //print message
                        }
                        else
                        {
                            cout << "Iron Spear (i), "; //print message
                        }
                    }
                    if (name.mythril_rapier_count() >= 1) //check if user has this weapon
                    {
                        if (name.stone_club_count() + name.iron_spear_count() + name.mythril_rapier_count() == name.getPartySize()) //check if this meets the max weapons
                        {
                            cout << "Mythril Rapier (m)." <<endl; //print message
                        }
                        else
                        {
                            cout << "Mythril Rapier (m), "; //print message
                        }
                    }
                    if (name.flaming_battle_ax_count() >= 1) //check if user has this weapon
                    {
                        if (name.vorpal_longsword_count() >= 1) //check if user has this weapon
                        {
                            cout << "Flaming Battle Ax (f), or Vorpal Longsword (v)." <<endl; //print message
                        }
                        if (name.stone_club_count() + name.iron_spear_count() + name.mythril_rapier_count() + name.flaming_battle_ax_count() == name.getPartySize()) //check if this meets the max weapons
                        {
                            cout << "Flaming Battle Ax (f)." <<endl; //print message
                        }
                    }
                    if (name.vorpal_longsword_count() >= 1 && name.flaming_battle_ax_count() == 0) //check if user has this weapon and no flaming battle ax
                    {
                        cout << "Vorpal Longsword (v)." <<endl; //print message
                    }
                    cin >> discard; //recieve user input
                    while (discard != 's' && discard != 'i' && discard != 'm' && discard != 'f' && discard != 'v') //run loop until the user responds with y or n for yes or no
                    {
                        cout << "Please enter 's', 'i', 'm', 'f', or 'v'."<<endl; //prompt for user input
                        cin >> discard; //recieve user input
                    }
                    if (discard == 's' && name.stone_club_count() >= 1) //check if user wanter to break stone club and has one to break
                    {
                        name.break_stone_club(); //break weapon
                    }
                    else if (discard == 'i' && name.iron_spear_count() >= 1) //check if user wanter to break iron spear and has one to break
                    {
                        name.break_iron_spear(); //break weapon
                    }
                    else if (discard == 'm' && name.mythril_rapier_count() >= 1) //check if user wanter to break mythril rapier and has one to break
                    {
                        name.break_mythril_rapier(); //break weapon
                    }
                    else if (discard == 'f' && name.flaming_battle_ax_count() >= 1) //check if user wanter to break flaming battle ax and has one to break
                    {
                        name.break_flaming_battle_ax(); //break weapon
                    }
                    else if (discard == 'v' && name.vorpal_longsword_count() >= 1) //check if user wanter to break vorpal longsword and has one to break
                    {
                        name.break_vorpal_longsword(); //break weapon
                    }
                    else
                    {
                        cout << "You dont have this weapon so you cannot discard it." <<endl; //print message
                        continue; //return to main menu
                    }
                }
            }
            int choice = 0; //declare variable
            cout <<endl;
            cout << "I have a plentiful collection of weapons to choose from, what would you like?" <<endl; //print menu
            cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." <<endl;
            cout <<endl;
            cout << "Choose one of the following:" <<endl;
            cout << "1. Stone Club [2*" << multiplier << " Gold]" <<endl;
            cout << "2. Iron Spear [2*" << multiplier << " Gold]" <<endl;
            cout << "3. (+1) Mythril Rapier [5*" << multiplier << " Gold]" <<endl;
            cout << "4. (+2) Flaming Battle-Axe [15*" << multiplier << " Gold]" <<endl;
            cout << "5. (+3) Vorpal Longsword [50*" << multiplier << " Gold]" <<endl;
            cout << "6. Cancel" <<endl;
            cin >> choice; //recieve user input
            while (choice < 1 && choice > 6)
            {
                cout <<endl;
                cout << "Invalid input. Please enter 1-6." <<endl; //inform user of invalid input
                cout << endl;
                cout << "I have a plentiful collection of weapons to choose from, what would you like?" <<endl; //print menu
                cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." <<endl;
                cout <<endl;
                cout << "Choose one of the following:" <<endl;
                cout << "1. Stone Club [2*" << multiplier << " Gold]" <<endl;
                cout << "2. Iron Spear [2*" << multiplier << " Gold]" <<endl;
                cout << "3. (+1) Mythril Rapier [5*" << multiplier << " Gold]" <<endl;
                cout << "4. (+2) Flaming Battle-Axe [15*" << multiplier << " Gold]" <<endl;
                cout << "5. (+3) Vorpal Longsword [50*" << multiplier << " Gold]" <<endl;
                cout << "6. Cancel" <<endl;
                cin >> choice; //recieve user input
            }
            if (choice == 1) //menu choice 1
            {
                int test = name.stone_club_count(); //declare local variables
                int number = 0;
                char answer;
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" <<endl; //prompt for user input
                cin >> number; //recieve user input
                while (number < 0) //runs loop to make sure a positive integer is entered
                {
                    cout << "Enter a positive integer, or 0 to cancel." <<endl; //prompt for user input
                    cin >> number; //recieve user input
                }
                if (number == 0) //check for condition to cancel
                {
                    continue; //return to main menu
                }
                if (number > 0) //checks that the number provided is above 0
                {
                    int max = number + name.weapon_count(); //call getter function to check count
                    if (max > name.getPartySize())
                    {
                        cout << "You are trying to purchase an amount of weapons that would exceed the maximum allowed." <<endl; //print message
                        continue; //return to main menu
                    }
                    cout << "You want to buy " << number << " Stone Club(s) for " << 2 * number  << "*"  << multiplier << " Gold? (y/n)" <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                    while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                    {
                        cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                        cin >> answer; //recieve user input
                    }
                    if (answer == 'n') //checks to see if user responded no
                    {
                        continue; //return to main menu
                    }
                    if (answer == 'y') //checks to see if user responded yes
                    {
                        name.buy_stone_club(number, name.getRoomsCleared()); //buy item
                    }
                    if (name.stone_club_count() == test) //tests to make sure the transaction went through
                    {
                        continue; //return to main menu
                    }
                }
                cout << "Thank you for your patronage!" <<endl; //print message
                continue; //return to main menu
            }
            if (choice == 2) //menu choice 2
            {
                int test = name.iron_spear_count(); //declare local variables
                int number = 0;
                char answer;
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" <<endl; //prompt for user input
                cin >> number; //recieve user input
                while (number < 0) //runs loop to make sure a positive integer is entered
                {
                    cout << "Enter a positive integer, or 0 to cancel." <<endl; //prompt for user input
                    cin >> number; //recieve user input
                }
                if (number == 0) //check for condition to cancel
                {
                    continue; //return to main menu
                }
                if (number > 0) //checks that the number provided is above 0
                {
                    int max = number + name.weapon_count(); //call getter function to check count
                    if (max > name.getPartySize())
                    {
                        cout << "You are trying to purchase an amount of weapons that would exceed the maximum allowed." <<endl; //print message
                        continue; //return to main menu
                    }
                    cout << "You want to buy " << number << " Iron Spear(s) for " << 2 * number  << "*"  << multiplier << " Gold? (y/n)" <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                    while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                    {
                        cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                        cin >> answer; //recieve user input
                    }
                    if (answer == 'n') //checks to see if user responded no
                    {
                        continue; //return to main menu
                    }
                    if (answer == 'y') //checks to see if user responded yes
                    {
                        name.buy_iron_spear(number, name.getRoomsCleared()); //buy item
                    }
                    if (name.iron_spear_count() == test) //tests to make sure the transaction went through
                    {
                        continue; //return to main menu
                    }
                }
                cout << "Thank you for your patronage!" <<endl; //print message
                continue; //return to main menu
            }
            if (choice == 3) //menu choice 3
            {
                int test = name.mythril_rapier_count(); //declare local variables
                int number = 0;
                char answer;
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" <<endl; //prompt for user input
                cin >> number; //recieve user input
                while (number < 0) //runs loop to make sure a positive integer is entered
                {
                    cout << "Enter a positive integer, or 0 to cancel." <<endl; //prompt for user input
                    cin >> number; //recieve user input
                }
                if (number == 0) //check for condition to cancel
                {
                    continue; //return to main menu
                }
                if (number > 0) //checks that the number provided is above 0
                {
                    int max = number + name.weapon_count(); //call getter function to check count
                    if (max > name.getPartySize())
                    {
                        cout << "You are trying to purchase an amount of weapons that would exceed the maximum allowed." <<endl; //print message
                        continue; //return to main menu
                    }
                    cout << "You want to buy " << number << " (+1) Mythril Rapier(s) for " << 5 * number  << "*" << multiplier << " Gold? (y/n)" <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                    while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                    {
                        cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                        cin >> answer; //recieve user input
                    }
                    if (answer == 'n') //checks to see if user responded no
                    {
                        continue; //return to main menu
                    }
                    if (answer == 'y') //checks to see if user responded yes
                    {
                        name.buy_mythril_rapier(number, name.getRoomsCleared()); //buy item
                    }
                    if (name.mythril_rapier_count() == test) //tests to make sure the transaction went through
                    {
                        continue; //return to main menu
                    }
                }
                cout << "Thank you for your patronage!" <<endl; //print message
                continue; //return to main menu
            }
            if (choice == 4) //menu choice 4
            {
                int test = name.flaming_battle_ax_count(); //declare local variables
                int number = 0;
                char answer;
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" <<endl; //prompt for user input
                cin >> number; //recieve user input
                while (number < 0) //runs loop to make sure a positive integer is entered
                {
                    cout << "Enter a positive integer, or 0 to cancel." <<endl; //prompt for user input
                    cin >> number; //recieve user input
                }
                if (number == 0) //check for condition to cancel
                {
                    continue; //return to main menu
                }
                if (number > 0) //checks that the number provided is above 0
                {
                    int max = number + name.weapon_count(); //call getter function to check count
                    if (max > name.getPartySize())
                    {
                        cout << "You are trying to purchase an amount of weapons that would exceed the maximum allowed." <<endl; //print message
                        continue; //return to main menu
                    }
                    cout << "You want to buy " << number << " (+2) Flaming Battle Ax(es) for " << 15 * number  << "*" << multiplier << " Gold? (y/n)" <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                    while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                    {
                        cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                        cin >> answer; //recieve user input
                    }
                    if (answer == 'n') //checks to see if user responded no
                    {
                        continue; //return to main menu
                    }
                    if (answer == 'y') //checks to see if user responded yes
                    {
                        name.buy_flaming_battle_ax(number, name.getRoomsCleared()); //buy item
                    }
                    if (name.flaming_battle_ax_count() == test) //tests to make sure the transaction went through
                    {
                        continue; //return to main menu
                    }
                }
                cout << "Thank you for your patronage!" <<endl; //print message
                continue; //return to main menu
            }
            if (choice == 5) //menu choice 5
            {
                int test = name.vorpal_longsword_count(); //declare local variables
                int number = 0;
                char answer;
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" <<endl; //prompt for user input
                cin >> number; //recieve user input
                while (number < 0) //runs loop to make sure a positive integer is entered
                {
                    cout << "Enter a positive integer, or 0 to cancel." <<endl; //prompt for user input
                    cin >> number; //recieve user input
                }
                if (number == 0) //check for condition to cancel
                {
                    continue; //return to main menu
                }
                if (number > 0) //checks that the number provided is above 0
                {
                    int max = number + name.weapon_count(); //call getter function to check count
                    if (max > name.getPartySize())
                    {
                        cout << "You are trying to purchase an amount of weapons that would exceed the maximum allowed." <<endl; //print message
                        continue; //return to main menu
                    }
                    cout << "You want to buy " << number << " (+3) Vorpal Longsword(s) for " << 50 * number  << "*" << multiplier << " Gold? (y/n)" <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                    while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                    {
                        cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                        cin >> answer; //recieve user input
                    }
                    if (answer == 'n') //checks to see if user responded no
                    {
                        continue; //return to main menu
                    }
                    if (answer == 'y') //checks to see if user responded yes
                    {
                        name.buy_vorpal_longsword(number, name.getRoomsCleared()); //buy item
                    }
                    if (name.vorpal_longsword_count() == test) //tests to make sure the transaction went through
                    {
                        continue; //return to main menu
                    }
                }
                cout << "Thank you for your patronage!" <<endl; //print message
                continue; //return to main menu
            }
            if (choice == 6) //menu choice 6
            {
                continue; //return to main menu
            }
        }
        if (option == 4) //menu option 4
        {
            int armor = 0; //declare variables
            int test = name.armor_count(); //call getter function to check count
            char answer;
            if (test == name.getPartySize())
            {
                cout << "You have the maximum amount of armor, buying more won't increase the protection provided." <<endl; //print message
                continue; //return to main menu
            }
            cout << "How many suits of armor can I get you at 5*" << multiplier << " per armor? (Enter a positive integer, or 0 to cancel)" <<endl; //prompt for user input
            cin >> armor; //recieve user input
            while (armor < 0) //runs loop to make sure a positive integer is entered
            {
                cout << "Enter a positive integer, or 0 to cancel." <<endl; //prompt for user input
                cin >> armor; //recieve user input
            }
            if (armor == 0) //check for condition to cancel
            {
                continue; //return to main menu
            }
            if (armor > 0) //checks that the number provided is above 0
            {
                int max = armor + name.armor_count(); //call getter function to check count
                if (max > name.getPartySize())
                {
                    cout << "You are trying to purchase an amount of armor that would exceed the maximum protection provided." <<endl; //print message
                    continue; //return to main menu
                }
                cout << "You want to buy " << armor << " Suit(s) of Armor for " << 5 * armor << "*" << multiplier << " Gold? (y/n)" <<endl; //prompt for user input
                cin >> answer; //recieve user input
                while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                {
                    cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                }
                if (answer == 'n') //checks to see if user responded no
                {
                    continue; //return to main menu
                }
                if (answer == 'y') //checks to see if user responded yes
                {
                    name.buy_armor(armor, name.getRoomsCleared()); //buy item
                }
                if (name.armor_count() == test) //tests to make sure the transaction went through
                {
                    continue; //return to main menu
                }
            }
            cout << "Thank you for your patronage!" <<endl; //print message
            continue; //return to main menu
        }
        if (option == 5) //menu option 5
        {
            int choice = 0;
            cout << "What treasure are you wishing to sell?" <<endl; //print menu
            cout <<endl;
            cout << "Choose one of the following:" <<endl;
            cout << "1. Silver Ring (10 Gold)" <<endl;
            cout << "2. Ruby Necklace (20 Gold)" <<endl;
            cout << "3. Emerald Bracelet (30 Gold)" <<endl;
            cout << "4. Diamond Circlet (40 Gold)" <<endl;
            cout << "5. Gem Encrusted Goblet (50 Gold)" <<endl;
            cout << "6. Cancel" <<endl;
            cin >> choice; //recieve user input
            while (choice < 1 && choice > 6)
            {
                cout <<endl;
                cout << "Invalid input. Please enter 1-6." <<endl; //inform user of invalid input
                cout << endl;
                cout << "What treasure are you wishing to sell?" <<endl; //print menu
                cout <<endl;
                cout << "Choose one of the following:" <<endl;
                cout << "1. Silver Ring (10 Gold)" <<endl;
                cout << "2. Ruby Necklace (20 Gold)" <<endl;
                cout << "3. Emerald Bracelet (30 Gold)" <<endl;
                cout << "4. Diamond Circlet (40 Gold)" <<endl;
                cout << "5. Gem Encrusted Goblet (50 Gold)" <<endl;
                cout << "6. Cancel" <<endl;
                cin >> choice; //recieve user input
            }
            if (choice == 1) //menu choice 1
            {
                int number = 0; //declare local variables
                int test = name.gold_count(); //call getter function to check count
                char answer;
                cout << "How much of this treasure do you wish to sell? (Enter a positive integer, or 0 to cancel)" <<endl; //prompt for user input
                cin >> number; //recieve user input
                while (number < 0) //runs loop to make sure a positive integer is entered
                {
                    cout << "Enter a positive integer, or 0 to cancel." <<endl; //prompt for user input
                    cin >> number; //recieve user input
                }
                cout << "Are you trying to sell " << number << " Silver Ring(s) for " << 10 * number << " Gold? (y/n)" <<endl; //prompt for user input
                cin >> answer; //recieve user input
                while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                {
                    cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                }
                if (answer == 'n') //checks to see if user responded no
                {
                    continue; //return to main menu
                }
                if (answer == 'y') //checks to see if user responded yes
                {
                    name.sell_silver_ring(number); //sell treasure
                }
                if (test != name.gold_count())
                {
                    cout << "You have made a successful sale! Enjoy the gold!" <<endl; //print message
                }
                continue; //return to main menu
            }
            if (choice == 2) //menu choice 2
            {
                int number = 0; //declare local variables
                int test = name.gold_count(); //call getter function to check count
                char answer;
                cout << "How much of this treasure do you wish to sell? (Enter a positive integer, or 0 to cancel)" <<endl; //prompt for user input
                cin >> number; //recieve user input
                while (number < 0) //runs loop to make sure a positive integer is entered
                {
                    cout << "Enter a positive integer, or 0 to cancel." <<endl; //prompt for user input
                    cin >> number; //recieve user input
                }
                cout << "Are you trying to sell " << number << " Ruby Necklace(s) for " << 20 * number << " Gold. (y/n)" <<endl; //prompt for user input
                cin >> answer; //recieve user input
                while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                {
                    cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                }
                if (answer == 'n') //checks to see if user responded no
                {
                    continue; //return to main menu
                }
                if (answer == 'y') //checks to see if user responded yes
                {
                    name.sell_ruby_neckalace(number); //sell treasure
                }
                if (test != name.gold_count())
                {
                    cout << "You have made a successful sale! Enjoy the gold!" <<endl; //print message
                }
                continue; //return to main menu
            }
            if (choice == 3) //menu choice 3
            {
                int number = 0; //declare local variables
                int test = name.gold_count(); //call getter function to check count
                char answer;
                cout << "How much of this treasure do you wish to sell? (Enter a positive integer, or 0 to cancel)" <<endl; //prompt for user input
                cin >> number; //recieve user input
                while (number < 0) //runs loop to make sure a positive integer is entered
                {
                    cout << "Enter a positive integer, or 0 to cancel." <<endl; //prompt for user input
                    cin >> number; //recieve user input
                }
                cout << "Are you trying to sell " << number << " Emerald Bracelet(s) for " << 30 * number << " Gold. (y/n)" <<endl; //prompt for user input
                cin >> answer; //recieve user input
                while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                {
                    cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                }
                if (answer == 'n') //checks to see if user responded no
                {
                    continue; //return to main menu
                }
                if (answer == 'y') //checks to see if user responded yes
                {
                    name.sell_emerald_bracelet(number); //sell treasure
                }
                if (test != name.gold_count())
                {
                    cout << "You have made a successful sale! Enjoy the gold!" <<endl; //print message
                }
                continue; //return to main menu
            }
            if (choice == 4) //menu choice 4
            {
                int number = 0; //declare locale variables
                int test = name.gold_count(); //call getter function to check count
                char answer;
                cout << "How much of this treasure do you wish to sell? (Enter a positive integer, or 0 to cancel)" <<endl; //prompt for user input
                cin >> number; //recieve user input
                while (number < 0) //runs loop to make sure a positive integer is entered
                {
                    cout << "Enter a positive integer, or 0 to cancel." <<endl; //prompt for user input
                    cin >> number; //recieve user input
                }
                cout << "Are you trying to sell " << number << " Diamond Circlet(s) for " << 40 * number << " Gold. (y/n)" <<endl; //prompt for user input
                cin >> answer; //recieve user input
                while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                {
                    cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                }
                if (answer == 'n') //checks to see if user responded no
                {
                    continue; //return to main menu
                }
                if (answer == 'y') //checks to see if user responded yes
                {
                    name.sell_diamond_circlet(number); //sell treasure
                }
                if (test != name.gold_count())
                {
                    cout << "You have made a successful sale! Enjoy the gold!" <<endl; //print message
                }
                continue; //return to main menu
            }
            if (choice == 5) //menu choice 5
            {
                int number = 0; //declare local variables
                int test = name.gold_count(); //call getter function to check count
                char answer;
                cout << "How much of this treasure do you wish to sell? (Enter a positive integer, or 0 to cancel)" <<endl; //prompt for user input
                cin >> number; //recieve user input
                while (number < 0) //runs loop to make sure a positive integer is entered
                {
                    cout << "Enter a positive integer, or 0 to cancel." <<endl; //prompt for user input
                    cin >> number; //recieve user input
                }
                cout << "Are you trying to sell " << number << " Gem Encrusted Goblet(s) for " << 50 * number << " Gold. (y/n)" <<endl; //prompt for user input
                cin >> answer; //recieve user input
                while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                {
                    cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                    cin >> answer; //recieve user input
                }
                if (answer == 'n') //checks to see if user responded no
                {
                    continue; //return to main menu
                }
                if (answer == 'y') //checks to see if user responded yes
                {
                    name.sell_gem_encrusted_goblet(number); //sell treasure
                }
                if (test != name.gold_count())
                {
                    cout << "You have made a successful sale! Enjoy the gold!" <<endl; //print message
                }
                continue; //return to main menu
            }
            if (choice == 6) //menu choice 6
            {
                continue; //return to main menu
            }
        }   
        if (option == 6) //menu option 6
        {
            char answer;
            cout << "Are you sure you're finished? You won't be able to buy anything else from me! (y/n)" <<endl;  //prompt for user input
            cin >> answer; //recieve user input
            while (answer != 'y' && answer != 'n')
            {
                cout << "Please enter 'n' for yes or 'y' no." <<endl;  //prompt for user input
                cin >> answer; //recieve user input
            }
            if (answer == 'n') //checks to see if user responded no
            {
                continue; //return to main menu
            }
            if (answer == 'y') //checks to see if user responded yes
            {
                cout << "Stay safe out there! Goodbye!" <<endl; //print message
                return; //end function
            }
        }
    }
}

//this function will also be used in the misfortune class to see if the misfortune can be conducted on the player
bool MainMenu::enoughItems(int n_in, Party& p_in){
   if(n_in > 0){
       return true;
   }
   else if(n_in == 0 && p_in.gold_count() >= 5){
       cout << "You didn't have what the bandits were looking for, so they took 5 of your gold instead." << endl;
       p_in.removeGold(5);
       return false;
   }
   else{
       cout << "Your party is so broke that the bandits felt bad for you and left. No changes to inventory this turn" << endl;
       return false;
   }
}
 
//this misfortune function will be used to decide what misfortune happens to the party
void MainMenu::randomMisfortune(Party& p_in, bool usedKey_in, int chance_in){
   srand(time(0));
   int random = rand() %101;
   if(random <= chance_in){
       random = rand()%101;
       if(random <= 30){
           cout << "OH NO! Your team was robbed by dungeon bandits!" << endl;
           random = rand()%101;
           if(random <= 33){
               if(!enoughItems(p_in.cauldron_count(), p_in)){
                   return;
               }
               cout << "You lost 1 Cauldron!" << endl;
               p_in.break_cauldron();
               return;
           }
           if(random > 33 && random <= 66){
               if(!enoughItems(p_in.armor_count(), p_in)){
                   return;
               }
               cout << "You lost 1 armor!" << endl;
               p_in.break_armor();
               return;
           }
           else{
               if(p_in.ingredients_count() >= 10){
                   cout << "You lost 10 kg of ingredients!" << endl;
                   p_in.cook_ingredients(10);
                   return;
               }
               else{
                   cout << "You lost all your ingredients!" << endl;
                   p_in.cook_ingredients(10);
                   return;
               }
           }
       }
       else if(random > 30 && random <= 40){
           random = rand() %101;
           if(random < 50){
               p_in.break_armor();
               cout << "OH NO! You lost 1 armor!" << endl;
               return;
           }
           else{
               cout << "You lost 1 " << p_in.break_random_weapon() << endl;
               return;
           }
       }
       else if(random > 40 && random <= 70){
           string affected_player = p_in.subtractRandomPlayerFullness(10);
           cout << "OH NO! " <<  affected_player << " got food poisoning and lost 10 fullness!" << endl;
           return;
       }
       else if(random > 70 && usedKey_in == true){
           cout << "OH NO! Your teammate " << p_in.killRandomPlayer() << " is trapped in the previous room and you must continue without them." << endl;
           cout << "Your party size has reduced to " << p_in.getPartySize() << " members." << endl;
       }
       else{
           enoughItems(0, p_in);
       }
   }
}


bool MainMenu::fightMonster(Party& name, bool auto_fight)
{
        ifstream in_file("monsters.txt"); //declare variables
        ofstream out("monster.txt");
        int count = 1;
        int counter = 0;
        int answer = 0;
        string str;
        string st;
    if (auto_fight == true || auto_fight == false) //runs regardless
    {
        if (name.getRoomsCleared() == 1) //finds proper monster per room
        {
            count = 7; //to 9
        }
        if (name.getRoomsCleared() == 2) //finds proper monster per room
        {
            count = 13; //to 14
        }
        if (name.getRoomsCleared() == 3) //finds proper monster per room
        {
            count = 19; //to 19
        }
        if (name.getRoomsCleared() == 4) //finds proper monster per room
        {
            count = 25; //to 24
        }
        if (name.getRoomsCleared() == 5) //finds proper monster per room
        {
            count = 31; //to 26
        }
        srand(time(0));
        int random = rand() % 4;
        count += random; 
        if (in_file.is_open())
        {
            while (getline(in_file, str))
            {
                counter++;
                if (count == counter)
                {
                    if (str[0] == '.') //makes sure monster can't be reselected
                    {
                        count++;
                        out << str <<endl;
                        continue;
                    }
                    if (str[0] == '-') //makes sure it's not going past the range of monsters per room
                    {
                        count -= 5;
                        out << str <<endl;
                        continue;
                    }
                    cout <<endl;
                    cout << str << " AHEAD! THEY LOOK HOSTILE!" <<endl;
                    cout <<endl;
                    out << '.' << str <<endl;
                    continue;
                }
                out << str <<endl;
            }
        }
        ifstream recieve("monster.txt");
        ofstream back("monsters.txt");
        if (recieve.is_open())
        {
            while (getline(recieve, st))
            {
                back << st <<endl;
            }
        }
    }   
    if (name.weapon_count() >= 1 && auto_fight == false)
    {
        cout << "Would you like to fight(1) or surrender(2)?" <<endl;
        cin >> answer;
        while (answer > 2 && answer < 1)
        {
            cout << "Please enter 1 to fight or 2 to surrender." <<endl;
            cin >> answer;
        }
    }
    if (answer == 1 || auto_fight == true)
    {
        int w = name.weapon_count() + name.mythril_rapier_count() + (2 * name.flaming_battle_ax_count()) + (3 * name.vorpal_longsword_count());
        int d = 0;
        if (name.weapon_count() != 0 && name.iron_spear_count() <= 1 && name.stone_club_count() <= 1 && name.mythril_rapier_count() <= 1 && name.flaming_battle_ax_count() <= 1 && name.vorpal_longsword_count() <= 1)
        {
            d = 4;
        }
        int a = name.armor_count();
        if (a == 0)
        {
           name.addArmor();
        }
        int c = name.getRoomsCleared() + 1;
        int r = rand() % 7;
        while (r == 0)
        {
            r = rand() % 7;
        }
        int ra = rand() % 7;
        while (ra == 0)
        {
            ra = rand() % 7;
        }
        double result = (r * w + d) - ((ra * 2) / a);
        name.break_armor();
        if (result <= 0)
        {
            cout << "You lost the battle." <<endl;
            int remove = name.gold_count() / 4;
            name.removeGold(remove);
            cout << "You lost " << remove << " gold." <<endl;
            int ingred = name.ingredients_count();
            if (ingred <= 30)
            {
                name.remove_ingredients(ingred);
                cout << "You lost all of your ingredients." <<endl;
            }
            if (ingred > 30)
            {
                name.remove_ingredients(30);
                cout << "You lost 30 ingredients and now only have " << name.ingredients_count() <<endl;
            }
            int num = name.armor_count();
    
            for (int i = 1; i < num; i++)
            {
                srand(time(0));
                int random = rand() % 101;
                if (random >= 35 && random < 40)
                {   
                    cout << name.killRandomPlayer() << " has been slain." <<endl;
                    cout << "Party size has been reduced to " << name.getPartySize() << " members." << endl;
                }
            }
            int other = name.getPartySize() - num;
            for (int i = num; i < name.getPartySize(); i++)
            {   
                int random = rand() % 101;
                if (random >= 70 && random < 80)
                {
                    cout << name.killRandomPlayer() << " has been slain." <<endl;
                    cout << "Party size has been reduced to " << name.getPartySize() << " members." << endl;
                }
            }
            loseFullness(50, 1, name);
            return false;
        }
        if (result > 0)
        {
            cout << "You won the battle!" <<endl;
            cout << "You recieved " << 10 * c << " gold!" <<endl;
            cout << "You recieved " << 5 * c << " kg of ingredients!" <<endl;
            name.addGold(10 * c);
            name.add_ingredients(5 * c);
            int percent = rand() % 101;
            if (percent >= 0 && percent < 10)
            {
                name.addKey();
                cout << "You found a room key!" <<endl;
            }
        }
        loseFullness(50, 1, name);
        return true;
        
    }
    if (auto_fight == false)
    {
        if (name.weapon_count() < 1 || answer == 2)
        {
            cout << "OH NO! Your teammate " << name.killRandomPlayer() << " is trapped in the previous room and you must continue without them." << endl;
            cout << "Your party size has reduced to " << name.getPartySize() << " members." << endl;
        }
        return false;
    }
    return false;
}

void MainMenu::riddle(Party& name)
{
    string riddle;
    string answer;
    string user_answer;
    string riddle_answer;
    int count = 0;
    int counter = 0;
    ifstream in_file("riddle.txt");
    ifstream in_again("riddle.txt");
    ofstream out("riddles.txt");

    cout << "You have come across a wandering merchant. To be able to talk to him you must solve a riddle." <<endl;
    cout << "Be warned, if you are wrong, there will be consequences." <<endl;
    cout <<endl;

    if (in_file.is_open() && in_again.is_open())
    {
        srand(time(0));
        int riddle_num = rand() % 41;
        while (riddle_num % 2 == 0)
        {
            riddle_num = rand() % 41;
        }
        while (getline(in_file, riddle))
        {
            count++;
            if (count == riddle_num)
            {
                if (riddle[0] == '.') 
                {
                    out << riddle <<endl;
                    count++;
                    continue;
                }
                if (riddle[0] == '-')
                {
                    out << riddle;
                    count = 1;
                    continue;
                }
                cout << riddle <<endl;
                out << '.' << riddle <<endl;
                cin >> user_answer;
                while (getline (in_again, answer))
                {
                    counter++;
                    if (count + 1 == counter)
                    {
                        riddle_answer = answer;
                    }
                }
                if (user_answer == riddle_answer)
                {
                    char answer;
                    char sure;
                    cout << "Congatulations! You solved the riddle correctly. Do you wish to barter for goods? (y/n)" <<endl; //prompt for user input
                    cin >> answer;  //recieve user input
                    while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                    {
                        cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                        cin >> answer; //recieve user input
                    }
                    if (answer == 'n') //checks to see if user responded no
                    {
                        cout << "Are you sure? We won't have the chance to meet again. (y/n)" <<endl; //prompt for user input
                        cin >> sure; //recieve user input
                        while (answer != 'n' && answer != 'y') //run loop until the user responds with y or n for yes or no
                        {
                            cout << "Please enter 'y' for yes or 'n' no." <<endl; //prompt for user input
                            cin >> sure; //recieve user input
                        }
                        if (sure == 'y') //checks to see if user responded yes
                        {
                            return; //end function
                        }
                    }
                    if (answer == 'y' || sure == 'n') //checks to see if user wants to see menu
                    {
                        merchantCom(name);
                    }
                }
                else
                {
                    cout << "That is not the right answer, now you must suffer the consequence." <<endl;
                    fightMonster(name, true);
                }
            }
            else
            {
                out << riddle <<endl;
            }
        }
    }
    ifstream in("riddles.txt");
    ofstream back("riddle.txt");
    while (getline(in, riddle))
    {
        back << riddle <<endl;
    }
    return;
}

void MainMenu::rockPaperScissors(Party& name, Map& m_in)
{
    bool win = false;
    int times = 0;
    while (win == false && times < 3)
    {
        int p_boulder = 0;
        int p_parchment = 0;
        int p_shears = 0;
        int c_boulder = 0;
        int c_parchment = 0;
        int c_shears = 0;
        int choice = 0;
        cout << "Pick Boulder (1), Parchment (2), or Shears (3)." <<endl;
        cin >> choice;
        while (choice < 1 && choice > 3)
        {
            cout << "Please enter 1, 2, or 3 for Boulder (1), Parchment (2), or Shears (3)." <<endl;
            cin >> choice;
        }
        if (choice == 1)
        {
            p_boulder++;
            cout << "You chose boulder." <<endl;
        }
        if (choice == 2)
        {
            p_parchment++;
            cout << "You chose parchment." <<endl;
        }
        if (choice == 3)
        {
            p_shears++;
            cout << "You chose shears." <<endl;
        }

        srand(time(0));
        int computer = rand() % 4;
        while (computer != 1 && computer != 2 && computer != 3)
        {
            computer = rand() % 4;
        }

        if (computer == 1)
        {
            c_boulder++;
            cout << "The door chose boulder." <<endl;
        }
        if (computer == 2)
        {
            c_parchment++;
            cout << "The door chose parchment." <<endl;
        }
        if (computer == 3)
        {
            c_shears++;
            cout << "The door chose shears." <<endl;
        }

        //tie
        if (p_shears == 1 && c_shears == 1)
        {
            cout << "You tied. Try again." <<endl;
            continue;
        }
        if (p_boulder == 1 && c_boulder == 1)
        {
            cout << "You tied. Try again." <<endl;
            continue;
        }
        if (p_parchment == 1 && c_parchment == 1)
        {
            cout << "You tied. Try again." <<endl;
            continue;
        }

        //win
        if (p_parchment == 1 && c_boulder == 1)
        {
            win = true;
        }
        if (p_boulder == 1 && c_shears == 1)
        {
            win = true;
        }
        if (p_shears == 1 && c_parchment == 1)
        {
            win = true;
        }

        //lose
        if (c_parchment == 1 && p_boulder == 1)
        {
            times++;
            cout << "You lost. You have " << 3 - times << " attempts left." <<endl;
            continue;
        }
        if (c_boulder == 1 && p_shears == 1)
        {
            times++;
            cout << "You lost. You have " << 3 - times << " attempts left." <<endl;
            continue;
        }
        if (c_shears == 1 && p_parchment == 1)
        {
            times++;
            cout << "You lost. You have " << 3 - times << " attempts left." <<endl;
            continue;
        }
    }
    if(win == true){
        name.addRoomCleared(1);
        if(fightMonster(name, false) == true){
            m_in.removeRoom(m_in.getPlayerRow(), m_in.getPlayerCol());
            randomMisfortune(name, true, 60);
        }
        else{
            cout << "You failed to beat the monster." << endl;
            name.subtractRoomCleared(1);
            randomMisfortune(name, true, 40);
        }
    }
    if(win == false)
    {
        cout << name.killRandomPlayer() << " has been slain" << endl;
    }
}
 
 
void MainMenu::action(Map& m_in, Party& p_in)
{
    int playerRow = m_in.getPlayerRow();
    int playerCol = m_in.getPlayerCol();
    int input;

    if(!m_in.isNPCLocation(playerRow, playerCol) && !m_in.isRoomLocation(playerRow, playerCol) && !m_in.isDungeonExit(playerRow, playerCol))
    {
        do
        {
            cout << "1. Move" << endl;
            cout << "2. Investigate" << endl;
            cout << "3. Pick a Fight" << endl;
            cout << "4. Cook and Eat" << endl;
            cout << "5. Give Up" << endl;
            cin >> input;
        }
        while(input < 1 || input > 5);
        if(input == 1)
        {
            moveHelper(m_in);
            loseFullness(50, 1, p_in);
            return;
        }
        else if(input == 2)
        {
            if(m_in.isExplored(playerRow, playerCol))
            {
                cout << "This space cannot be explored again. Please select another option." << endl;
                action(m_in, p_in);
            }
            else
            {
                srand(time(0));
                int random = rand()%101;
                if(random < 10)
                {
                    cout << "You found a key!" << endl;
                    p_in.addKey();
                    loseFullness(50, 1, p_in);
                }
                else if(random >= 10 && random < 30)
                {
                    cout << "You found some treasure!" << endl;
                    if(p_in.getRoomsCleared() == 0)
                    {
                        cout << "5 gold has been added to your inventory." << endl;
                        p_in.addGold(5);
                    }
                    else if(p_in.getRoomsCleared() == 1)
                    {
                        cout << "Silver ring has been added to your inventory." << endl;
                        p_in.find_silver_ring();
                    }
                    else if(p_in.getRoomsCleared() == 2)
                    {
                        cout << "Ruby necklace has been added to your inventory." << endl;
                        p_in.find_ruby_neckalace();
                    }
                    else if(p_in.getRoomsCleared() == 3)
                    {
                        cout << "Emerald bracelet has been added to your inventory." << endl;
                        p_in.find_emerald_bracelet();
                    }
                    else if(p_in.getRoomsCleared() == 4)
                    {
                        cout << "Diamond circlet has been added to your inventory." << endl;
                        p_in.find_diamond_circlet();
                    }
                    else if(p_in.getRoomsCleared() >= 5)
                    {
                        cout << "Gem-encrusted goblet has been added to your inventory" << endl;
                        p_in.find_gem_encrusted_goblet();
                    }
                    loseFullness(50, 1, p_in);
                }
                else if(random >= 30 && random < 50)
                {
                    //summon a monster to fight. 10% chance it drops key
                    fightMonster(p_in, true); //true means you fight no matter what, no choice to fight or not
    
                }
                else
                {
                    cout << "The space had nothing. Unfortunate. Continue to next turn." << endl;

                    //50% chance to lose 1 fullness for each player
                    loseFullness(50, 1, p_in);
                }
                m_in.exploreSpace(m_in.getPlayerRow(), m_in.getPlayerCol());
                randomMisfortune(p_in, false, 40);
                return;
            }
        }
        else if(input == 3)
        {
            //pick a fight with a monster. causes random monster to appear
            fightMonster(p_in, false);
            randomMisfortune(p_in, false, 40);
        }
        else if(input == 4){ //cook and eat 
            if(p_in.ingredients_count() < 5)
            {
                cout << "You don't have enough ingredients for a cook. Pick another option." << endl;
                action(m_in, p_in);
            }
            else
            {
                int in_food;
                char input;
                srand(time(0));
                int random = rand()%101;

                cout << "How many kg of food would you like to cook?" << endl;
                cout << "Please only enter increments of 5. Any leftovers will be thrown out. (5 kg = 1 fullness)" << endl;
                cin >> in_food;

                do
                {
                    cout << "What cookware would you like to use?" << endl;
                    cout << "You have " << p_in.ceramic_pot_count() << " Ceramic Pot(P), " << p_in.frying_pan_count() << " Frying pans(F), and " << p_in.cauldron_count() << " Cauldrons(C)" << endl;
                    cin >> input;
                    if(input != 'P' && input != 'p' && input != 'F' && input != 'f' && input != 'C' && input != 'c')
                    {
                        cout << "Please enter either P, F, or C" << endl;
                    }
                }
                while(input != 'P' && input != 'p' && input != 'F' && input != 'f' && input != 'C' && input != 'c');

                if(input == 'P' || input == 'p')
                {
                    if(p_in.ceramic_pot_count() == 0)
                    {
                        cout << "You don't have enough ceramic pots to complete a cook. Pick another option." << endl;
                        action(m_in, p_in);
                    }
                    else
                    {
                        if(random < 25)
                        {
                            cout << "Your ceramic pot broke! You lost " << in_food << " kg of food and 1 ceramic pot!" << endl;
                            p_in.cook_ingredients(in_food);
                            p_in.break_ceramic_pot();
                            randomMisfortune(p_in, false, 40);
                            return;
                        }
                    }
                }
                if(input == 'F' || input == 'f')
                {
                    if(p_in.frying_pan_count() == 0)
                    {
                        cout << "You don't have enough frying pans to complete a cook. Pick another option." << endl;
                        action(m_in, p_in);
                    }
                    else
                    {
                        if(random < 10)
                        {
                            cout << "Your frying pan broke! You lost " << in_food << " kg of food and 1 frying pan!" << endl;
                            p_in.cook_ingredients(in_food);
                            p_in.break_frying_pan();
                            randomMisfortune(p_in, false, 40);
                            return;
                        }
                    }
                }
                if(input == 'C' || input == 'c')
                {
                    if(p_in.cauldron_count() == 0)
                    {
                        cout << "You don't have enough cauldrons to complete a cook. Pick another option." << endl;
                        action(m_in, p_in);
                    }
                    else
                    {
                        if(random < 2)
                        {
                            cout << "Your cauldron broke! You lost " << in_food << " kg of food and 1 cauldron!" << endl;
                            p_in.cook_ingredients(in_food);
                            p_in.break_cauldron();
                            randomMisfortune(p_in, false, 40);
                            return;
                        }
                    }
                }

                cout << "You successfully cooked " << in_food << " kg of food and all players in your party have had their fullness raised by " << in_food/p_in.getPartySize() << " points" << endl;
                p_in.addFullness(in_food/p_in.getPartySize());
                p_in.cook_ingredients(in_food);
                randomMisfortune(p_in, false, 40);
                return;
            }
        }
        else if(input == 5)
        {
            endGame(1, p_in);
        }
    }
    else if(m_in.isRoomLocation(playerRow, playerCol))
    {
        int input;
        do{
            cout << "1. Move" << endl;
            cout << "2. Open the door" << endl;
            cout << "3. Give up" << endl;
            cin >> input;
            if(input < 1 || input > 3){
                cout << "Please pick a number between 1 and 3" << endl;
            }
        }while(input < 1 || input > 3);
        if(input == 1)
        {
            moveHelper(m_in);
            loseFullness(20, 1, p_in);
            return;
        }
        else if(input == 2)
        {
            if(p_in.getKeysFound() > 0){
                //battle an enemy 2 levels higher than # of cleared rooms
                p_in.addRoomCleared(1);
                if(fightMonster(p_in, false) == true){
                    m_in.removeRoom(m_in.getPlayerRow(), m_in.getPlayerCol());
                    randomMisfortune(p_in, true, 60);
                }
                else{
                    cout << "You failed to beat the monster. You lost your key and must use another one to try this room again" << endl;
                    p_in.subtractRoomCleared(1);
                    randomMisfortune(p_in, true, 40);
                }
                p_in.subtractKey();
            }
            else{
                rockPaperScissors(p_in, m_in);
            }
        }
        else if(input == 3)
        {
            endGame(1, p_in);
        }
    }
    else if(m_in.isNPCLocation(playerRow, playerCol))
    {
        int input;
        do
        {
            cout << "1. Move" << endl;
            cout << "2. Speak to NPC" << endl;
            cout << "3. Give up" << endl;
            cin >> input;
        }while(input < 1 || input > 3);
        if(input == 1)
        {
            moveHelper(m_in);
            loseFullness(20, 1, p_in);
        }
        else if(input == 2)
        {
            riddle(p_in);
            m_in.removeNPC(m_in.getPlayerRow(), m_in.getPlayerCol());
        }
        else if(input == 3)
        {
            endGame(1, p_in);
        }
    }
    else if(m_in.isDungeonExit(m_in.getPlayerRow(), m_in.getPlayerCol()))
    {   
        int input;
        cout << "1. Move" << endl;
        cout << "2. Exit dungeon" << endl;
        cout << "3. Give up" << endl;
        while(!(cin >> input) || (input < 1 && input > 3)){
            cout << "Please only enter a number between 1 and 3" << endl;
        }
        if(input == 1){
            moveHelper(m_in);
            loseFullness(20, 1, p_in);
        }
        else if(input == 2){
            if(m_in.getRoomCount() == 0){
                endGame(5, p_in);
            }
            else{
                cout << "You have not cleared all of the rooms yet. Come back when you've defeated the sorceror" << endl;
                action(m_in, p_in);
            }
        }
        else if(input == 3){
            endGame(1, p_in);
        }
    }
}
 
void MainMenu::endGame(int ending, Party p_in)
{
    //give up ending
    if(ending == 1)
    {
        cout << "You gave up?! I am disappointed. Please try to kill the sorceror again later" << endl;
    }
    //mc died of hunger ending
    else if(ending == 0)
    {
        cout << "You died of hunger?! I am disappointed. You should've stocked up at the merchant" << endl;
    }
    //died of sorcerors anger ending
    else if(ending == 2)
    {
        cout << "You should've paid closer attention to the sorceror's anger. Now you and your comrades have died in vain" << endl;
    }
    //died because only the party leader is left
    else if(ending == 4)
    {
        cout << "No man can beat the sorceror singlehandedly. Come back again with a new team later" << endl;
    }
    //successful ending
    else if(ending == 5)
    {
        cout << "Thank you for beating the sorceror! All of us in the dungeon owe you our lives!" << endl;
    }

    string str;
    ifstream OGmonster("OGmonster.txt"); //streams to reset text files to original format
    ifstream OGriddle("OGriddle.txt");
    ofstream monsterback("monsters.txt");
    ofstream riddleback("riddle.txt");
    if (OGmonster.is_open())
    {
        while (getline(OGmonster, str))
        {
            monsterback << str <<endl;
        }
    }
    if (OGriddle.is_open())
    {
        while (getline(OGriddle, str))
        {
            riddleback << str <<endl;
        }
    }
    exit(0);
}
 
void MainMenu::displayMainMenu(Party& p_in, Map& m_in){
    //randomize the map
    //the map needs 5 rooms, 5 NPCs
    srand(time(0));
    int random_row = rand()%12;
    int random_col = rand()%12;
    while(m_in.getRoomCount() < 5 && m_in.addRoom(random_row, random_col)){
        random_row = rand()%12;
        random_col = rand()%12;
    }
    while(m_in.getNPCCount() < 5 && m_in.addNPC(random_row, random_col)){
        random_row = rand()%12;
        random_col = rand()%12;
    }
    beginGame(p_in);
    //status, map, action
    bool gameIsOver = false;
    while(!gameIsOver){
        cout << endl;
        displayStatus(p_in);
        m_in.displayMap();
        action(m_in, p_in);
        sorcerors_anger++;
        if(p_in.findPlayer(p_in.getPartyLeaderName()).getFullness() <= 0){
            gameIsOver = true;
            endGame(0, p_in);
            return;
        }
        if(sorcerors_anger == 100){
            gameIsOver = true;
            endGame(2, p_in);
            return;
        }
        for(int i = 0; i < 5; i++){
            if(p_in.getPlayerNameAtIndex(i) != "dead" && p_in.findPlayer(p_in.getPlayerNameAtIndex(i)).getFullness() <= 0){
                cout << p_in.getPlayerNameAtIndex(i) << " has died to hunger." << endl;
                p_in.killPlayer(p_in.getPlayerNameAtIndex(i));
                cout << "Party size has been reduced to " << p_in.getPartySize() << " members." << endl;
            }
        }
        if(p_in.getPartySize() <= 1){
            gameIsOver = true;
            endGame(4, p_in);
            return;
        }
        cout << endl;
    }
}