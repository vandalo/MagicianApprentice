#include <iostream>
#include "Utils.h"
#include "Spider.h"
#include "Exit.h"
#include "Room.h"
#include "Item.h"
#include "Player.h"
#include <string>

Spider::Spider(const char* name, const char* description, Entity* parent) :
	Monster(name, description, parent)
{
	type = MONSTER;

	hp = 10;
	maxHp = 10;
	mana = 0;
	lvl = 1;
	atack = 5;
	information = "The spider atacks every five seconds while your heals points is higer than 75%.";
	maxCooldown = 5;
	cooldown = 5;
}

Spider::~Spider()
{}

int Spider::GetHp()
{
	return hp;
}

int Spider::GetMaxHp()
{
	return maxHp;
}

bool Spider::Atack()
{
	bool ret = false;
	if (cooldown <= 0)
	{
		Room* room = GetRoom();
		for (list<Entity*>::const_iterator it = room->container.begin(); it != room->container.cend(); ++it)
		{
			if ((*it)->type == PLAYER)
			{
				Player* player = (Player*)(*it);
				if (player->GetHp() * 100 / player->GetMaxHp() > 75)
				{
					unsigned int damage = player->reciveAtack(atack);
					cout << "\nThe " << name << " deals you " << damage << " hitpoints.\n";
					ret = true;
				}
			}
		}
		cooldown = maxCooldown;
	}
	else
	{
		cooldown--;
	}
	return ret;
}	

bool Spider::Update()
{
	if (IsAlive())
	{
		return Atack();
	}
}

Room* Spider::GetRoom() const
{
	return (Room*)parent;
}

/*void Spider::Look() const
{
	cout << name << "\n";
	cout << description << "\n";
	cout << information << "\n";
}*/

void Spider::Stats(const vector<string>& args) const
{
	int lifePercent = hp * 100 / maxHp;

	//cout << "You are level " << lvl << endl;

	if (lifePercent > 75)
	{
		cout << name << "is healthy, ";
	}
	else if (lifePercent > 25)
	{
		cout << name << "is hurt, ";
	}
	else
	{
		cout << name << "is almost death, ";
	}

	cout << name << " have " << hp << "/" << maxHp << " hit points" << endl;
	cout << name << " have " << mana << " mana points" << endl;
}