#ifndef _ZERGLING_H_
#define _ZERGLING_H_

#include "Zerg.h"

// Zerglings are cheap melee units and overwhelming to enemies.
// They're so good for flooding players they've given their name to a
// general battlefield tactic: the Zergling rush.
class Zergling: public Zerg {
 public:
  // Name: Zergling() - Default Constructor
  // Description: Creates a new Zergling type of zerg
  // Preconditions: None
  // Postconditions: Can create a Zergling
  Zergling();
  // Name: Zergling(string name, int hp)
  // Description: Creates a new Zergling
  // Preconditions: None
  // Postconditions: Can create a Zergling
  Zergling(string, int);
  // Name: SpecialAttack
  // Description: Defines the Zergling's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
