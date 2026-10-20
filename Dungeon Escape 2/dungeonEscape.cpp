// CSCI1300 Fall 2022
// Author: Harrison Perlstein and Robby Toomey
// CSCI 1300-307 TA: Zachary Atkins
// Project 3 - Dungeon Escape - Play Game

#include <iostream>
#include <fstream>
#include "Party.h"
#include "Player.h"
#include "MainMenu.h"
#include "Map.h"
 
using namespace std;
 
int main()
{
    MainMenu m;
    Map m1;
    Party p;
    
    m.displayMainMenu(p, m1);
}
