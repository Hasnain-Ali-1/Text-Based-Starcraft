/***********************************************************
 ** File:    Marine.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hasnain Ali
 ** Date     11/7/2022
 ** Section: 10/15
 ** This file contains the code for the header file of the Marine class
 **********************************************************/

#include "Marine.h"
using namespace std;

// Marine()
// Constructor for Marine
Marine::Marine() {
}

// Marine(string name, int health)
// Overloaded constructor for Marine
Marine::Marine(string name, int health) {
  SetName(name);
  SetHealth(health);
}

// ~Marine()
// Destructor for marine
Marine::~Marine() {
}

// SpecialAttack()
// Defines the Marine's special attack and returns damage
int Marine::SpecialAttack() {
  int damage = (rand() % 8) + 1;                                                                   // An int representing the damage done by a special attack
  cout << GetName() << " spins up doing GATLING DAMAGE! \n";
  cout << GetName() << " deals " << damage << " damage! \n"; 
  return damage;
}
