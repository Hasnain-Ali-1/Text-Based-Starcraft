/***********************************************************
 ** File:    Zergling.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hasnain Ali
 ** Date     11/7/2022
 ** Section: 10/15
 ** This file contains the code for the header file of the Zergling class
 **********************************************************/

#include "Zergling.h"
using namespace std;

// Zergling()
// Constructor for Zergling
Zergling::Zergling() {
}

// Zergling(string name, int health)
// Overloaded constructor for Zergling
Zergling::Zergling(string name, int health) {
  SetName(name);
  SetHealth(health);
}

// SpecialAttack()
// Defines the Zergling's special attack and returns damage
int Zergling::SpecialAttack() {
  cout << "Zergling scratches at you ferociously! \n";
  int damage = 1;                                                                                  // An int representing the damage done by a special attack
  return damage;
}
