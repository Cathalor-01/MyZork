#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ZorkUL {
private:
    Room *currentRoom, *aPtr, *bPtr, *cPtr, *dPtr, *ePtr, *fPtr, *gPtr, *hPtr, *iPtr, *jPtr;
	Parser parser;
    vector<Room> rooms;
	void createRooms();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();

public:
	ZorkUL();
	void play();
	string go(string direction);
    string teleport();
};

#endif /*ZORKUL_H_*/
