#ifndef _MARINE_H_
#define _MARINE_H_

#include "Terran.h"

//Marines are the basic attack units for the Terrans, and have the distinction of
// being the only initial unit with a ranged attack against both aerial and ground targets. 

class Marine: public Terran {
 public:
  // Name: Marine() - Default Constructor
  // Description: Creates a new marine
  // Preconditions: None
  // Postconditions: Can create a marine
  Marine();
  // Name: Marine(string name, int hp)
  // Description: Creates a new Marine
  // Preconditions: None
  // Postconditions: Can create a Marine
  Marine(string, int);
  // Name: ~Marine - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Marine();
  // Name: SpecialAttack
  // Description: Defines the Marine's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
