#include <iostream>
#include "Utils.h"
#include "Room.h"
#include "Player.h"
#include "Stair.h"

Stair::Stair(const char* name, const char* description, Entity* parent, Entity* must, bool fix) :
	Item(name, description, parent, must, fix)
{
	used = false;
}

void Stair::Use(Player * player, const vector<string>& args)
{
	if (used == false)
	{
		used = true;
		cout << "You have moved the books of th top side, thanks to the stairs, and something has fall in to the floor.\n";
		player->CreateBookpage3();
	}
}
