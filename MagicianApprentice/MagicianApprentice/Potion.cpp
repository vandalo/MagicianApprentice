#include <iostream>
#include "Utils.h"
#include "Room.h"
#include "Player.h"
#include "Potion.h"

Potion::Potion(const char* name, const char* description, Entity* parent, Entity* must, bool fix) :
	Item(name, description, parent, must, fix)
{
	used = false;
}

void Potion::Use(Player * player, const vector<string>& args)
{
	if (used == false)
	{
		player->UpdateMana(50);
		used = true;
		cout << "You win 50 mana points.\n";
		parent = nullptr;
	}
}
