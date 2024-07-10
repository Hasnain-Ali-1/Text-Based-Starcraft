#ifndef _GAME_H_
#define _GAME_H_

//Includes of required classes
#include "Area.h"
#include "Entity.h"
#include "Zerg.h"
#include "Terran.h"
#include "Hydralisk.h"
#include "Mutalisk.h"
#include "Zergling.h"
#include "Battlecruiser.h"
#include "Ghost.h"
#include "Marine.h"

//Includes of required libraries
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//************************Constants*********************
const int MARINE_HEALTH = 8; //starting health for marine
const int GHOST_HEALTH = 10;  //starting health for ghost
const int BATTLECRUISER_HEALTH = 12; //starting health for battlecruiser
const int TERRAN_HEALTH = 10; //starting health for terran
const int ZERGLING_HEALTH = 3; //starting health for zergling
const int MUTALISK_HEALTH = 5; //starting health for mutalisk
const int HYDRALISK_HEALTH = 7; //starting health for hydralisk
const int NUM_RESTS = 1; //starting rests for player
const int NUM_SPECIAL = 3; //starting special attacks for player
const int REST_HEAL = 10; //how much health is restored from rest
const int START_AREA = 0; //starting area number
const int START_WINS = 0; //starting number of wins
const string FILE_NAME = "proj4_map1.txt"; //default for default game constructor
const char DELIMITER = '|'; //delimiter for input file (map file)
//******************************************************

class Game {
public:
  // Name: Game() - Default Constructor
  // Description: Creates a new Game
  // Preconditions: None
  // Postconditions: Initializes all game variables to defaults (constants)
  // including rests, specials, curArea, filename, curZerg (nullptr), and starting wins
  Game();
  // Name: Game(string filename) - Overloaded Constructor
  // Description: Creates a new Game
  // Preconditions: None
  // Postconditions: Initializes all game variables to defaults (constants)
  //                 including rests, specials, curArea, filename (from passed variable),
  //                 curZerg (nullptr), and starting wins
  Game(string);
  // Name: ~Game
  // Description: Destructor
  // Preconditions: None
  // Postconditions: Deallocates anything dynamically allocated in Game (terran, zergs, and map)
  ~Game();
  // Name: LoadMap()
  // Description: Dynamically creates areas and inserts them into the m_myMap vector
  // Note: the size of the map is not known - you should not use constants for this.
  //       Also, you can use stoi to convert strings to integers
  // Precondition: m_filename is populated
  // Postcondition: Map is populated with area objects.
  void LoadMap();
  // Name: TerranCreation()
  // Description: Allows user to choose a new terran (or child) to play with. May
  //              be either Terran, Marine, Ghost, or Battlecruiser.
  // Preconditions: None
  // Postconditions: m_myTerran is populated
  void TerranCreation();
  // Name: StartGame()
  // Description: Welcomes the player to the game. Calls LoadMap, TerranCreation,
  //              prints the current area then calls action
  // Preconditions: Input file must exist
  // Postconditions: Map is loaded, User has chosen a terran to play with,
  //                 printed the starting area, and calls action
  void StartGame();
  // Name: Action()
  // Description: Menu for game. Calls RandomZerg for current location then displays menu.
  //              Player can look, move, attack, rest, stats, or quit
  //              If player moves, clears out the m_curZerg and sets m_curZerg = RandomZerg
  //              If player looks, will NOT display zerg again (as this is a function of moving)
  //              Can only attack if there is actually a zerg in this area
  // Preconditions: Everything in start has been completed
  // Postconditions: Game continues until quit or player dies
  void Action();
  // Name: RandomZerg()
  // Description: Used to randomly create a dynamically allocated zerg
  //              (25% chance of nothing, 25% chance of Zergling, Mutalisk, or Hydralisk.)
  //              When chosen, displays the description
  //              of the zerg or displays "It is peaceful here."
  // Preconditions: Has an entity pointer to hold zerg child or nullptr
  // Postconditions: Returns object of type Zergling, Mutalisk, Hydralisk, or nullptr
  Entity* RandomZerg();
  // Name: Rest
  // Description: If no zerg in current area, allows player to rest
  // Preconditions: Must be valid area with no zerg (area must exist) and have rests
  // Postconditions: Reduces available rests by one and increases hp by 10
  //                 using REST_HEAL (regardless of starting value)
  void Rest();
  // Name: Move
  // Description: Asks a player which direction they would like to move.
  //              Moves player from one area to another (updates m_curArea)
  // Preconditions: Must be valid move (area must exist)
  // Postconditions: Displays area information
  void Move();
  // Name: Attack
  // Description: Allows player to attack an enemy entity.
  // Preconditions: Must have enemy Zerg in area
  // Postconditions: Indicates who wins and updates health(hp) as battle continues.
  //                 Both Terran and Zerg attack every round until one or more has <= 0 health
  //                 May need to deallocate enemy Zerg to prevent memory leaks.
  //                 When either Zerg or Terran <= 0 health, calls ProcessBattle
  void Attack();
  // Name: Stats()
  // Description: Displays the information about the player (name, hp, rests, specials, and wins)
  // Preconditions: None
  // Postconditions: None
  void Stats();
  // Name: ProcessBattle
  // Description: Called when either the zerg or terran have no health left
  //       Displays who won (Zerg, Terran, mutual destruction), adds wins if necessary,
  //       and has a 10% chance of earning another rest action.
  // Preconditions: Zerg or terran are <= 0 health
  // Postconditions: 
  void ProcessBattle(bool zergAlive, bool alive);
private:
  vector<Area*> m_myMap; // Vector for holding all areas in game
  Entity* m_myTerran; // Entity pointer for Terran (Marine, Ghost, or Battlecruiser) - Player
  int m_curArea; // Current area that player (Terran) is in
  Entity* m_curZerg; // Current zerg loaded for current area
  int m_numRests; // Number of rests for player (Terran)
  int m_numSpecial; // Number of special attacks for player (Terran) (refreshed after rests)
  string m_filename; //Name of the input file for the map (holds area objects)
  int m_wins; //Number of battles won in this game
};

#endif
