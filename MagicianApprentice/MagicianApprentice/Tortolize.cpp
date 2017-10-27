#include <iostream>
#include "Utils.h"
#include "Room.h"
#include "Player.h"
#include "Tortolize.h"

Tortolize::Tortolize(const char* name, const char* description, Entity* parent, Entity* must, int mana, int cd, const char* nameSpell) :
	Spell(name, description, parent, must, mana, cd, nameSpell)
{}

void Tortolize::effect(Player * player)
{
	player->UpdateShield(120);
	player->UpdateMana(-(int)mana);
	cdTime = cd;
	cout << "You get a shield of 120 seconds.\n";
}
