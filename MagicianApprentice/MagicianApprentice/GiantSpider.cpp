#include <iostream>
#include "Utils.h"
#include "GiantSpider.h"
#include "Exit.h"
#include "Room.h"
#include "Item.h"
#include "Player.h"
#include <string>

GiantSpider::GiantSpider(const char* name, const char* description, Entity* parent) :
	Monster(name, description, parent)
{
	type = MONSTER;

	hp = 30;
	maxHp = 30;
	mana = 0;
	lvl = 1;
	attack1 = 15;
	information = "The Giant Spider atacks every five seconds.\n";
	maxCooldown1 = 5;
	cooldown1 = 5;
}

GiantSpider::~GiantSpider()
{}

bool GiantSpider::Atack()
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
				unsigned int damage = player->ReciveAtack(attack1);
				cout << "\nThe " << name << " deals you " << damage << " hitpoints.\n";
				ret = true;
				cooldown1 = maxCooldown1;
			}
		}
	}
	else
	{
		cooldown1--;
	}
	return ret;
}
