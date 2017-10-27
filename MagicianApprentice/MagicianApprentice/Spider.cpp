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
	attack1 = 5;
	information = "The spider attacks every five seconds while your heals points is higer than 75%.";
	maxCooldown1 = 5;
	cooldown1 = 5;
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
	if (cooldown1 <= 0)
	{
		Room* room = GetRoom();
		for (list<Entity*>::const_iterator it = room->container.begin(); it != room->container.cend(); ++it)
		{
			if ((*it)->type == PLAYER)
			{
				Player* player = (Player*)(*it);
				if (player->GetHp() * 100 / player->GetMaxHp() > 75)
				{
					unsigned int damage = player->ReciveAtack(attack1);
					cout << "\nThe " << name << " deals you " << damage << " hitpoints.\n";
					ret = true;
				}
			}
		}
		cooldown1 = maxCooldown1;
	}
	else
	{
		cooldown1--;
	}
	return ret;
}	

bool Spider::Update()
{
	bool ret = false;
	if (IsAlive())
	{
		ret = Atack();
	}
	return ret;
}

Room* Spider::GetRoom() const
{
	return (Room*)parent;
}