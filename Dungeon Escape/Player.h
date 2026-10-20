// CSCI1300 Fall 2022
// Author: Harrison Perlstein and Robby Toomey
// CSCI 1300-307 TA: Zachary Atkins
// Project 3 - Dungeon Escape - Player Class

#ifndef PLAYER_H
#define PLAYER_H
 
#include <iostream>
using namespace std;
 
class Player{
   public:
       Player();
       Player(string p);
       void setPlayerName(string n);
       void addFullness(int f);
       void subtractFullness(int& f);
       string getPlayerName();
       int getFullness();
       void setFullness(int am);
   private:
       int fullness;
       string player_name;
};
 
#endif