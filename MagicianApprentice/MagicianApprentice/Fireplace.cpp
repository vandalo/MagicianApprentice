#include <iostream>
#include "Utils.h"
#include "Room.h"
#include "Player.h"
#include "Fireplace.h"

Fireplace::Fireplace(const char* name, const char* description, Entity* parent, Entity* must, bool fix, bool isOn) :
	Item(name, description, parent, must, fix), isOn(isOn)
{
	used = false;
}

void Fireplace::Look() const {
	cout << name;
	if (name.length() > 0)
	{
		cout << "\n";
	}
	cout << description;
	if (isOn)
	{
		cout << " with a combination of orange, red and blue flames.\n";
	}
	else
	{
		cout << " plenty of ashes.\n";
	}

}

void Fireplace::Use(Player * player, const vector<string>& args)
{
	if (used == false)
	{
		list<Entity*> items;
		FindByTypeAndPropietary(ITEM, items, player);
		bool find = false;
		for (list<Entity*>::const_iterator it = items.begin(); it != items.cend() && find == false; ++it)
		{
			if (Same((*it)->name, args[1]))
			{
				find = true;
			}
			if (find == false && (*it)->container.size() > 0)
			{
				for (list<Entity*>::const_iterator itInside = (*it)->container.begin(); itInside != (*it)->container.cend() && find == false; ++itInside)
				{
					if (Same((*itInside)->name, args[1]))
					{
						find = true;
					}
				}
			}
		}
		if (find)
		{
			//Object finded and needed
			if (Same(args[1], must->name))
			{
				used = true;
				isOn = false;
				cout << "You have used the water to turn of the fire! Now you can see something shining there.\n";
				player->CreateKey1();
			}
			//Object finded but is not the needed
			else
			{
				cout << "You can\'t use " << must->name << " on " << name << ".\n";
			}
		}
		else
		{
			cout << "You don\'t have " << args[1] << " on your inventory.\n";
		}
	}
}

