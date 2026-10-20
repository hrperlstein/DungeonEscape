// CSCI1300 Fall 2022
// Author: Harrison Perlstein and Robby Toomey
// CSCI 1300-307 TA: Zachary Atkins
// Project 3 - Dungeon Escape - Party Class

#ifndef PARTY_H
#define PARTY_H
 
#include "Player.h"
#include <iostream>
using namespace std;
 
class Party
{
    private:
    int gold;
    Player party[5];
    int party_size;

    //ingredients
    int kg;

    //cookware
    int ceramic_pot; //break percent 25%
    int frying_pan; //break percent 10%
    int cauldron; //break percent 2%

    //weapons
    int stone_club;
    int iron_spear;
    int mythril_rapier;
    int flaming_battle_ax;
    int vorpal_longsword;

    //armor
    int armor;

    //treasure
    int silver_ring;
    int ruby_necklace;
    int emerald_bracelet;
    int diamond_circlet;
    int gem_encrusted_goblet;

    //misc
    int rooms_cleared;
    int keys_found;

    string party_leader;

    public:
    Party(); //default constructor
    int getPartySize();
    string getPlayerNameAtIndex(int in);
    string getPartyLeaderName();
    Player findPlayer(string p);
    void addPlayer(Player a);
    void killPlayer(string p);
    string killRandomPlayer();
    void addGold(int g);
    void removeGold(int g);
    string subtractRandomPlayerFullness(int f);
    string subtractFullnessAtIndex(int amount, int index);
    void addFullness(int amount);
    int getPlayerFullnessAtIndex(int i);
    void setPartyLeader();

    void sort();


    int gold_count();

    //ingredients
    void buy_ingredients(int kg_to_buy, int rooms_cleared); //increase kg by one per one gold
    void add_ingredients(int amount);
    void remove_ingredients(int amount);
    void cook_ingredients(int kg_to_cook); //decrease ingredients

    int ingredients_count(); //declare getter
    
    //cookware
    void buy_ceramic_pot(int ceramic_pot_to_buy, int rooms_cleared); //increase cookware item by one and take gold
    void buy_frying_pan(int frying_pan_to_buy, int rooms_cleared);
    void buy_cauldron(int cauldron_to_buy, int rooms_cleared);

    void break_ceramic_pot(); //decrease cookware item by one
    void break_frying_pan();
    void break_cauldron();

    int ceramic_pot_count(); //declare getters
    int frying_pan_count();
    int cauldron_count();

    //weapons
    void buy_stone_club(int stone_club_to_buy, int rooms_cleared); //increase weapon by one and take gold
    void buy_iron_spear(int iron_spear_to_buy, int rooms_cleared);
    void buy_mythril_rapier(int mythril_rapier_to_buy, int rooms_cleared);
    void buy_flaming_battle_ax(int flaming_battle_ax_to_buy, int rooms_cleared);
    void buy_vorpal_longsword(int vorpal_longsword_to_buy, int rooms_cleared);

    void break_stone_club(); //decrease weapon by one
    void break_iron_spear();
    void break_mythril_rapier();
    void break_flaming_battle_ax();
    void break_vorpal_longsword();

    int stone_club_count(); //declare getters
    int iron_spear_count();
    int mythril_rapier_count();
    int flaming_battle_ax_count();
    int vorpal_longsword_count();
    int weapon_count();
    string break_random_weapon();

    //armor
    void buy_armor(int armor_to_buy, int rooms_cleared); //increase armor count and take gold

    void break_armor();

    int armor_count(); //declare getter

    //treasure
    void find_silver_ring();
    void find_ruby_neckalace();
    void find_emerald_bracelet();
    void find_diamond_circlet();
    void find_gem_encrusted_goblet();

    void sell_silver_ring(int treasure_to_sell); //increase gold, decrease treasure
    void sell_ruby_neckalace(int treasure_to_sell);
    void sell_emerald_bracelet(int treasure_to_sell);
    void sell_diamond_circlet(int treasure_to_sell);
    void sell_gem_encrusted_goblet(int treasure_to_sell);

    int silver_ring_count(); //delcare getters
    int ruby_necklace_count();
    int emerald_bracelet_count();
    int diamond_circlet_count();
    int gem_encrusted_goblet_count();
    int treasure_count();

    int getKeysFound();
    int getRoomsCleared();
    void addKey();
    void subtractKey();
    void addRoomCleared(int a);
    void subtractRoomCleared(int a);

    void addArmor();
};
 
#endif

