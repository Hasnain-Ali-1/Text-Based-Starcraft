#ifndef _HYDRALISK_H_
#define _HYRDALISK_H_

#include "Zerg.h"

// Hydralisks spit hyper-velocity, super-dense darts at enemies, ripping them to pieces.
// They are general-purpose units and their special attack spits acid (for our project)

class Hydralisk: public Zerg {
 public:
  // Name: Hydralisk() - Default Constructor
  // Description: Creates a new Hydralisk
  // Preconditions: None
  // Postconditions: Can create a Hydralisk
  Hydralisk();
  // Name: Hydralisk(string name, int hp)
  // Description: Creates a new Hydralisk
  // Preconditions: None
  // Postconditions: Can create a Hydralisk
  Hydralisk(string, int);
  // Name: SpecialAttack
  // Description: Defines the Hydralisk's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
