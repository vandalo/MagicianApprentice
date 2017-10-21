#include <iostream>
#include "utils.h"
#include "world.h"
#include "Defines.h"
#include "Entity.h"
#include "Room.h"
#include "Player.h"
#include "Exit.h"
#include "Item.h"

World::World()
{}

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
		else if (Same(args[0], "east") || Same(args[0], "west") || Same(args[0], "north") || Same(args[0], "south")) 
		{
			args.push_back(args[0]);
			args[0] = "go";
			player->Go(args);
		}
		else if (Same(args[0], "inventory"))
		{
			player->Inventory(args);
		}
		else if (Same(args[0], "take"))
		{
			cout << "You must say what you want to take.\n";
		}
		else ret = false;
		break;
	case 2:
		if (Same(args[0], "go"))
		{
			player->Go(args);
		}
		else if (Same(args[0], "look"))
		{
			player->Look(args);
		}
		else if (Same(args[0], "take"))
		{
			player->Take(args);
		}
		else if (Same(args[0], "open"))
		{
			{
				player->Open(args);
			}
		}
		else ret = false;
		break;
	default:
		ret = false;
	}
	return ret;
}

string World::Introduction()
{
	cout << "Welcome dear... Oh, wait... Can you remember your name\?\n";
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

bool World::Init() {
	clock_t timer = clock();

	//Init Rooms
	Room *forest = new Room("The forest", "You are in the forest.");
	Room *bridge = new Room("The bridge", "You are at the bridge which connect the forest with the castle. The castle is near at the east.");
	Room *door = new Room("The door", "You are in the entrance of the castle the huge door is at the east.");
	Room *hall = new Room("The hall", "You are at the hall of the castle.");
	Room *diningroom = new Room("Dining room", "You are at the dining room. The room is very big, at the middle\nyou can see the table, at the east part there is a fireplace with beautiful flames.");
	Room *kitchen = new Room("Kitchen", "This is the kitchen of the castle. It is plenty of cooking items.");
	Room *firstfloor = new Room("First floor", "You see a huge room.");
	Room *library = new Room("First floor", "You are at the castle’s library. The ceiling is very high.\nYou can see an enormous number of books. There is an stair to arrive to the books at the top of the shelfs.");


	entities.push_back(forest);
	entities.push_back(bridge);
	entities.push_back(door);
	entities.push_back(hall);
	entities.push_back(diningroom);
	entities.push_back(kitchen);
	entities.push_back(firstfloor);
	entities.push_back(library);

	

	//Player creation
	string name = Introduction().c_str();
	player = new Player(name.c_str(), "You are a magician apprentice", forest);

	//Items from player since start
	Item *document = new Item("Document", "Mission:\nYou blabla", player, nullptr, false);
	Item *spellbook = new Item("Spellbook", "This is your spellbook, it contains all the spells you know.", player, nullptr, false);
	Item *sbPage1 = new Item("Bookpage1", "Ignite: This spell throws a flame to the enemy.\nIt costs 20 mana points and hurt 10 damage.\nIt have 10 seconds of cooldown", spellbook, spellbook, false);
	Item *doorSign = new Item("Sign", "Only the helthy people can enter the castle!", door, nullptr, true);
	Item *sbPage2 = new Item("Bookpage2", "Exura: This spell restore you hit points.\nIt costs 20 mana points and you will get 30 hit points.\nIt have 10 seconds of cooldown", door, spellbook, false);
	
	entities.push_back(document);
	entities.push_back(spellbook);
	entities.push_back(sbPage1);
	entities.push_back(doorSign);


	//Exits
	Exit *forestToBridge = new Exit("east", "This is a sandy road which arrives until the bridge", "bridge", forest, bridge, false, nullptr);
	Exit *bridgeToForest = new Exit("west", "This is a sandy road which arrives until the forest", "forest", bridge, forest, false, nullptr);
	Exit *bridgeToDoor = new Exit("east", "This bridge brings you to the door", "door", bridge, door, false, nullptr);
	Exit *doorToBridge = new Exit("west", "This path brings you to the bridge", "bridge", door, bridge, false, nullptr);
	Exit *doorToHall = new Exit("east", "This is the main door from the castle", "door", door, hall, true, player);
	Exit *HallToDoor = new Exit("west", "This is the main door from the castle", "door", hall, door, false, nullptr);
	Exit *HallToKitchen = new Exit("south", "You can see the kitchen right there", "kitchen", hall, kitchen, false, nullptr);
	Exit *KitchenToHall = new Exit("north", "You can see the big hall", "hall", kitchen, hall, false, nullptr);
	Exit *HallToDiningroom = new Exit("east", "You can see the dining room throw the door", "dining room", hall, diningroom, false, nullptr);
	Exit *DiningroomToHall = new Exit("west", "You can see the big hall", "hall", diningroom, hall, false, nullptr);
	Exit *HallToFirstfloor = new Exit("up", "You can see an extremly beautifull stairs which arrive to the first floor", "stairs", hall, firstfloor, false, nullptr);
	Exit *FirstfloorToHall = new Exit("down", "You can see an extremly beautifull stairs which arrive to the hall", "stairs", firstfloor, hall, false, nullptr);


	entities.push_back(forestToBridge);
	entities.push_back(bridgeToForest);
	entities.push_back(bridgeToDoor);
	entities.push_back(doorToBridge);
	entities.push_back(doorToHall);

	entities.push_back(HallToKitchen);
	entities.push_back(KitchenToHall);
	entities.push_back(HallToDiningroom);
	entities.push_back(DiningroomToHall);
	entities.push_back(HallToFirstfloor);
	entities.push_back(FirstfloorToHall);

	return true;
}
