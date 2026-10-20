// CSCI1300 Fall 2022
// Author: Harrison Perlstein and Robby Toomey
// CSCI 1300-307 TA: Zachary Atkins
// Project 3 - Dungeon Escape - Player Class

#include "Player.h"

#include <iostream>
using namespace std;

Player::Player(){
    player_name = "dead";
    fullness = 0;
}

Player::Player(string p_in){
    player_name = p_in;
    fullness = 50;
}

void Player::setPlayerName(string p_in){
    player_name = p_in;
}

void Player::addFullness(int f_in){
    fullness += f_in;
}

void Player::subtractFullness(int& f_in){
    fullness -= f_in;
}
void Player::setFullness(int amount){
    fullness = amount;
}

string Player::getPlayerName(){
    return player_name;
}
int Player::getFullness(){
    return fullness;
}


