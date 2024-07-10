#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  if( argc != 2) {
    cout << "This requires a map file to be loaded." << endl;
    cout << "Usage: ./proj4 proj4_map1.txt" << endl;
  }

  cout << "Loading file: " << argv[1] << endl << endl;

  string mapName = argv[1];
  srand (time(NULL));
  Game g(mapName);
  g.StartGame();
  return 0;
}
