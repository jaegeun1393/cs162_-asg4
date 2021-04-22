/like this
CC = g++
EXE_FILE = go_hunt

all: $(EXE_FILE)

$(EXE_FILE):hunt_wumpus.cpp game.o event.o room.o wumpus.o gold.o pit.o bats.o 
	$(CC) hunt_wumpus.cpp game.o event.o room.o wumpus.o gold.o pit.o bats.o -o $(EXE_FILE)

game.o: game.cpp game.hpp
	$(CC) -c game.cpp

event.o: event.cpp event.hpp
	$(CC) -c event.cpp

room.o: room.cpp room.hpp
	$(CC) -c room.cpp

wumpus.o: wumpus.cpp wumpus.hpp
	$(CC) -c wumpus.cpp

gold.o: gold.cpp gold.hpp
	$(CC) -c gold.cpp

pit.o: pit.cpp pit.hpp
	$(CC) -c pit.cpp

bats.o: bats.cpp bats.hpp
	$(CC) -c bats.cpp

clean: 
	rm -f *.o $(BIN)
