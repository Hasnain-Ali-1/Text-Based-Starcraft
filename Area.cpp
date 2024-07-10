/***********************************************************
 ** File:    Area.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hasnain Ali
 ** Date     11/9/2022
 ** Section: 10/15
 ** This file contains the code for the header file of the Area class
 **********************************************************/

#include "Area.h"
using namespace std;

// Area
// Overloaded Constructor
Area::Area(int areaID, string areaName, string areaDesc, int north, int east, int south, int west) {
  m_ID = areaID;
  m_name = areaName;
  m_desc = areaDesc;
  m_direction[0] = north;
  m_direction[1] = east;
  m_direction[2] = south;
  m_direction[3] = west;
}

// GetName
// Returns area name as string
string Area::GetName() {
  return m_name;
}

// GetID
// Returns area id as int
int Area::GetID() {
  return m_ID;
}

// GetDesc
// Returns area desc as string
string Area::GetDesc() {
  return m_desc;
}

// CheckDirection
// Returns id of area in the direction the user chose
int Area::CheckDirection(char myDirection) {
  int areaID;                                                                                      // An int used to represent the ID of the area the user wants to move to
  // If the user entered 'N' or 'n', areaId becomes the first number in m_direction[]
  if ((myDirection == 'N') || (myDirection == 'n')) {
    areaID = m_direction[0];
  }
  // If the user entered 'E' or 'e', areaId becomes the second number in m_direction[]
  if ((myDirection == 'E') || (myDirection == 'e')) {
    areaID = m_direction[1];
  }
  // If the user entered 'S' or 's', areaId becomes the third number in m_direction[]
  if ((myDirection == 'S') || (myDirection == 's')) {
    areaID = m_direction[2];
  }
  // If the user entered 'W' or 'w', areaId becomes the fourth number in m_direction[]
  if ((myDirection == 'W') || (myDirection == 'w')) {
    areaID = m_direction[3];
  }
  return areaID;
}

// PrintArea
// Outputs the area name, area desc, then possible exits
void Area::PrintArea() {
  string possibleExits;                                                                           // A string used to represent the possible exits of an area
  cout << GetName() << "\n";
  cout << GetDesc() << "\n";
  // Iterates thorugh m_direction[]
  for (int i = 0; i < 4; i++) {
    if (m_direction[i] != -1) {
      // Add the first number in m_direction as a possible exit
      if (i == 0) {
	possibleExits.push_back('N');
      }
      // Add the second number in m_direction as a possible exit
      if (i == 1) {
        possibleExits.push_back('E');
      }
      // Add the third number in m_direction as a possible exit
      if (i == 2) {
        possibleExits.push_back('S');
      }
      // Add the fourth number in m_direction as a possible exit
      if (i == 3) {
        possibleExits.push_back('W');
      }
    }
  }
  // Prints out the possible exits
  cout << "Possible Exits: ";
  for (unsigned int i = 0; i < possibleExits.size(); i++) {
    cout << possibleExits[i] << " ";
  }
  cout << "\n";
}

