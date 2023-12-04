
#include "Weapon.h"



void weapon::printData() {

    cout << "Weapon Name: " << name;
    cout << " Base: " << baseDamage;
    cout << " Vigor: " << vigor;
    cout << " Mind: " << mind;
    cout << " Endurance: " << endurance;
    cout << " Strength: " << strength;
    cout << " Dexterity: " << dexterity;
    cout << " Intelligence: " << intelligence;
    cout << " Faith: " << faith;
    cout << " Arcane: " << arcane;
    cout << " Total Damage: " << totalDamage << endl;
}

int weapon::correctAttribute(int pick) const { //This is used for sorting according to the correct attribute
    switch (pick) {
        case 1:
            return this->baseDamage;
        case 2:
            return this->vigor;
        case 3:
            return this->mind;
        case 4:
            return this->endurance;
        case 5:
            return this->strength;
        case 6:
            return this->dexterity;
        case 7:
            return this->intelligence;
        case 8:
            return this->faith;
        case 9:
            return this->arcane;
        case 10:
            return this->totalDamage;
    }
}