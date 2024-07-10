/***********************************************************
 ** File:    Mutalisk.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hasnain Ali
 ** Date     11/7/2022
 ** Section: 10/15
 ** This file contains the code for the header file of the Mutalisk class
 **********************************************************/

#include "Mutalisk.h"
using namespace std;

// Mutalisk()
// Constructor for Mutalisk
Mutalisk::Mutalisk() {
}

// Mutalisk(string name, int health)
// Overloaded constructor for Mutalisk
Mutalisk::Mutalisk(string name, int health) {
  SetName(name);
  SetHealth(health);
}

// SpecialAttack()
// Defines the Mutalisk's special attack and returns damage
int Mutalisk::SpecialAttack() {
  int damage = 4;                                                                                // An int representing the damage done by a special attack
  cout << "Mutalisk blasts you with their attack! \n";
  return damage;
}

