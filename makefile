CXX = g++
CXXFLAGS = -Wall -g

proj4: proj4.cpp Game.o Area.o Battlecruiser.o Marine.o Ghost.o Hydralisk.o Mutalisk.o Zergling.o Terran.o Zerg.o Entity.o
	$(CXX) $(CXXFLAGS) Game.o Area.o Battlecruiser.o Marine.o Ghost.o Hydralisk.o Mutalisk.o Zergling.o Terran.o Zerg.o Entity.o proj4.cpp -o proj4

Game.o: Game.cpp Game.h Area.o Battlecruiser.o Marine.o Ghost.o Hydralisk.o Mutalisk.o Zergling.o Terran.o Zerg.o Entity.o
	$(CXX) $(CXXFLAGS) -c Game.cpp

Area.o: Area.cpp Area.h
	$(CXX) $(CXXFLAGS) -c Area.cpp

Battlecruiser.o: Battlecruiser.cpp Battlecruiser.h Terran.o Entity.o
	$(CXX) $(CXXFLAGS) -c Battlecruiser.cpp

Marine.o: Marine.cpp Marine.h Terran.o Entity.o
	$(CXX) $(CXXFLAGS) -c Marine.cpp

Ghost.o: Ghost.cpp Ghost.h Terran.o Entity.o
	$(CXX) $(CXXFLAGS) -c Ghost.cpp

Hydralisk.o: Hydralisk.cpp Hydralisk.h Zerg.o Entity.o
	$(CXX) $(CXXFLAGS) -c Hydralisk.cpp

Mutalisk.o: Mutalisk.cpp Mutalisk.h Zerg.o Entity.o
	$(CXX) $(CXXFLAGS) -c Mutalisk.cpp

Zergling.o: Zergling.cpp Zergling.h Zerg.o Entity.o
	$(CXX) $(CXXFLAGS) -c Zergling.cpp

Terran.o: Terran.cpp Terran.h Entity.o
	$(CXX) $(CXXFLAGS) -c Terran.cpp

Zerg.o: Zerg.cpp Zerg.h Entity.o
	$(CXX) $(CXXFLAGS) -c Zerg.cpp

Entity.o: Entity.cpp Entity.h
	$(CXX) $(CXXFLAGS) -c Entity.cpp

run:
	./proj4

run1:
	./proj4 proj4_map1.txt

vall:
	valgrind ./proj4 proj4_map1.txt

clean:
	rm *~
	rm *.o
