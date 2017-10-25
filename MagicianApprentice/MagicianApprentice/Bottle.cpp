#include <iostream>
#include "Utils.h"
#include "Room.h"
#include "Player.h"
#include "Bottle.h"

Bottle::Bottle(const char* name, const char* description, Entity* parent, Entity* must, bool fix) :
	Item(name, description, parent, must, fix)
{
	used = false;
}

void Bottle::Use(Player * player)
{
	if (used == false)
	{
		used = true;
	}
}
