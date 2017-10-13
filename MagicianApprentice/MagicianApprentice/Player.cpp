#include <iostream>
#include "Utils.h"
#include "Player.h"
#include "Exit.h"
#include "Room.h"

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


