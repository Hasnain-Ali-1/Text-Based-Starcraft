/***********************************************************
 ** File:    Entity.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hasnain Ali
 ** Date     11/7/2022
 ** Section: 10/15
 ** This file contains the code for the header file of the Entity class
 **********************************************************/

#include "Entity.h"
using namespace std;

// Entity
// A constructor for the Entity class (abstract)
Entity::Entity() {
}

// Entity
// An overloaded constructor for the Entity class (abstract)
Entity::Entity(string name, int health) {
}

// ~Entity
// A virtual destructor for the Entity class
Entity::~Entity() {
}

// GetName
// Returns the name of an entity
string Entity::GetName() {
  return m_name;
}

// GetHealth
// Returns the health of an entity
int Entity::GetHealth() {
  return m_health;
}

// SetName
// Sets the name of the entity
void Entity::SetName(string name) {
  m_name = name;
}

// SetHealth
// Sets the health of the entity
void Entity::SetHealth(int health) {
  m_health = health;
}

ostream& operator<<(ostream& output, Entity& currentEntity) {
  output << currentEntity.m_name << "'s health: " << currentEntity.GetHealth() << "\n";
  return output;
}
