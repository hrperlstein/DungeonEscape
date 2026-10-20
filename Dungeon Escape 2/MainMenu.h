// CSCI1300 Fall 2022
// Author: Harrison Perlstein and Robby Toomey
// CSCI 1300-307 TA: Zachary Atkins
// Project 3 - Dungeon Escape - Main Menu Class

#ifndef MAINMENU_H
#define MAINMENU_H
 
#include "Party.h"
#include "Map.h"
#include <iostream>
using namespace std;
 
class MainMenu{
    public:
        MainMenu();
        int getSorcerorsAnger();
        void displayStatus(Party& p);
        void displayMainMenu(Party& p, Map& m);
        void action(Map& m, Party& p);
        void moveHelper(Map& m);
        void loseFullness(int chance, int amnt, Party& p);
        void merchantCom(Party& p);
        bool fightMonster(Party& name, bool auto_fight);
        void riddle(Party& p);
        void endGame(int ending, Party p);
        void rockPaperScissors(Party& name, Map& m);
        void beginGame(Party& p); 

        //misfortune functions
        bool enoughItems(int n, Party& p);
        void randomMisfortune(Party& p, bool keyUsed, int chance);

    private:
        int sorcerors_anger;
};
 
#endif
 

