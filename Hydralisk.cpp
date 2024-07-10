/***********************************************************
 ** File:    Hydralisk.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hasnain Ali
 ** Date     11/7/2022
 ** Section: 10/15
 ** This file contains the code for the header file of the Hydralisk class
 **********************************************************/

#include "Hydralisk.h"
using namespace std;

// Hydralisk()
// Constructor for Hydralisk
Hydralisk::Hydralisk() {
}

// Hydralisk(string name, int health)
// Overloaded constructor for Hydralisk
Hydralisk::Hydralisk(string name, int health) {
  SetName(name);
  SetHealth(health);
}

// SpecialAttack()
// Defines the Hydralisk's special attack and returns damage
int Hydralisk::SpecialAttack() {
  int damage = 2;                                                                                         // An int representing the damage done by a special attack
  cout << "Hydralisk sprays you with deadly acid! \n";
  return damage;
}
