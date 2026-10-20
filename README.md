# DungeonEscape

## Description
This project is an ASCII video game based off the game Dungeons and Dragons developed in C++. The game challenges players to find a key in order to escape before a sorcerer destroys the dungeon. Investigate spaces, win rock-paper-scissors matches, defeat monsters, and solve riddles to survive and escape.

## Features
- Dungeon Exploration — Navigate a dungeon filled with hidden merchants, rooms, and dangerous encounters

- Merchant Encounters — Purchase useful items to improve your chances of surviving and escaping the dungeon

- Resource Management — Manage your party's hunger, equipment, and survival throughout your journey

- Combat System — Battle monsters using a combat system in which weapons and armor influence your chances of victory.

- Riddle Challenges — Solve riddles to purchase items from the wandering merchant, with incorrect answers potentially leading to combat

- Room Challenges — Unlock rooms by winning Rock Paper Scissors against the AI or with a key

- Win and Lose Conditions — Find a key and reach the dungeon exit to win, while avoiding hunger, monster encounters, and other threats that could end your run

## How to Play

### Starting the Game
The game begins with an encounter with a merchant. You can purchase useful items to help your party survive the dangers of the dungeon and eventually escape. Choose your items carefully, as they may make the difference between survival and defeat.

### Turn Actions
Every turn, you can choose one of the following actions:

1. Move — Move your party through the dungeon.
2. Investigate — Investigate your current space to discover items, keys, or other encounters.
3. Pick a Fight — Initiate combat with a monster.
4. Cook and Eat — Prepare and eat food to help your party survive.
5. Give Up — End your attempt to escape the dungeon.

### Dungeon Spaces
At the beginning of every turn you are provided with an ASCII map, disclosing various important locations. In this dungeon, spaces are marked differently based on how you can interact with them. 

Spaces marked with '-' are normal spaces

Spaces marked 'N' are spaces that hold the wandering merchant

Spaces marked 'R' contain a room

The space marked 'E' is the dungeon exit

### Winning the Game
To win, you must find a key and reach the dungeon exit (E). Once you have a key, make your way to the exit to escape the dungeon and secure your victory.

### Party Status and Losing Conditions
At the end of every turn, you will receive a status update on your party. You can check the Sorcerer's Anger as part of your party's status.

You will lose the game if any of the following conditions occur:

The Sorcerer's Anger reaches 100, causing him to destroy the dungeon

All your party members die

Your party dies from hunger

### Exploring and Entering Rooms
Throughout the dungeon, you can investigate spaces to discover items, keys, and other encounters. Keys can be found by investigating spaces and defeating monsters.

To enter a room (R), you must either possess a key or win a game of Rock Paper Scissors against the AI.

If you have a key, you can use it to enter the room.

If you attempt Rock Paper Scissors and lose, you must fight a monster.

Losing Rock Paper Scissors does not unlock the room. You must obtain a key or win Rock Paper Scissors to enter it.

### Combat 
Battling monsters involves a complex equation that determines your chances of winning. Equipping better weapons and armor increases your chances of defeating them.

### The Wandering Merchant 
The wandering merchant sells items that can help your party survive the dungeon.

To purchase items, you must first answer a riddle. If you answer incorrectly, you must fight a monster. 

### Random Misfortunes
Every turn, there is a high chance that a random misfortune will occur, damaging your party. Be prepared for unexpected setbacks as you explore the dungeon.

## Installation & Setup
- Download the zip file and open within your chosen IDE

- Ensure all files are in the same directory as the cpp files in order to successfully compile.

  MainMenu.h, Map.h, Party.h and Player.h, monster.txt, monsters.txt, OGmonster.txt, OGriddle.txt, riddle.txt, riddles.txt 
  must be in the same directory as the cpp files.

- For a g++ compiler:

  Compile: g++ -std=c++17 dungeonEscape.cpp MainMenu.cpp Map.cpp Party.cpp Player.cpp 

  Run: ./a.out

## Future Improvements
- Add more internal games similar to the already included rock paper scissors and riddles

## Authors
Harrison Perlstein & Robby Toomey
