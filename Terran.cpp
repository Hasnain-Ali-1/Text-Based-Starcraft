/***********************************************************
 ** File:    Terran.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hasnain Ali
 ** Date     11/7/2022
 ** Section: 10/15
 ** This file contains the code for the header file of the Terran class
 **********************************************************/

#include "Terran.h"
using namespace std;

// Terran()
// Constructor for Terran
Terran::Terran() {
}

// Terran(string name, int health)
// Overloaded constructor for Terran
Terran::Terran(string name, int health) {
  SetName(name);
  SetHealth(health);
}

// ~Terran()
// Destructor for Terran
Terran::~Terran() {
}

// Attack()
// Describes attack statments for Terrans and returns damage
int Terran::Attack() {
  int damage = (rand() % 6) + 1;                                                                    // An int representing the damage done by a normal attack
  // Different cout statements depending on damage
  if (damage == 1) {
    cout << GetName() << " attacks dealing "<< damage << " point of damage! \n";
  }
  else {
    cout << GetName() << " attacks dealing "<< damage << " points of damage! \n";
  }
  return damage;
}

// SpecialAttack()
// Tells players Terrans don't have special attacks, can be used
// to call child class SpecialAttack
int Terran::SpecialAttack() {
  int damage = 0;                                                                                   // An int representing the damage done by a special attack
  cout << "Terran's have no special attack! \n";
  return damage;
}
