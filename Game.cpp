/***********************************************************
 ** File:    Game.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hasnain Ali
 ** Date     11/9/2022
 ** Section: 10/15
 ** This file contains the code for the header file of the Game class
 **********************************************************/

#include "Game.h"
using namespace std;

// Game()
// Default Constructor for Game
Game::Game() {
}

// Game(string filename)
// Overloaded Constructor for GameDescription: Creates a new Game
Game::Game(string filename) {
  m_curZerg = nullptr;
  m_myTerran = nullptr;
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  m_curArea = START_AREA;
  m_wins = START_WINS;
  m_filename = filename;
}

// ~Game
// Destructor for Game
Game::~Game() {
}

// LoadMap()
// Dynamically creates areas and inserts them into the m_myMap vector
void Game::LoadMap() {
  Area* newArea;                                                                              // Creates a pointer to a Area
  string line;                                                                                // A string used to represent the lines in the text file
  ifstream mapFile;                                                                           // An ifstream used to open the text file
  int areaID = -2;                                                                            // An int representing the Area ID
  string areaName = "placeholder";                                                            // A string representing the Area name
  string areaDesc = "placeholder";                                                            // A string representing the Area description
  int northID = -2;                                                                           // An int representing the Area ID to the North
  int eastID = -2;                                                                            // An int representing the Area ID to the East
  int southID = -2;                                                                           // An int representing the Area ID to the South
  int westID = -2;                                                                            // An int representing the Area ID to the West
  mapFile.open(m_filename);
  if (mapFile.is_open()) {
    while (getline (mapFile, line, DELIMITER)) {
      if (line != "\n") {
	// If areaID has the placeholder value
	if (areaID == -2) {
	  areaID = stoi(line);
	}
	// If areaName has the placeholder value
	else if (areaName == "placeholder") {
	  areaName = line;
	}
	// If areaDesc has the placeholder value
	else if (areaDesc == "placeholder") {
	  areaDesc = line;
	}
	// If northID has the placeholder value
	else if (northID == -2) {
	  northID = stoi(line);
	}
	// If eastID has the placeholder value
	else if (eastID == -2) {
	  eastID = stoi(line);
	}
	// If southID has the placeholder value
	else if (southID == -2) {
	  southID = stoi(line);
	}
	// If everything but westID doesn't have the plaecholder value
	else {
	  westID = stoi(line);
	}
	// If areaName, areaDesc, northID, eastID, southID, and westID don't have the default
	// value
	if ((areaID != -2) && (areaName != "placeholder") && (areaDesc != "placeholder")
	    && (northID != -2) && (eastID != -2) && (southID != -2) && (westID != -2)) {
	  // Connects the pointer to a new Area object
	  newArea = new Area(areaID, areaName, areaDesc, northID, eastID, southID, westID);
	  // Adds the object to the vector
	  m_myMap.push_back(newArea);
	  // Resets the areaName, areaDesc, northID, eastID, southID, and westID to it's
	  // default values
	  areaID = -2;
	  areaName = "placeholder";                                                         
	  areaDesc = "placeholder";                                                        
	  northID = -2;                                                                       
	  eastID = -2;                                                                           
	  southID = -2;                                                                          
	  westID = -2;
	}
      }
    }
    mapFile.close();
  }
  else {
    cout << "The file was unable to be opened \n";
  }
}

// TerranCreation()
// Allows user to choose a class. Populates m_myTerran
void Game::TerranCreation() {
  string userName;                                                                            // A string that represents the name the user has chosen for their name
  bool validChoice = false;                                                                   // A bool used to determine if the user entered a valid number
  int userChoice;                                                                             // An int used to determine the user's class
  cout << "Welcome to UMBC Starcraft \n";
  cout << "Terran Name: ";
  getline(cin, userName);
  while (validChoice == false) {
    cout << "Select a class \n";
    cout << "1. Marine \n";
    cout << "2. Ghost \n";
    cout << "3. Battlecruiser \n";
    cout << "4. No Class \n";
    cin >> userChoice;
    // If the user entered 1, creates a Marine
    if (userChoice == 1) {
      validChoice = true;
      m_myTerran = new Marine(userName, MARINE_HEALTH);
    }
    // If the user entered 2, creates a Ghost
    else if (userChoice == 2) {
      validChoice = true;
      m_myTerran = new Ghost(userName, GHOST_HEALTH);
    }
    // If the user entered 3, creates a Battlecruiser
    else if (userChoice == 3) {
      validChoice = true;
      m_myTerran = new Battlecruiser(userName, BATTLECRUISER_HEALTH);
    }
    // If the user entered 4, creates a Terran
    else if (userChoice == 4) {
      validChoice = true;
      m_myTerran = new Terran(userName, TERRAN_HEALTH);
    }
    else {
      validChoice = false;
    }
  }
}

// StartGame()
// Welcomes the player to the game
void Game::StartGame() {
  LoadMap();
  TerranCreation();
  cout << "\n";
  // Prints out the current area
  for (unsigned int i = 0; i < m_myMap.size(); i++) {
    if (i == 0) {
      m_myMap.at(i)->PrintArea();
    }
  }
  Action();
}

// Name: Action()
// The Menu for game. Calls RandomZerg for current location then displays menu.
void Game::Action() {
  m_curZerg = RandomZerg();
  int userChoice = 1;                                                                         // An int representing the user's choice
  int mapSize = m_myMap.size();                                                               // An int representing the map size
  while (userChoice != 6) {
    // If the user's character is dead, ends the game
    if (m_myTerran->GetHealth() <= 0) {
      userChoice = 6;
    }
    else {
      cout << "What would you like to do? \n";
      cout << "1. Look \n";
      cout << "2. Move \n";
      cout << "3. Attack Zerg \n";
      cout << "4. Rest \n";
      cout << "5. Check Stats \n";
      cout << "6. Quit \n";
      cin >> userChoice;
      // If the user enetered 1, displays the current area
      if (userChoice == 1) {
	for (int i = 0; i < mapSize; i++) {
	  if (i == m_curArea) {
	    m_myMap.at(i)->PrintArea();
	  }
	}
      }
    }
    // If the user enters 2, moves the character if it's a valid area
    if (userChoice == 2) {
      Move();
    }
    // If the user enters 3, fights the Zerg if there is one
    if (userChoice == 3) {
      Attack();
    }
    // if the user enters 4, uses a rest action if they have one
    if (userChoice == 4) {
      Rest();
    }
    // If the user enters 5, displays their current stats
    if (userChoice == 5) {
      Stats();
    }
  }
  // If the user enters 6, deletes all dynamically allocated stuff and
  // quits the program
  if (userChoice == 6) {
    for (unsigned int i = 0; i < m_myMap.size(); i++) {
      delete m_myMap.at(i);
    }
    delete m_myTerran;
    m_myTerran = nullptr;
    if (m_curZerg != nullptr) {
      delete m_curZerg;
      m_curZerg = nullptr;
    }
    cout << "Thanks for playing UMBC Starcraft \n";
  }
}

// RandomZerg()
// Used to randomly create a dynamically allocated zerg
Entity* Game::RandomZerg() {
  int randNum;                                                                                 // An int representing a random number used to detemrine the zerg type
  string zergName;                                                                             // A string representing Zerg name
  randNum = (rand() % 4) + 1;
  // No Zerg is created
  if (randNum == 1) {
    m_curZerg = nullptr;
    cout << "It is peaceful here. \n";
  }
  // A Zergling is created
  if (randNum == 2) {
    zergName = "Zergling";
    m_curZerg = new Zergling(zergName, ZERGLING_HEALTH);
    cout << "A small terrifying zergling waits here. \n";
  }
  // A Mutalisk is created
  if (randNum == 3) {
    zergName = "Mutalisk";
    m_curZerg = new Mutalisk(zergName, MUTALISK_HEALTH);
    cout << "A large flying mutalisk hovers here. \n";
  }
  // A Hydralisk is created
  if (randNum == 4) {
    zergName = "Hydralisk";
    m_curZerg = new Hydralisk(zergName, HYDRALISK_HEALTH);
    cout << "A medium sized hydralisk slithers here waiting to cover you with acid. \n";
  }
  return m_curZerg;
}

// Rest
// Allows player to rest depending on their scenario
void Game::Rest() {
  int currHealth;                                                                             // An int used to represent health after resting
  // If there's a zerg in the area
  if (m_curZerg != nullptr) {
    cout << "You cannot rest with a Zerg in the area. \n";
  }
  // If the user doesn't have any rests
  else if (m_numRests == 0) {
    cout << "You don't have any rests. \n";
  }
  // The user uses a rest action
  else {
    m_numRests = m_numRests - 1;
    m_numSpecial = NUM_SPECIAL;
    currHealth = m_myTerran->GetHealth() + REST_HEAL;
    m_myTerran->SetHealth(currHealth);
    cout << "You rest and wake up refreshed. \n";
  }
}

// Move
// Moves player from one area to another (updates m_curArea)
void Game::Move() {
  char nextArea;                                                                               // A char used to represent the next area the user wants to move to
  int nextAreaID;                                                                              // An int used to represent the area ID of the area the user wants to move to
  bool validDirection = false;                                                                 // A boolean used to determine if a user entered a valid direction
  int mapSize = m_myMap.size();                                                                // An int representing the map size
  while (validDirection != true) {
    cout << "Which direction? (N E S W) \n";
    cin >> nextArea;
    // If the user didn't input a valid char
    if ((nextArea != 'N') && (nextArea != 'n') && (nextArea != 'E') && (nextArea != 'e') &&
	(nextArea != 'S') && (nextArea != 's') && (nextArea != 'W') && (nextArea != 'w')) {
      validDirection = false;
    }
    else {
      // Iterates thorugh m_myMap
      for (int i = 0; i < mapSize; i++) {
	if (i == m_curArea) {
	  // Checks the ID of the next area and reprompts if the ID is -1
	  nextAreaID = m_myMap.at(i)->CheckDirection(nextArea);
	  if (nextAreaID == -1) {
	    validDirection = false;
	  }
	  // If a valid direction was entered, takes them out of the loop
	  else {
	    validDirection = true;
	  }
	}
      }
    }
  }
  // "Moves" the user to the new area
  m_curArea = nextAreaID;
  // Deletes the Zerg at the previous location if there was one
  if (m_curZerg != nullptr) {
    delete m_curZerg;
    m_curZerg = nullptr;
  }
  cout << "\n";
  // Displays the new area
  for (int i = 0; i < mapSize; i++) {
    if (i == m_curArea) {
      m_myMap.at(i)->PrintArea();
    }
  }
  // Creates a new zerg
  m_curZerg = RandomZerg();
}

// Attack
// Indicates who wins and updates health(hp) as battle continues.
void Game::Attack() {
  int userChoice = 0;                                                                          // An int representing the user's attack choice
  int userAttackDamage;                                                                        // An int representing the user's attack damage
  int zergAttackDamage;                                                                        // An int representing the Zerg's attack damage
  int zergSpecialChance;                                                                       // An int that determines if the Zerg uses a speical attack
  int userHealth;                                                                              // An int representing the User's health
  int zergHealth;                                                                              // An int representing the Zerg's health
  bool zergAlive = true;                                                                           
  bool userAlive = true;
  if (m_curZerg == nullptr) {
    cout << "There are no Zergs in the area \n";
  }
  else {
    // While both the user and zerg are alive
    while ((zergAlive == true) && (userAlive == true)) {
      while ((userChoice != 1) && (userChoice != 2)) {
	cout << "1. Normal Attack \n";
	cout << "2. Special Attack \n";
	cin >> userChoice;
	// User uses the normal attack for the class they chose
	if (userChoice == 1) {
	  userAttackDamage = m_myTerran->Attack();
	}
	else if (userChoice == 2) {
	  // If the user doesn't have any specials
	  if (m_numSpecial == 0) {
	    cout << "You don't have any special attacks! \n";
	    userAttackDamage = 0;
	  }
	  // User uses a special attack
	  else {
	    userAttackDamage = m_myTerran->SpecialAttack();
	    m_numSpecial = m_numSpecial - 1;
	  }
	}
      }
      zergSpecialChance = (rand() % 4) + 1;
      // If zergSpecialChance is 1, the zerg does a special attack
      if (zergSpecialChance == 1) {
	// If the Zerg is a Zergling
	if (m_curZerg->GetName() == "Zergling") {
	  zergAttackDamage = m_curZerg->SpecialAttack();
	  cout << "Zergling deals " << zergAttackDamage << " point of damage! \n";
	}
	// If the Zerg is a Mutalisk
	if (m_curZerg->GetName() == "Mutalisk") {
	  zergAttackDamage =  m_curZerg->SpecialAttack();
	  cout << "Mutalisk deals " << zergAttackDamage << " points of damage! \n";
	}
	// If the Zerg is a Hydralisk
	if (m_curZerg->GetName() == "Hydralisk") {
	  zergAttackDamage =  m_curZerg->SpecialAttack();;
	  cout << "Hydralisk deals " << zergAttackDamage << " points of damage! \n";
	}
      }
      // The Zerg does a normal attack
      else {
	zergAttackDamage = m_curZerg->Attack(); 
      }
      // Updates the health of the user and zerg after one round
      userHealth = m_myTerran->GetHealth() - zergAttackDamage;
      zergHealth = m_curZerg->GetHealth() - userAttackDamage;
      m_myTerran->SetHealth(userHealth);
      m_curZerg->SetHealth(zergHealth);
      // If the user's character isn't alive
      if (m_myTerran->GetHealth() <= 0) {
	userAlive = false;
      }
      // If the Zerg isn't alive
      if (m_curZerg->GetHealth() <= 0) {
	zergAlive = false;
      }
      // If both are alive, uses the overloaded << operator to display health
      if ((userAlive == true) && (zergAlive == true)) {
	cout << *m_myTerran;
	cout << *m_curZerg;
      }
      // Takes the user back to the beginning of the while loop to start the next round
      // if both are alive
      userChoice = 0;
    }
    // If one or both are dead
    ProcessBattle(zergAlive, userAlive);
  }
}
  
// Stats()
// Displays the information about the player (name, hp, rests, specials, and wins)
void Game::Stats() {
  cout << "Name: " << m_myTerran->GetName() << "\n";
  cout << "HP: " << m_myTerran->GetHealth() << "\n";
  cout << "Rests: " << m_numRests << "\n";
  cout << "Specials: " << m_numSpecial << "\n";
  cout << "Wins: " << m_wins << "\n";
}

// ProcessBattle
// Displays who won (Zerg, Terran, mutual destruction), adds wins if necessary,
void Game::ProcessBattle(bool zergAlive, bool alive) {
  int restChance;                                                                             // An int that represents the chance a user gets an additional rest action
  // If the user is the only one alive
  if ((zergAlive == false) && (alive == true)) {
    m_wins = m_wins + 1;
    cout << "You have defeated the " << m_curZerg->GetName() << ". \n";
    restChance = (rand() % 10) + 1;
    // If restChance equals 1 the user gets an additional rest action
    if (restChance == 1) {
      m_numRests = m_numRests + 1;
      cout << "You have earned another rest action! \n";
    }
    // Deallocates the dyanamically allocated Zerg
    delete m_curZerg;
    m_curZerg = nullptr;
  }
  // If the Zerg's the only one alive
  if ((zergAlive == true) && (alive == false)) {
    cout << "You have been defeated by the " << m_curZerg->GetName() << ". \n";
    cout << "Game Over \n";
  }
  // If both are dead
  if ((zergAlive == false) && (alive == false)) {
    cout << "You and the " << m_curZerg->GetName() << " defeated each other. \n";
    cout << "Game Over \n";
  }
}
