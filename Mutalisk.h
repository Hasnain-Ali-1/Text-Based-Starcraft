#ifndef _MUTALISK_H_
#define _MUTALISK_H_

#include "Zerg.h"

//A flying zerg that spashes enemies with damage
class Mutalisk: public Zerg {
 public:
  // Name: Mutalisk() - Default Constructor
  // Description: Creates a new Mutalisk
  // Preconditions: None
  // Postconditions: Can create a Mutalisk
  Mutalisk();
  // Name:  Mutalisk(string name, int hp)
  // Description: Creates a new Mutalisk
  // Preconditions: None
  // Postconditions: Can create a Mutalisk
  Mutalisk(string, int);
  // Name: SpecialAttack
  // Description: Defines the Mutalisk's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
