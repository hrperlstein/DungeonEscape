// CSCI1300 Fall 2022
// Author: Harrison Perlstein and Robby Toomey
// CSCI 1300-307 TA: Zachary Atkins
// Project 3 - Dungeon Escape - Party Class

#include "Party.h" 
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
Party::Party() //default constructor
{
    gold = 100;
    party_size = 5; 
    
    //ingredients
    kg = 0;

    //cookware
    ceramic_pot = 0;
    frying_pan = 0;
    cauldron = 0;

    //weapons
    stone_club = 0;
    iron_spear = 0;
    mythril_rapier = 0;
    flaming_battle_ax = 0;
    vorpal_longsword = 0;

    //armor
    armor = 0;

    //treasure
    silver_ring = 0;
    ruby_necklace = 0;
    emerald_bracelet = 0;
    diamond_circlet = 0;
    gem_encrusted_goblet = 0;

    //misc
    rooms_cleared = 0;
    keys_found = 0;
}
//===================================================================================================================================
 
int Party::getPartySize(){
   return party_size;
}

string Party::getPlayerNameAtIndex(int in)
{
    return party[in].getPlayerName();
}
 
Player Party::findPlayer(string p_in){
    for(int i = 0; i < party_size; i++){
        if(party[i].getPlayerName() == p_in){
            return party[i];
        }
    }
    return party[0];
}
 
void Party::addPlayer(Player a){
   for(int i = 0; i < 5; i++){
       if(party[i].getPlayerName() == "dead"){
           party[i] = a;
           return;
       }  
   }
}
 
void Party::killPlayer(string p_in){
    for(int i = 0; i < party_size; i++)
    {
        if(party[i].getPlayerName() == p_in)
        {
            party[i].setPlayerName("dead");
            party_size -= 1;
            party[i].setFullness(0);
            return;
        }
    }
    if (weapon_count() == party_size)
    {
        break_random_weapon();
    }
    if (armor_count() == party_size)
    {
        break_armor();
    }
}

string Party::killRandomPlayer()
{   
    srand(time(0));
    if(party_size == 2){
        for(int i = 0; i < 2; i++){
            if(party[i].getPlayerName() != party_leader){
                string name = party[i].getPlayerName();
                killPlayer(name);
                return name;
            }
        }
    }
    if(party_size == 3){
        for(int i = 0; i < 3; i++){
            if(party[i].getPlayerName() != party_leader){
                string name = party[i].getPlayerName();
                killPlayer(name);
                return name;
            }
        }
    }

    int random = (rand() % 5); 
    while (party[random].getPlayerName() == "dead" || party[random].getPlayerName() == party_leader)
    {
        random = rand() % 5;
    }
    string name = party[random].getPlayerName();
    killPlayer(name);
    return name;
}

void Party::setPartyLeader(){
    party_leader = party[0].getPlayerName();
}

string Party::getPartyLeaderName()
{
    return party_leader;
}
 
void Party::addGold(int g_in){
   gold+=g_in;
}
 
void Party::removeGold(int g_in){
   if(gold - g_in < 0){
       gold = 0;
       return;
   }
   gold -= g_in;
}
 
string Party::subtractRandomPlayerFullness(int f_in){
    srand(time(0));
    int random = rand()%101;
    if(random <= 20){
        party[0].subtractFullness(f_in);
        return party[0].getPlayerName();
    }
    else if(random <= 40){
        party[1].subtractFullness(f_in);
        return party[1].getPlayerName();
    }
    else if(random <= 60){
        party[2].subtractFullness(f_in);
        return party[2].getPlayerName();
    }
    else if(random <= 80){
        party[3].subtractFullness(f_in);
        return party[3].getPlayerName();
    }
    else if(random <= 100){
        party[4].subtractFullness(f_in);
        return party[4].getPlayerName();
    }
    return party[0].getPlayerName();
}

string Party::subtractFullnessAtIndex(int amount, int index){
   party[index].subtractFullness(amount);
   return party[index].getPlayerName();
}
void Party::addFullness(int amount){
   for(int i = 0; i < 5; i++){
        if(party[i].getFullness() + amount > 50){
            party[i].setFullness(50);
            continue;
        }
        if(party[i].getPlayerName() != "dead")
        {
            party[i].addFullness(amount);
        }
   }
}
int Party::getPlayerFullnessAtIndex(int i_in){
    return party[i_in].getFullness();
}


int Party::gold_count()
{
    return gold;
}
//===================================================================================================================================

//ingredients functions
void Party::buy_ingredients(int kg_to_buy, int rooms_cleared) //increase kg by one per one gold
{
    double subtractor = 0;
    for (int i = 0; i < 6; i++)
    {
        if (rooms_cleared == i)
        {
            subtractor = kg_to_buy * (1 + i/4.0);
        }
    }
    int s = subtractor;
    if (gold < s)
    {
        cout << "You don't have enough gold for this purchase." <<endl;
        return;
    }
    gold -= s;
    kg += kg_to_buy; 
}

void Party::add_ingredients(int amount)
{
    kg += amount;
}
void Party::remove_ingredients(int amount)
{
    kg -= amount;
}

void Party::cook_ingredients(int kg_to_cook) //decrease ingredients
{
    if (kg_to_cook >= 0)
    {
        kg -= kg_to_cook;
    }
}

int Party::ingredients_count() //declare getter
{
    return kg;
}
//===================================================================================================================================

//cookware functions
void Party::buy_ceramic_pot(int ceramic_pot_to_buy, int rooms_cleared) //increase cookware item in exchange for gold
{
    double subtractor = 0;
    for (int i = 0; i < 6; i++)
    {
        if (rooms_cleared == i)
        {
            subtractor = ceramic_pot_to_buy * 2 * (1 + i/4.0);
        }
    }
    int s = subtractor;
    if (gold < s)
    {
        cout << "You don't have enough gold for this purchase." <<endl;
        return;
    }
    gold -= s;
    ceramic_pot += ceramic_pot_to_buy;
}
void Party::buy_frying_pan(int frying_pan_to_buy, int rooms_cleared)
{
    double subtractor = 0;
    for (int i = 0; i < 6; i++)
    {
        if (rooms_cleared == i)
        {
            subtractor = frying_pan_to_buy * 10 * (1 + i/4.0);
        }
    }
    int s = subtractor;
    if (gold < s)
    {
        cout << "You don't have enough gold for this purchase." <<endl;
        return;
    }
    gold -= s;
    frying_pan += frying_pan_to_buy;
}
void Party::buy_cauldron(int cauldron_to_buy, int rooms_cleared)
{
    double subtractor = 0;
    for (int i = 0; i < 6; i++)
    {
        if (rooms_cleared == i)
        {
            subtractor = cauldron_to_buy * 20 * (1 + i/4.0);
        }
    }
    int s = subtractor;
    if (gold < s)
    {
        cout << "You don't have enough gold for this purchase." <<endl;
        return;
    }
    gold -= s;
    cauldron += cauldron_to_buy;
}


void Party::break_ceramic_pot() //decrease cookware item by 1
{
    if (ceramic_pot > 0)
    {
        ceramic_pot--;
    }
}

void Party::break_frying_pan()
{
    if (frying_pan > 0)
    {
        frying_pan--;
    }
}
void Party::break_cauldron()
{
    if (cauldron > 0)
    {
        cauldron--;
    }
}


int Party::ceramic_pot_count() //declare getters
{
    return ceramic_pot;
}
int Party::frying_pan_count()
{
    return frying_pan;
}
int Party::cauldron_count()
{
    return cauldron;
}
//===================================================================================================================================

//weapons functions
void Party::buy_stone_club(int stone_club_to_buy, int rooms_cleared)
{
    double subtractor = 0;
    for (int i = 0; i < 6; i++)
    {
        if (rooms_cleared == i)
        {
            subtractor = stone_club_to_buy * 2 * (1 + i/4.0);
        }
    }
    int s = subtractor;
    if (gold < s)
    {
        cout << "You don't have enough gold for this purchase." <<endl;
        return;
    }
    gold -= s;
    stone_club += stone_club_to_buy;
}
void Party::buy_iron_spear(int iron_spear_to_buy, int rooms_cleared)
{
    double subtractor = 0;
    for (int i = 0; i < 6; i++)
    {
        if (rooms_cleared == i)
        {
            subtractor = iron_spear_to_buy * 2 * (1 + i/4.0);
        }
    }
    int s = subtractor;
    if (gold < s)
    {
        cout << "You don't have enough gold for this purchase." <<endl;
        return;
    }
    gold -= s;
    iron_spear += iron_spear_to_buy;
}
void Party::buy_mythril_rapier(int mythril_rapier_to_buy, int rooms_cleared)
{
    double subtractor = 0;
    for (int i = 0; i < 6; i++)
    {
        if (rooms_cleared == i)
        {
            subtractor = mythril_rapier_to_buy * 5 * (1 + i/4.0);
        }
    }
    int s = subtractor;
    if (gold < s)
    {
        cout << "You don't have enough gold for this purchase." <<endl;
        return;
    }
    gold -= s;
    mythril_rapier += mythril_rapier_to_buy;
}
void Party::buy_flaming_battle_ax(int flaming_battle_ax_to_buy, int rooms_cleared)
{
    double subtractor = 0;
    for (int i = 0; i < 6; i++)
    {
        if (rooms_cleared == i)
        {
            subtractor = flaming_battle_ax_to_buy * 15 * (1 + i/4.0);
        }
    }
    int s = subtractor;
    if (gold < s)
    {
        cout << "You don't have enough gold for this purchase." <<endl;
        return;
    }
    gold -= s;
    flaming_battle_ax += flaming_battle_ax_to_buy;
}
void Party::buy_vorpal_longsword(int vorpal_longsword_to_buy, int rooms_cleared)
{   
    double subtractor = 0;
    for (int i = 0; i < 6; i++)
    {
        if (rooms_cleared == i)
        {
            subtractor = vorpal_longsword_to_buy * 50 * (1 + i/4.0);
        }
    }
    int s = subtractor;
    if (gold < s)
    {
        cout << "You don't have enough gold for this purchase." <<endl;
        return;
    }
    gold -= s;
    vorpal_longsword += vorpal_longsword_to_buy;
}

 
void Party::break_stone_club()
{
   if(stone_club > 0)
   {
       stone_club--;
   }
}
void Party::break_iron_spear()
{
   if(iron_spear > 0)
   {
       iron_spear--;
   }
}
void Party::break_mythril_rapier()
{
   if(mythril_rapier > 0)
   {
       mythril_rapier--;
   }
}
void Party::break_flaming_battle_ax()
{
   if(flaming_battle_ax > 0)
   {
        flaming_battle_ax--;
   }
}
void Party::break_vorpal_longsword()
{
   if(flaming_battle_ax > 0)
   {
       vorpal_longsword--;
   }
}
string Party::break_random_weapon(){
   srand(time(0));
   int random = rand()%101;
 
   if(random < 20){
       break_stone_club();
       return "stone club";
   }
   else if(random < 40){
       break_iron_spear();
       return "spear";
   }
   else if(random < 60){
       break_mythril_rapier();
       return "mythril rapier";
   }
   else if(random < 80){
       break_vorpal_longsword();
       return "vorpal longsword";
   }
   else if(random < 100){
       break_flaming_battle_ax();
       return "flaming battle ax";
   }
   return "";
}


int Party::stone_club_count() //declare getters
{
    return stone_club;
}
int Party::iron_spear_count()
{
    return iron_spear;
}
int Party::mythril_rapier_count()
{
    return mythril_rapier;
}
int Party::flaming_battle_ax_count()
{
    return flaming_battle_ax;
}
int Party::vorpal_longsword_count()
{
    return vorpal_longsword;
}
int Party::weapon_count()
{
    return stone_club + iron_spear + mythril_rapier + flaming_battle_ax + vorpal_longsword;
}
//===================================================================================================================================

//armor functions
void Party::buy_armor(int armor_to_buy, int rooms_cleared)
{
    double subtractor = 0;
    for (int i = 0; i < 6; i++)
    {
        if (rooms_cleared == i)
        {
            subtractor = armor_to_buy * 5 * (1 + i/4.0);
        }
    }
    int s = subtractor;
    if (gold < s)
    {
        cout << "You don't have enough gold for this purchase." <<endl;
        return;
    }
    gold -= s;
    armor += armor_to_buy;
}

void Party::addArmor()
{
    armor += 1;
}

void Party::break_armor()
{
    if(armor > 0)
    {
        armor--;
    }
}

int Party::armor_count() //declare getter
{
    return armor;
}
//===================================================================================================================================

//treasure functions
void Party::find_silver_ring()
{
    silver_ring++;
}
void Party::find_ruby_neckalace()
{
    ruby_necklace++;
}
void Party::find_emerald_bracelet()
{
    emerald_bracelet++;
}
void Party::find_diamond_circlet()
{
    diamond_circlet++;
}
void Party::find_gem_encrusted_goblet()
{
    gem_encrusted_goblet++;
}


void Party::sell_silver_ring(int treasure_to_sell)
{
    if (silver_ring >= treasure_to_sell)
    {
        silver_ring -= treasure_to_sell;
        gold += treasure_to_sell * 10;
    }
    else
    {
        cout << "You are trying to sell more of this treasure than you have in your possession." <<endl;
    }
}
void Party::sell_ruby_neckalace(int treasure_to_sell)
{
    if (ruby_necklace >= treasure_to_sell)
    {
        ruby_necklace -= treasure_to_sell;
        gold += treasure_to_sell * 20;
    }
    else
    {
        cout << "You are trying to sell more of this treasure than you have in your possession." <<endl;
    }
}
void Party::sell_emerald_bracelet(int treasure_to_sell)
{
    if (emerald_bracelet >= treasure_to_sell)
    {
        emerald_bracelet -= treasure_to_sell;
        gold += treasure_to_sell * 30;
    }
    else
    {
        cout << "You are trying to sell more of this treasure than you have in your possession." <<endl;
    }
}
void Party::sell_diamond_circlet(int treasure_to_sell)
{
    if (diamond_circlet >= treasure_to_sell)
    {
        diamond_circlet -= treasure_to_sell;
        gold += treasure_to_sell * 40;
    }
    else
    {
        cout << "You are trying to sell more of this treasure than you have in your possession." <<endl;
    }
}
void Party::sell_gem_encrusted_goblet(int treasure_to_sell)
{
    if (gem_encrusted_goblet >= treasure_to_sell)
    {
        gem_encrusted_goblet -= treasure_to_sell;
        gold += treasure_to_sell * 50;
    }
    else
    {
        cout << "You are trying to sell more of this treasure than you have in your possession." <<endl;
    }
}


int Party::silver_ring_count()
{
    return silver_ring;
}
int Party::ruby_necklace_count()
{
    return ruby_necklace;
}
int Party::emerald_bracelet_count()
{
    return emerald_bracelet;
}
int Party::diamond_circlet_count()
{
    return diamond_circlet;
}
int Party::gem_encrusted_goblet_count()
{
    return gem_encrusted_goblet;
}
int Party::treasure_count()
{
    return silver_ring + ruby_necklace + emerald_bracelet + diamond_circlet + gem_encrusted_goblet;
}


//misc
int Party::getKeysFound()
{
    return keys_found;
}
int Party::getRoomsCleared()
{
    return rooms_cleared;
}
void Party::addKey()
{
    keys_found += 1;
}
void Party::subtractKey()
{
    keys_found -= 1;
}
void Party::addRoomCleared(int a_in)
{
    rooms_cleared += a_in;
}
void Party::subtractRoomCleared(int a_in){
    rooms_cleared -= a_in;
}

void Party::sort()
{   
    int alive = party_size;
    string temp_name[5];
    int arr[5];
    string name_arr[5];
    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        if (party[i].getPlayerName() != "dead")
        {
            arr[count] = party[i].getFullness();
            temp_name[count] = party[i].getPlayerName();
            count++;
        }
    }

    int temp[5];
    for (int i = 0; i < alive; i++)
    {
        int max = -9999;
        string name = "";
        for (int j = 0; j < alive; j++) //finds min
        { 
            if (arr[j] > max) 
            {
                max = arr[j];
                name = temp_name[j];
            }
        }
        bool first_time = true;
        for (int j = 0; j < alive; j++) 
        {
            if (arr[j] == max && first_time == true) 
            {
                arr[j] = -9999;
                first_time = false;          
            }
        }

        temp[i] = max;
        name_arr[i] = name;
    }
    for (int i = 0; i < alive; i++)
    {
        cout << "| " << name_arr[i] << " | Fullness: " << temp[i] << endl;
    }
}