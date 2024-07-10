/***********************************************************
 ** File:    Ghost.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hasnain Ali
 ** Date     11/7/2022
 ** Section: 10/15
 ** This file contains the code for the header file of the Ghost class
 **********************************************************/

#include "Ghost.h"
using namespace std;

// Ghost()
// Constructor for Ghost
Ghost::Ghost() {
}

// Ghost(string name, int health)
// Overloaded constructor for Ghost
Ghost::Ghost(string name, int health) {
  SetName(name);
  SetHealth(health);
}

// ~Ghost()
// Destructor for Ghost
Ghost::~Ghost() {
}

// SpecialAttack()
// Defines the Ghost's special attack and returns damage
int Ghost::SpecialAttack() {
  int damage = (rand() % 11) + 2;                                                                    // An int representing the damage done by a special attack
  cout << GetName() << " performs a sneak attack! \n";
  cout << GetName() << " deals " << damage << " damage! \n";
  return damage;
}
