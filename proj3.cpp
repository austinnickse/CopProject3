//
// Created by Austin Nickse on 11/27/2023.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class weapon {
public:
    std::string name;
    int base;
    int vigor;
    int mind;
    int endurance;
    int strength;
    int dexterity;
    int intelligence;
    int faith;
    int arcane;
    int total; //Will store total damage when calculated
};

int totalDamage(weapon cur, int vigor, int mind, int endurance, int strength, int dexterity, int intelligence, int faith, int arcane) {
    return (cur.base + cur.vigor * vigor + cur.mind * mind + cur.endurance * endurance + cur.strength * strength
            + cur.dexterity * dexterity + cur.intelligence * intelligence + cur.faith * faith + cur.arcane * arcane);
}

void mergeSort (std::vector<weapon> weapons) {

}

void quickSort (std::vector<weapon> weapons) {

}

int main() {
    std::ifstream myfile ("weapon_data3.txt");
    std::string text;
    std::string word;
    std::vector<weapon> weaponlist;
    while (getline (myfile, text)) { //Splits .txt into lines - Inspired by https://www.w3schools.com/cpp/cpp_files.asp
        std::istringstream iss(text);
        weapon cur; //create new weapon
        std::string name; //Since a weapons name is multiple words we need to concatenate it separately
        int i = 0; //keeps track of which stat we are accessing
        while (std::getline(iss, word, ' ')) { //Splits lines into words - Inspired by https://www.geeksforgeeks.org/split-a-sentence-into-words-in-cpp/
            switch(i) {
                case 0: //All weapon names are 3 words so 0-2 are all adding to the name
                    cur.name = word;
                    break;
                case 1 ... 2:
                    cur.name = cur.name + " " + word;
                    break;
                case 3: //otherwise its a number so add stats
                    cur.base = std::stoi(word);
                    break;
                case 4:
                    cur.vigor = std::stoi(word);
                    break;
                case 5:
                    cur.mind = std::stoi(word);
                    break;
                case 6:
                    cur.endurance = std::stoi(word);
                    break;
                case 7:
                    cur.strength = std::stoi(word);
                    break;
                case 8:
                    cur.dexterity = std::stoi(word);
                    break;
                case 9:
                    cur.intelligence = std::stoi(word);
                    break;
                case 10:
                    cur.faith = std::stoi(word);
                    break;
                case 11:
                    cur.arcane = std::stoi(word);
                    break;

            }
            i++;
        }
        weaponlist.push_back(cur);
    }
    int vigor, mind, endurance, strength, dexterity, intelligence, faith, arcane; //user inputs
    std::cout << "Enter Vigor Level:";
    std::cin >> vigor;
    std::cout << "Enter Mind Level:";
    std::cin >> mind;
    std::cout << "Enter Endurance Level:";
    std::cin >> endurance;
    std::cout << "Enter Strength Level:";
    std::cin >> strength;
    std::cout << "Enter Dexterity Level:";
    std::cin >> dexterity;
    std::cout << "Enter Intelligence Level:";
    std::cin >> intelligence;
    std::cout << "Enter Faith Level:";
    std::cin >> faith;
    std::cout << "Enter Arcane Level:";
    std::cin >> arcane;
    for (weapon x : weaponlist) { //sets correct total damage for every weapon
        x.total = totalDamage(x, vigor, mind, endurance, strength, dexterity, intelligence, faith, arcane);
    }
    std::string sort;
    std::cout << "Choose sorting methods - 'q' for quicksort or 'm' for mergesort";
    std::cin >> sort;
    if (sort == "q") {
        quickSort(weaponlist);
    }
    else if (sort == "m") {
        mergeSort(weaponlist);
    }
    else {
        std::cout << "Invalid input";
        //NEED TO MAKE IT PROMPT FOR SORT METHOD AGAIN
    }





    //BELOW IS TESTING
    //std::cout << "DING"; This shows that it caluclates above statements in less than a second
    //Below for testing
    //std::cout << "Damage of first weapon is " << totalDamage(weaponlist[0], vigor, mind, endurance, strength, dexterity, intelligence, faith, arcane);
    /*
    std::cout <<  "\nWeapon Stats: " << weaponlist[0].name << " " << weaponlist[0].base << " " <<  weaponlist[0].vigor << " " <<  weaponlist[0].mind
    << " " <<  weaponlist[0].endurance << " " <<  weaponlist[0].strength << " " <<  weaponlist[0].dexterity <<  " " << weaponlist[0].intelligence
            << " " <<  weaponlist[0].faith <<  " " << weaponlist[0].arcane;
            */

}










