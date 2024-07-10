/***********************************************************
 ** File:    Battlecruiser.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hasnain Ali
 ** Date     11/7/2022
 ** Section: 10/15
 ** This file contains the code for the header file of the Battlecruiser class
 **********************************************************/

#include "Battlecruiser.h"
using namespace std;

// Battlecruiser()
// Constructor for Battlecruiser
Battlecruiser::Battlecruiser() {
}

// Battlecruiser(string name, int health)
// Overloaded constructor for Battlecruiser
Battlecruiser::Battlecruiser(string name, int health) {
  SetName(name);
  SetHealth(health);
}

// ~Battlecruiser()
// Destructor for Battlecruiser
Battlecruiser::~Battlecruiser() {
}

// SpecialAttack()
// Defines the Battlecruiser's special attack and returns damage
int Battlecruiser::SpecialAttack() {
  int damage = (rand() % 10) + 3;                                                                      // An int representing the damage done by a special attack
  cout << GetName() << " uses the Yomato Cannon! \n";
  cout << GetName() << " deals " << damage << " damage! \n";
  return damage;
}

