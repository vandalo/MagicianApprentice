#include <iostream>
#include "utils.h"
#include "world.h"
#include "Defines.h"
#include "Entity.h"
#include "Room.h"
#include "Player.h"
#include "Exit.h"
#include "Item.h"
#include "Spider.h"
#include "Spell.h"
#include "Ignite.h"
#include "Exura.h"
#include "Potion.h"
#include "Stair.h"
#include "Bottle.h"
#include "Fireplace.h"
#include "Tortolize.h"

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

bool World::GameLoop()
{
	clock_t now = clock();
	bool ret = false;
	//Clock every second
	if ((now - timer) / 500 > FRAME_RATE)
	{
		for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
			ret |= (*it)->Update();
		timer = now;
	}
	return ret;
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
			player->Stats();
		}
		else if (Same(args[0], "go"))
		{
			cout << "You must say where you want to go.\n";
		}
		else if (Same(args[0], "east") || Same(args[0], "west") || Same(args[0], "north") || Same(args[0], "south") || Same(args[0], "up"))
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
		else if (Same(args[0], "ignite") || Same(args[0], "exura") || Same(args[0], "tortolize"))
		{
			player->UseSpell(args);
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
		else if (Same(args[0], "use"))
		{
			player->Use(args);
		}
		else ret = false;
		break;
	case 4:
		if (Same(args[0], "use") && Same(args[2], "on"))
		{
			player->UseOn(args);
		}
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
	Room *diningroom = new Room("Dinning room", "You are at the dining room. The room is very big, at the middle\nyou can see the table, at the east part there are three sofas.");
	Room *kitchen = new Room("Kitchen", "This is the kitchen of the castle. It is plenty of cooking items.");
	Room *firstfloor = new Room("First floor", "You see a huge room.");
	Room *library = new Room("The library", "You are at the castle\'s library. The ceiling is very high.\nYou can see an enormous number of books. There is an stair to arrive to the books at the top of the shelfs.");
	Room *room = new Room("Room", "You are at the castle’s main room. It\'s plenty of spider silks.");
	Room *dungeon = new Room("Dungeon", "You are at the dungeon. There is a lot of darkness and it\'s hard to see arrownd.");
	Room *secretPasage = new Room("Secret pasage", "You are in a secret pasage!\n The walls have torchs which guide you.");
	Room *hiddenRoom = new Room("Hidden room", "You are in the secret office from the castle\'s owner.\nIt\'s georgious! Plenty of decoration, books and an awesome table.");
	Room *catacombs = new Room("Catacombs", "There are many treasures here. You can see far away how it shines!");
	Room *neverAcces = new Room("neverAcces", "neverAcces");

	entities.push_back(forest);
	entities.push_back(bridge);
	entities.push_back(door);
	entities.push_back(hall);
	entities.push_back(diningroom);
	entities.push_back(kitchen);
	entities.push_back(firstfloor);
	entities.push_back(library);
	entities.push_back(room);
	entities.push_back(dungeon);
	entities.push_back(secretPasage);
	entities.push_back(hiddenRoom);
	entities.push_back(catacombs);
	entities.push_back(neverAcces);
	//Player creation
	string name = Introduction().c_str();
	player = new Player(name.c_str(), "You are a magician apprentice", library, this);
	entities.push_back(player);

	//Items from player since start
	Item *document = new Item("Document", "Mission:\nYou blabla", player, nullptr, false);
	Item *spellbook = new Item("Spellbook", "This is your spellbook, it contains all the spells you know.", player, nullptr, false);
	Item *doorSign = new Item("Sign", "Only the helthy people can enter the castle!", door, nullptr, true);
	Item *table = new Item("Table", "You can see a table in the middle of the library!", library, nullptr, true);
	Item *kitchenTable = new Item("Table", "This table is full of coocking items.", kitchen, nullptr, true);
	Item *ink = new Item("Ink", "You can see a pot of black ink. The pot have the draw of a dragon", table, nullptr, true);
	Item *lamp = new Item("Lamp", "You can see a lamp. It\'s very old it should not work.", table, nullptr, true);
	Potion* potion1 = new Potion("Potion", "Use this potion will give you 50 mana points.", hall, nullptr, false);
	Potion* potion2 = new Potion("Potion", "Use this potion will give you 50 mana points.", kitchen, nullptr, false);
	Ignite *sbPage1 = new Ignite("Bookpage1", "Ignite: This spell throws a flame to the enemy.\nYou will deal 10 damage.", spellbook, spellbook, 20, 10, "ignite");
	Exura *sbPage2 = new Exura("Bookpage2", "Exura: This spell restore you hit points.\nYou will get 30 hp.", door, spellbook, 20, 10, "exura");
	Stair *stair = new Stair("Stair", "You can see an stair, it should help to get the books from the top of the shelf.", library, nullptr, true);
	Bottle *bottle = new Bottle("Bottle", "You can see a glass bottle.", kitchen, nullptr, false);
	Item *water = new Item("Water", "It\'s a crystaline water", kitchen, bottle, false);
	Fireplace *fireplace = new Fireplace("Fireplace", "You can see and extremly beautifull fireplace", diningroom, water, true, true);

	//Temporal object to be replaced
	Item *key= new Item("Key", "You can see a key. It\'s seems quite new, it must open a door.", neverAcces, nullptr, false);

	entities.push_back(document);
	entities.push_back(spellbook);
	entities.push_back(sbPage1);
	entities.push_back(sbPage2);
	entities.push_back(doorSign);
	entities.push_back(potion1);
	entities.push_back(potion2);
	entities.push_back(stair);
	entities.push_back(table);
	entities.push_back(ink);
	entities.push_back(lamp);
	entities.push_back(kitchenTable);
	entities.push_back(bottle);
	entities.push_back(water);
	entities.push_back(fireplace);

	entities.push_back(key);


	//Monsters
	Spider *spiderOfBridge = new Spider("Spider", "You can see an spider", bridge);
	entities.push_back(spiderOfBridge);
	Spider *spiderOfHall = new Spider("Spider", "You can see an spider", hall);
	entities.push_back(spiderOfHall);

	//Exits
	Exit *forestToBridge = new Exit("east", "This is a sandy road which arrives until the bridge", "bridge", forest, bridge, false, nullptr);
	Exit *bridgeToForest = new Exit("west", "This is a sandy road which arrives until the forest", "forest", bridge, forest, false, nullptr);
	Exit *bridgeToDoor = new Exit("east", "This bridge brings you to the door", "path", bridge, door, false, spiderOfBridge);
	Exit *doorToBridge = new Exit("west", "This path brings you to the bridge", "bridge", door, bridge, false, nullptr);
	Exit *doorToHall = new Exit("east", "This is the main door from the castle", "door", door, hall, true, player);
	Exit *HallToDoor = new Exit("west", "This is the main door from the castle", "door", hall, door, false, nullptr);
	Exit *HallToKitchen = new Exit("south", "You can see the kitchen right there", "kitchen", hall, kitchen, false, nullptr);
	Exit *KitchenToHall = new Exit("north", "You can see the big hall", "hall", kitchen, hall, false, nullptr);
	Exit *HallToDiningroom = new Exit("east", "You can see the dining room throw the door", "dining room", hall, diningroom, false, nullptr);
	Exit *DiningroomToHall = new Exit("west", "You can see the big hall", "hall", diningroom, hall, false, nullptr);
	Exit *HallToFirstfloor = new Exit("up", "You can see an extremly beautifull stairs which arrive to the first floor", "stairs", hall, firstfloor, false, nullptr);
	Exit *FirstfloorToHall = new Exit("down", "You can see an extremly beautifull stairs which arrive to the hall", "stairs", firstfloor, hall, false, nullptr);
	Exit *FirstfloorToLibrery = new Exit("west", "You can see an opened door and something like a library behind", "door", firstfloor, library, false, nullptr);
	Exit *LibreryToFirstfloor = new Exit("east", "You can see an opened door and the first floor room behind", "door", library, firstfloor, false, nullptr);
	Exit *FirstfloorToRoom = new Exit("east", "You can see a door. This door is quite elegant.", "door", firstfloor, room, true, key);

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
	entities.push_back(FirstfloorToLibrery);
	entities.push_back(LibreryToFirstfloor);

	

	return true;
}

void World::CreateBookpage3()
{
	Entity* spellbook = nullptr;
	Entity* library = nullptr;
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
	{
		if (Same((*it)->name, "Spellbook"))
		{
			spellbook = (*it);
		}
		else if (Same((*it)->name, "The library"))
		{
			library = (*it);
		}
	}
		
	Tortolize* sbPage3 = new Tortolize("Bookpage3", "Tortolize: This spell will give you a shiled of 120 seconds of energy.\nAll the damage you recieve will decreace the shield time.", library, spellbook, 10, 60, "tortolize");
	entities.push_back(sbPage3);
}

void World::CreateKey1()
{
	Entity* dinningroom = nullptr;
	Entity* exitFirstFloorToRoom = nullptr;
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
	{
		if (Same((*it)->name, "Dinning room"))
		{
			dinningroom = (*it);
		}
	}
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
	{
		if (Same((*it)->name, "Key"))
		{
			(*it)->ChangeParentTo(dinningroom);
		}
	}
}
