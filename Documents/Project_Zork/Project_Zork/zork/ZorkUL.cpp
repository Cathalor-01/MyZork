#include <iostream>

using namespace std;
#include "ZorkUL.h"

int main(int argc, char argv[]) {
	ZorkUL temp;
	temp.play();
	return 0;
}

ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
    aPtr = new Room("a");

       bPtr = new Room("b");
           bPtr->addItem(new Item("piece two", 3, 33));
       cPtr = new Room("c");

       dPtr = new Room("d");

       ePtr = new Room("e");
           ePtr->addItem(new Item("piece one", 1, 11));
       fPtr = new Room("f");
       gPtr = new Room("g");

       hPtr = new Room("h");
       hPtr->addItem(new Item("piece three", 4, 44));
       iPtr = new Room("i");
       iPtr->addItem(new Item("piece four", 2, 22));
       jPtr = new Room("j");


   //             (N, E, S, W)
       aPtr->setExits(fPtr, bPtr, dPtr, cPtr);
       bPtr->setExits(NULL, NULL, NULL, aPtr);
       cPtr->setExits(NULL, aPtr, NULL, NULL);
       dPtr->setExits(aPtr, ePtr, jPtr, iPtr);
       ePtr->setExits(NULL, NULL, NULL, dPtr);
       fPtr->setExits(NULL, gPtr, aPtr, hPtr);
       gPtr->setExits(NULL, NULL, NULL, fPtr);
       hPtr->setExits(NULL, fPtr, NULL, NULL);
       iPtr->setExits(NULL, dPtr, NULL, NULL);
       jPtr->setExits(dPtr, NULL, NULL, NULL);

        currentRoom = aPtr;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
	cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "        [j]        " << endl;
        }

	else if (commandWord.compare("go") == 0)
		goRoom(command);
    else if (commandWord.compare("teleport") == 0){
        teleport();
    }
    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}


/** COMMANDS **/
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}

string ZorkUL::teleport(){

    string teleport = "\nTeleporting...\n";

    int random = rand()%10;
    Room* rooms[]={aPtr, bPtr, cPtr, dPtr, ePtr, fPtr, gPtr, hPtr, iPtr, jPtr};
    currentRoom = rooms[random];


    teleport+= currentRoom->longDescription()+"\n";
    return teleport;
}

