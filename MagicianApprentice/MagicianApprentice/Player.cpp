#include <iostream>
#include "Utils.h"
#include "Player.h"
#include "Exit.h"
#include "Room.h"
#include "Item.h"
#include <string>

Player::Player(const char* name, const char* description, Entity* parent) :
	Entity(name, description, parent)
{
	type = PLAYER;

	if (parent != nullptr)
		parent->container.push_back(this);

	hp = 50;
	maxHp = 50;
	mana = 100;
	lvl = 1;

}

Player::~Player()
{}

void Player::Look(const vector<string>& args) const
{
	if (args.size() > 1)
	{
		for (list<Entity*>::const_iterator it = parent->container.begin(); it != parent->container.cend(); ++it)
		{
			if (Same((*it)->name, args[1]))
			{
				(*it)->Look();
				return;
			}
		}

		for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
		{
			if (Same((*it)->name, args[1]))
			{
				(*it)->Look();
				return;
			}
		}

		if (Same(args[1], "me"))
		{
			cout << name << "\n";
			cout << description << "\n";
		}
	}
	else
	{
		parent->Look();
	}
}

void Player::Stats(const vector<string>& args) const
{
	int lifePercent = hp * 100 / maxHp;

	cout << "You are level " << lvl << endl;

	if (lifePercent > 75)
	{
		cout << "You are healthy, ";
	}
	else if (lifePercent > 25)
	{
		cout << "You are hurt, ";
	}
	else
	{
		cout << "You are almost death, ";
	}

	cout << "you have " << hp << "/" << maxHp << " hit points" << endl;
	cout << "You have " << mana << " mana points" << endl;
}

Room* Player::GetRoom() const
{
	return (Room*)parent;
}

void Player::Inventory(const vector<string>& args) const
{
	list<Entity*> items;
	FindByTypeAndPropietary(ITEM, items, (Entity*)this);

	for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
	{
		(*it)->Look();
	}
}

void Player::Go(const vector<string>& args)
{
	Exit* exit = GetRoom()->GetExitByName(args[1]);
	if (exit == nullptr) 
	{
		cout << "There aren't anything on " + (args[1]) + ".\n";
	}
	else
	{
		ChangeParentTo(exit->GetDestinationByRoom(GetRoom()));
		parent->Look();
	}
}

void Player::Take(const vector<string>& args)
{	
	Item* item = (Item*)GetItemByName(args[1]);

	if (item != nullptr)
	{
		cout << "You already have " + item->name + ".\n";
	}
	else
	{
		item = (Item*)GetRoom()->GetItemByName(args[1]);
		if (item == nullptr)
		{
			cout << "There aren't any item called " + (args[1]) + ".\n";
		}
		else if (item->fixed)
		{
			cout << "You can't take " + (args[1]) + ".\n";
		}
		else
		{
			if (item->must == nullptr)
			{
				item->ChangeParentTo(this);
				cout << "You added the page to your inventory.\n";
			}
			else
			{
				list<Entity*> items;
				FindByTypeAndPropietary(ITEM, items, (Entity*)this);
				for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
				{
					if ((*it)->name == item->must->name)
					{
						item->ChangeParentTo(*it);
						cout << "You added the page to your " + (*it)->name + ".\n";
					}
				}
			}
		}
	}
}