#include <iostream>
#include "Utils.h"
#include "Dragon.h"
#include "Exit.h"
#include "Room.h"
#include "Item.h"
#include "Player.h"
#include <string>

Dragon::Dragon(const char* name, const char* description, Entity* parent) :
	Monster(name, description, parent)
{
	type = MONSTER;

	hp = 50;
	maxHp = 50;
	mana = 0;
	lvl = 1;
	information = "The Dragon atacks every 3 seconds using a normal attack and he send a giant fireball every 15 seconds.\n";
	attack1 = 5;
	maxCooldown1 = 3;
	cooldown1 = 3;
	attack2 = 40;
	maxCooldown2 = 15;
	cooldown2 = 15;
}

Dragon::~Dragon()
{}

bool Dragon::Atack()
{
	bool ret = false;
	if (cooldown1 <= 0 || cooldown2 <= 0)
	{
		Room* room = GetRoom();
		for (list<Entity*>::const_iterator it = room->container.begin(); it != room->container.cend(); ++it)
		{
			if ((*it)->type == PLAYER)
			{
				Player* player = (Player*)(*it);
				if (cooldown1 <= 0)
				{
					unsigned int damage = player->ReciveAtack(attack1);
					cout << "\nThe " << name << " deals you " << damage << " hitpoints.\n";
					ret = true;
					cooldown1 = maxCooldown1;
				}
				else
				{
					cooldown1--;
				}
				if (cooldown2 <= 0)
				{
					unsigned int damage = player->ReciveAtack(attack2);
					cout << "\nThe " << name << " deals you " << damage << " hitpoints with a great fireball!.\n";
					ret = true;
					cooldown2 = maxCooldown2;
				}
				else
				{
					cooldown2--;
				}
				
			}
		}
	}
	else
	{
		cooldown1--;
		cooldown2--;
	}
	return ret;
}