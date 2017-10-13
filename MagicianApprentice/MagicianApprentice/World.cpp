#include <iostream>
#include "utils.h"
#include "world.h"
#include "Defines.h"
#include "Entity.h"
#include "Room.h"
#include "Player.h"
#include "Exit.h"

World::World()
{

}

bool World::Init() {
	clock_t timer = clock();

	//Init Rooms
	Room *forest = new Room("The forest", "You are in the forest.");
	Room *bridge = new Room("The bridge", "You are at the bridge which connect the forest with the castle. The castle is near at the east.\nThe forest stay at the west.");

	//Exits
	Exit *forestToBridge = new Exit("east", "This is a sandy road which arrives until the bridge", "bridge", forest, bridge, false, false);
	Exit *bridgeToForest = new Exit("west", "This is a sandy road which arrives until the forest", "bridge", bridge, forest, false, false);

	entities.push_back(forest);
	entities.push_back(bridge);
	entities.push_back(forestToBridge);
	entities.push_back(bridgeToForest);
	//Player creation
	string name = Introduction().c_str();
	player = new Player(name.c_str(), "You are a magician apprentice", forest);

	return true;
}

World::~World()
{
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		delete *it;

	entities.clear();
}

bool World::ReadComand(vector<string>& args)
{
	bool ret = true;

	if (args.size() > 0 && args[0].length() > 0)
		ret = ParseCommand(args);

	GameLoop();

	return ret;
}

void World::GameLoop()
{
	clock_t now = clock();

	//Clock every second
	if ((now - timer) / 500 > FRAME_RATE)
	{
		for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
			(*it)->Update();

		timer = now;
	}

}

bool World::ParseCommand(vector<string>& args)
{
	bool ret = true;

	switch (args.size()) {
	case 1:
		if (Same(args[0], "look"))
		{
			player->Look(args);
		}
		else if (Same(args[0], "stats"))
		{
			player->Stats(args);
		}
		else if (Same(args[0], "go"))
		{
			cout << "You must say where you want to go.\n";
		}
		else if (Same(args[0], "east") || Same(args[0], "west") || Same(args[0], "north") || Same(args[0], "south")) {
			args.push_back(args[0]);
			args[0] = "go";
			player->Go(args);
		}
		break;
	case 2:
		if (Same(args[0], "go"))
		{
			player->Go(args);
		}
		break;
	default:
		cout << "Sorry, I don't understand this action.\n";
	}
	return ret;
}

string World::Introduction()
{
	cout << "Welcome dear\... Oh, wait\... Can you remember your name\?\n";
	cout << "> ";
	string input_name;
	getline(cin, input_name);

	cout << "\n";
	cout << "Welcome dear " << input_name << ", this is your last exam to become a magician! This is not like the other\n";
	cout << "test and practices you have already done during this years at the school, this time you will\n";
	cout << "have to face a real case.\n\n";
	cout << "Every day the magic council receives many letter from people asking for help with many\n";
	cout << "things and the organisation of this exam chose one for each studden who have to do the\n";
	cout << "exam, so remember, we don’t know what you will have to face.\n\n";
	cout << "You have the explanation of your mission with you in the document apart, from the spellbook\n";
	cout << "you have used during all this years at school. Good luck!\n\n";

	return input_name;
}