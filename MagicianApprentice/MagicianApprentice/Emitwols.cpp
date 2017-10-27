#include <iostream>
#include "Utils.h"
#include "Room.h"
#include "Player.h"
#include "Monster.h"
#include "Emitwols.h"

Emitwols::Emitwols(const char* name, const char* description, Entity* parent, Entity* must, int mana, int cd, const char* nameSpell) :
	Spell(name, description, parent, must, mana, cd, nameSpell)
{}

void Emitwols::effect(Player * player)
{
	player->UpdateMana(-(int)mana);

	Room* room = player->GetRoom();
	for (list<Entity*>::const_iterator it = room->container.begin(); it != room->container.cend(); ++it)
	{
		if ((*it)->type == MONSTER)
		{
			Monster* monster = (Monster*)(*it);
			if (monster->IsAlive() == true)
			{
				monster->cooldown1 *= 2;
				monster->maxCooldown1 *= 2;
				monster->cooldown2 *= 2;
				monster->maxCooldown2 *= 2;
			}
		}
	}
	cdTime = cd;
}
