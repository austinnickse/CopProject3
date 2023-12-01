#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> //For rand
#include <fstream>

//Created by Austin Nickse on 11/28/2023
//Creates data set for project 3


std::vector<std::string> createWeapons() {
    std::vector<std::string> prefix;
    prefix.push_back("Moonlight");
    prefix.push_back("Godly");
    prefix.push_back("Deadly");
    prefix.push_back("Sharp");
    prefix.push_back("Sleek");
    prefix.push_back("Rotten");
    prefix.push_back("Agonizing");
    prefix.push_back("Marksmanship");
    prefix.push_back("War-ready");
    prefix.push_back("Knightly");
    prefix.push_back("Wizardly");
    prefix.push_back("Holy");
    prefix.push_back("Damp");
    prefix.push_back("Worn");
    prefix.push_back("New");
    prefix.push_back("Bloody");
    prefix.push_back("Weeping");
    prefix.push_back("Inferno");
    prefix.push_back("Frosty");
    prefix.push_back("Cold");
    prefix.push_back("Icy");
    prefix.push_back("Dragonbone");
    prefix.push_back("Combat");
    prefix.push_back("Otherworldly");
    prefix.push_back("Hellish");
    prefix.push_back("Heavenly");
    prefix.push_back("Light");
    prefix.push_back("Dark");
    prefix.push_back("Ephemeral");
    prefix.push_back("Iridescent");
    prefix.push_back("Crimson");
    prefix.push_back("White");
    prefix.push_back("Gray");
    prefix.push_back("Black");
    prefix.push_back("Carbon");
    prefix.push_back("Steel");
    prefix.push_back("Copper");
    prefix.push_back("Zinc");
    prefix.push_back("Gold");
    prefix.push_back("Silver");
    prefix.push_back("Dirty");
    prefix.push_back("Clean");
    prefix.push_back("Heroic");
    prefix.push_back("Villainous");
    prefix.push_back("Sunlight");
    prefix.push_back("Scarred");
    prefix.push_back("Divine");

    std::vector<std::string> type;
    type.push_back("Sword");
    type.push_back("Greatsword");
    type.push_back("Katana");
    type.push_back("Lance");
    type.push_back("Rapier");
    type.push_back("Crossbow");
    type.push_back("Bow");
    type.push_back("Longbow");
    type.push_back("Wand");
    type.push_back("Staff");
    type.push_back("Mace");
    type.push_back("Whip");
    type.push_back("Gloves");
    type.push_back("Bat");
    type.push_back("Pipe");
    type.push_back("Flail");
    type.push_back("Scythe");
    type.push_back("Shuriken");
    type.push_back("Kunai");
    type.push_back("Tanto");
    type.push_back("Knife");
    type.push_back("Cleaver");
    type.push_back("Saw");
    type.push_back("Fist");
    type.push_back("Claw");
    type.push_back("Hook");
    type.push_back("Spear");
    type.push_back("Pike");
    type.push_back("Shield");
    type.push_back("Greatshield");
    type.push_back("Shortshield");
    type.push_back("Scimitar");
    type.push_back("Fireball");
    type.push_back("Iceball");
    type.push_back("Magic");
    type.push_back("Falchion");
    type.push_back("Dual-swords");
    type.push_back("Javelin");
    type.push_back("Spell-Tome");
    type.push_back("Spell-Book");
    type.push_back("Hammer");
    type.push_back("Throwing-Knives");
    type.push_back("Club");
    type.push_back("Morning-Star");
    type.push_back("Saber");
    type.push_back("Pick");
    type.push_back("Estoc");

    std::vector<std::string> names;

    for (int i = 0; i < prefix.size(); i++) {
        for (int j = 0; j < prefix.size(); j++) {
            for (int z = 0; z < prefix.size(); z++) {
                if (i != j) {
                    names.push_back(prefix[i] + " " + prefix[j] + " " + type[z]);
                }
            }
        }
    }

    /* SHOWS NAME OF EACH WEAPON
    for (std::string x : names) {
        std::cout << x << "\n";
    }
    */


    // THERE ARE `~101000`DIFFERENT WEAPONs, ALL UNIQUE
    //std::cout << names.size();

    return names;
};

int main() {
    std::vector<std::string> names = createWeapons();

    //Now we will create stats for each weapon - base stats and scaling stats
    std::ofstream MyFile("weapon_data3.txt");
    for (std::string x : names) {
        int base = rand() % 300 + 1; //Base is from 1-300
        int vigor = rand() % 10 + 1; //All scaling stats are randomized on a scale of 1-10
        int mind = rand() % 10 + 1;
        int endurance = rand() % 10 + 1;
        int strength = rand() % 10 + 1;
        int dexterity = rand() % 10 + 1;
        int intelligence = rand() % 10 + 1;
        int faith = rand() % 10 + 1;
        int arcane = rand() % 10 + 1;
        MyFile << x << " " << base << " " << vigor << " " << mind << " " << endurance  << " " << strength
               << " " << dexterity  << " " << intelligence  << " " << faith  << " " << arcane << "\n";
        /* BELOW FOR TESTING
        std::cout << x << " " << base << " " << vigor << " " << mind << " " << endurance  << " " << strength
                << " " << dexterity  << " " << intelligence  << " " << faith  << " " << arcane << "\n";
        /* FOR TTESTING - Says each respective stat
         * std::cout << x << " Base: " << base << " Vigor: " << vigor << " Mind: " << mind << " Endurance: " << endurance  << " Strength: " << strength
                << " Dexterity: " << dexterity  << " Intelligence: " << intelligence  << " Faith: " << faith  << " Arcane: " << arcane << "\n";
        */
    }
    return 0;
}
