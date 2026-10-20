------------------------
HOW TO COMPILE AND RUN
------------------------
Compile: g++ -std=c++17 dungeonEscape.cpp MainMenu.cpp Map.cpp Party.cpp Player.cpp 
Run: ./a.out
------------------------
DEPENDENCIES
------------------------
MainMenu.h, Map.h, Party.h and Player.h, monster.txt, monsters.txt, OGmonster.txt, OGriddle.txt, riddle.txt, riddles.txt 
must be in the same directory as the cpp files in order to compile.
------------------------
PROJECT INFORMATION
------------------------
CU Boulder CSCI1300 Fall 2022 Final Project
Author: Harrison Perlstein and Robby Toomey
Date: Dec 1, 2022
------------------------
ABOUT THIS PROJECT
------------------------
This project is an ASCII video game based off the game Dungeons and Dragons. The game challenges players to find a key in order to escape 
before a sorcerer destroys the dungeon. Investigate spaces, win rock-paper-scissors matches, defeat monsters, and solve riddles to survive 
and escape.

In this dungeon, spaces are marked differently based on how you can interact with them. Spaces marked with '-' are normal spaces. Spaces 
marked 'N' are spaces that hold the wandering merchant. Spaces marked 'R' contain a room. The space marked 'E' is the dungeon exit. Every
turn, there will be a status update of your party. If you look, you will see the sorcerors anger as one part of the status. If the sorcerors 
anger reaches 100, he will blow up the dungeon and the game will end. If all of your party members die, you will lose the game. If you die 
to hunger, you will lose the game. Many times throughout the dungeon, you will find the merchant who you can buy items from to help you. To 
enter a room space, you must either posess a key or win a game of rock paper scissors vs the AI. If you fail rock paper scissors, you are 
forced into a fight with a monster. In addition, you are not able to enter that room until you either get a key or win rock paper scissors. 
Keys are found by investigating spaces and beating monsters. Battling a monster involves a complex equation. Your chances of winning 
increase based on weapons and armor. Wandering merchant spaces are hidden until you walk over them. To buy items from the merchant, you must 
answer a riddle. Answer the riddle incorrectly and you must fight a monster yet again. Every turn, there is a large chance for a random misfortune 
to occur which will damage your party. 
