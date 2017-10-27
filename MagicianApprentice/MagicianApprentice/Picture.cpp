#include <iostream>
#include "Utils.h"
#include "Room.h"
#include "Player.h"
#include "Picture.h"

Picture::Picture(const char* name, const char* description, Entity* parent, Entity* must, bool fix) :
	Item(name, description, parent, must, fix)
{
	used = false;
}

void Picture::Use(Player * player, const vector<string>& args)
{
	if (used == false)
	{
		used = true;
		cout << "You have moved the picture and you have discovered a secret door.\n";
		player->CreateSecretExit();
	}
}

void Picture::Look() const {
	cout << name << ".\n";
	cout << description;
}
