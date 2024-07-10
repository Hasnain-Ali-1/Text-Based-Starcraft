#ifndef _ZERG_H_
#define _ZERG_H_

#include "Entity.h"

//The parent class for all of the scary Zerg
class Zerg: public Entity {
 public:
  // Name: Zerg() - Default Constructor
  // Description: Would be used to create a zerg but abstracted
  // Preconditions: None
  // Postconditions: Used to populate child class data
  Zerg();
  // Name: Zerg(string name, int hp) - Overloaded Constructor
  // Description: Would be used to create a Zerg but abstracted
  // Preconditions: None
  // Postconditions: Used to populate child class data
  Zerg(string, int);
  // Name: Attack()
  // Description: Describes attack statements for Zerg
  // Preconditions: None
  // Postconditions: Returns damage
  int Attack();
  // Name: SpecialAttack()
  // Description: Purely virtual SpecialAttack
  // Preconditions: None
  // Postconditions: May be used to call child class SpecialAttack
  virtual int SpecialAttack()=0;
};
#endif
