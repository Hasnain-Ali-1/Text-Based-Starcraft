/***********************************************************
 ** File:    Zerg.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hasnain Ali
 ** Date     11/7/2022
 ** Section: 10/15
 ** This file contains the code for the header file of the Zerg class
 **********************************************************/

#include "Zerg.h"
using namespace std;

// Zerg()
// Deafult constructor for Zerg (abstracted)
Zerg::Zerg() {
}

// Zerg(string name, int health)
// Overloaded constructor for Zerg (abstracted)
Zerg::Zerg(string name, int health) {
}

// Attack()
// Describes attack statements for Zerg and returns damage
int Zerg::Attack() {
  int damage = 1;                                                                              // An int representing the damage done by a normal attack
  cout << GetName() << " deals 1 point of damage! \n";
  return damage;
}
