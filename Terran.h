#ifndef _TERRAN_H_
#define _TERRAN_H_

#include "Entity.h"

class Terran: public Entity {
 public:
  // Name: Terran() - Default Constructor
  // Description: Creates a new terran
  // Preconditions: None
  // Postconditions: Can create a terran
  Terran();
  // Name: Terran(string name, int hp) - Overloaded constructor
  // Description: Creates a new terran
  // Preconditions: None
  // Postconditions: Can be used to populate terran or child classes
  Terran(string, int);
  // Name: ~Terran - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Terran();
  // Name: Attack()
  // Description: Describes attack statements for terran
  // Preconditions: None
  // Postconditions: Returns damage
  int Attack();
  // Name: SpecialAttack()
  // Description: Tells player that terran does not have special attack
  // may be used for child class special attacks
  // Preconditions: None
  // Postconditions: May be used to call child class SpecialAttack
  virtual int SpecialAttack();
};
#endif
