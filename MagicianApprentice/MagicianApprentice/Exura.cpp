#include <iostream>
#include "Utils.h"
#include "Room.h"
#include "Player.h"
#include "Exura.h"

Exura::Exura(const char* name, const char* description, Entity* parent, Entity* must, int mana, int cd, const char* nameSpell) :
	Spell(name, description, parent, must, mana, cd, nameSpell)
{}

void Exura::effect(Player * player)
{
	player->updateHp(30);
	player->updateMana(-(int)mana);
	cdTime = cd;
}
