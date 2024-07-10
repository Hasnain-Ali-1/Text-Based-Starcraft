#ifndef _BATTLECRUISER_H_
#define _BATTLECRUISER_H_

#include "Terran.h"

// The Battlecruiser is the Terrans' most powerful air unit.
// They are sometimes used to harass the enemy with their long range Yamato Cannon.
class Battlecruiser: public Terran {
 public:
  // Name: Battlecruiser() - Default Constructor
  // Description: Creates a new Battlecruiser
  // Preconditions: None
  // Postconditions: Can create a Battlecruiser
  Battlecruiser();
  // Name: Battlecruiser(string name, int hp)
  // Description: Creates a new Battlecruiser
  // Preconditions: None
  // Postconditions: Can create a Battlecruiser
  Battlecruiser(string, int);
  // Name: ~Battlecruiser - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Battlecruiser();
  // Name: SpecialAttack
  // Description: Defines the Battlecruiser's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
