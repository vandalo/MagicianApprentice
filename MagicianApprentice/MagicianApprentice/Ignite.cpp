#include <iostream>
#include "Utils.h"
#include "Room.h"
#include "Player.h"
#include "Ignite.h"
#include "Monster.h"

Ignite::Ignite(const char* name, const char* description, Entity* parent, Entity* must, int mana, int cd, const char* nameSpell) :
	Spell(name, description, parent, must, mana, cd, nameSpell)
{}

void Ignite::effect(Player * player)
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
				unsigned int damage = monster->ReciveAtack(10);
				cout << "You deal " << damage << " damage to " << monster->name << ".\n";
				if (monster->IsAlive() == false)
				{
					cout << "You defeat the " << monster->name << ".\n";
				}
			}

		}
	}
	cdTime = cd;
}