#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> //For rand
#include <fstream>
#include <ctime>
#include "Weapon.h"


using namespace std;

//Created by Austin Nickse on 11/28/2023
//Creates data set for project 3


std::vector<std::string> createWeapons();

void initializeWeapons(vector<string> names);
int totalDamage(weapon cur, int vigor, int mind, int endurance, int strength, int dexterity, int intelligence, int faith, int arcane);

//merge sort
void merge(vector<weapon>& vec, int left, int mid, int right, int choice);
void mergeSort(vector<weapon>& vec, int left, int right, int choice);

//quick sort
int partition(vector<weapon>& vec, int low, int high, int choice);
void quickSort(vector<weapon>& vec, int low, int high, int choice);
void swap(int& a, int& b);

void printVector(vector<weapon>& vec);
void topWeapons(vector<weapon>& vec);

int main() {


    ifstream myfile("weapon_data3.txt");
    string text;
    string word;
    vector<weapon> weaponlist;
    while (getline(myfile, text)) { //Splits .txt into lines - Inspired by https://www.w3schools.com/cpp/cpp_files.asp
        istringstream iss(text);
        weapon cur; //create new weapon
        string name; //Since a weapons name is multiple words we need to concatenate it separately
        int i = 0; //keeps track of which stat we are accessing
        while (std::getline(iss, word, ' ')) { //Splits lines into words - Inspired by https://www.geeksforgeeks.org/split-a-sentence-into-words-in-cpp/
            switch (i) {
                case 0: //All weapon names are 3 words so 0-2 are all adding to the name
                    cur.name = word;
                    break;
                case 1:
                    cur.name = cur.name + " " + word;
                    break;
                case 2:
                    cur.name = cur.name + " " + word;
                    break;
                case 3: //otherwise its a number so add stats
                    cur.baseDamage = std::stoi(word);
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
    cout << "Enter Vigor Level: " << std::left;
    cin >> vigor;
    cout << "Enter Mind Level: " << std::left;
    cin >> mind;
    cout << "Enter Endurance Level: " << std::left;
    cin >> endurance;
    cout << "Enter Strength Level: " << std::left;
    cin >> strength;
    cout << "Enter Dexterity Level: " << std::left;
    cin >> dexterity;
    cout << "Enter Intelligence Level: " << std::left;
    cin >> intelligence;
    cout << "Enter Faith Level: " << std::left;
    cin >> faith;
    cout << "Enter Arcane Level: " << std::left;
    cin >> arcane;

    //int highestDamage = 0;
    int damage;
    //weapon bestWeapon;
    for (int i = 0;  i < weaponlist.size(); i++) {
        weaponlist[i].vigor = weaponlist[i].vigor * vigor;
        weaponlist[i].mind = weaponlist[i].mind * mind;
        weaponlist[i].endurance = weaponlist[i].endurance * endurance;
        weaponlist[i].strength = weaponlist[i].strength * strength;
        weaponlist[i].dexterity = weaponlist[i].dexterity * dexterity;
        weaponlist[i].intelligence = weaponlist[i].intelligence * intelligence;
        weaponlist[i].faith = weaponlist[i].faith * faith;
        weaponlist[i].arcane = weaponlist[i].arcane * arcane;
        damage = totalDamage(weaponlist[i], weaponlist[i].vigor, weaponlist[i].mind, weaponlist[i].endurance,
                             weaponlist[i].strength, weaponlist[i].dexterity,
                             weaponlist[i].intelligence, weaponlist[i].faith, weaponlist[i].arcane);
        weaponlist[i].totalDamage = damage;
        /* For testing to see if the correct weapon is chosen
        if (damage > highestDamage) {
            bestWeapon = weaponlist[i];
            highestDamage = damage;
        }
         */
    }
    //cout << "Based on your stats, here is the best weapon for you and it's statistics: " << endl;
    //bestWeapon.printData();


    string sort;
    cout << "Choose sorting methods - 'q' for quicksort or 'm' for mergesort: ";
    cin >> sort;

    cout << endl;

    int choice;
    cout << "How would you like to sort the data? (Please enter a number from 1-10) \n" <<
         "1. Base Damage \n" <<
         "2. Vigor \n" <<
         "3. Mind \n" <<
         "4. Endurance \n" <<
         "5. Strength \n" <<
         "6. Dexterity \n" <<
         "7. Intelligence \n" <<
         "8. Faith \n" <<
         "9. Arcane \n" <<
         "10. Total Damage" << endl;
    cin >> choice;


    int size = weaponlist.size();
    //quickSort(vec, 0, size - 1);
    //mergeSort(vec, 0, size - 1);

    clock_t t;
    t = clock();
    if (sort == "q") {
        quickSort(weaponlist,0 , size-1, choice);
    }
    else if (sort == "m") {
        mergeSort(weaponlist, 0, size-1, choice);
    }
    else {
        cout << "Invalid input";
        //NEED TO MAKE IT PROMPT FOR SORT METHOD AGAIN
    }
    t = clock() - t;

    cout << "It took " << t << " milliseconds seconds to sort the vector" << endl;


    //cout << "Sorted Vector:" << endl;
    topWeapons(weaponlist);


    //BELOW IS JUST SO PROGRAM HANGS ON SCREEN SO YOU CAN READ THE RESULTS
    string end;
    cin >> end;
    if (end == "e") {
        return 0;
    }
    return 0;
}


int totalDamage(weapon cur, int vigor, int mind, int endurance, int strength, int dexterity, int intelligence, int faith, int arcane) {
    //set all correct values for when we sort later
    return (cur.baseDamage + cur.vigor + cur.mind + cur.endurance + cur.strength + cur.dexterity + cur.intelligence + cur.faith
    + cur.arcane);
}


//merge 2 subvectors
void merge(vector<weapon>& vec, int left, int mid, int right, int choice)
{

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<weapon> x(n1), y(n2);

    for (int i = 0; i < n1; i++)
        x[i] = vec[left + i];
    for (int j = 0; j < n2; j++)
        y[j] = vec[mid + 1 + j];


    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (x[i].correctAttribute(choice) <= y[j].correctAttribute(choice))
        {
            vec[k] = x[i];
            i++;
        }
        else
        {
            vec[k] = y[j];
            j++;
        }
        k++;
    }

    while (i < n1) //append remaining elements when we run out in x and y
    {
        vec[k] = x[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vec[k] = y[j];
        j++;
        k++;
    }
}


void mergeSort(vector<weapon>& vec, int left, int right, int choice)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // vector divided into 2 subvectors at this point

        mergeSort(vec, left, mid, choice);
        mergeSort(vec, mid + 1, right, choice);

        // merge the sorted subvectors
        merge(vec, left, mid, right, choice);
    }
}




int partition(vector<weapon>& vec, int low, int high, int choice) //partition vector based on pivot element
{

    int pivot = vec[low].correctAttribute(choice);
    int up = low, down = high;

    while (up < down)
    {
        for (int j = up; j < high; j++)
        {
            if (vec[up].correctAttribute(choice) > pivot)
                break;
            up++;
        }
        for (int j = high; j > low; j--)
        {
            if (vec[down].correctAttribute(choice) < pivot)
                break;
            down--;
        }
        if (up < down)
            swap(vec[up], vec[down]);
    }
    swap(vec[low], vec[down]);
    return down;
}

void quickSort(vector<weapon>& vec, int low, int high, int choice)
{
    if (low < high)
    {
        int pivot = partition(vec, low, high, choice);
        quickSort(vec, low, pivot - 1, choice);
        quickSort(vec, pivot + 1, high, choice);
    }
}

void swap(int& a, int& b) {
    int num = a;
    a = b;
    b = num;
}

void topWeapons(vector<weapon>& vec) {
    int displaynum;
    std::cout << "How many weapons do you want to display? ";
    std::cin >> displaynum;
    std::cout << "\n";
    for (int i = 1; i <= displaynum; i++) {
        std::cout << i << ": ";
        vec[vec.size() - i].printData();
    }
}

//print vector function used for testing
/*
void printVector(vector<weapon>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        vec[i].printData();
    }
}
 */





