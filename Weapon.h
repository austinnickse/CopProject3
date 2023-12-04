#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class weapon {
public:
    std::string name;
    int baseDamage;
    int vigor;
    int mind;
    int endurance;
    int strength;
    int dexterity;
    int intelligence;
    int faith;
    int arcane;
    int totalDamage; //Will store total damage when calculated

    int correctAttribute(int pick) const;
    void printData();
};