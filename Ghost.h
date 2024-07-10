#ifndef _GHOST_H_
#define _GHOST_H_

#include "Terran.h"

//Stealth specialist with access to several powerful and different abilities
class Ghost: public Terran {
 public:
  // Name: Ghost() - Default Constructor
  // Description: Creates a new Ghost
  // Preconditions: None
  // Postconditions: Can create a Ghost
  Ghost();
  // Name: Ghost(string name, int hp)
  // Description: Creates a new Ghost
  // Preconditions: None
  // Postconditions: Can create a Ghost
  Ghost(string, int);
  // Name: ~Ghost - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Ghost();
  // Name: SpecialAttack
  // Description: Defines the Ghost's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
