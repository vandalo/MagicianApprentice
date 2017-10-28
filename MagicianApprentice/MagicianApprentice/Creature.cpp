#include <iostream>
#include "Utils.h"
#include "Creature.h"
#include "Exit.h"
#include "Room.h"
#include "Item.h"
#include <string>

Creature::Creature(const char* name, const char* description, Entity* parent) :
	Entity(name, description, parent)
{
	type = CREATURE;
	hp = 0;
	maxHp = 0;
	mana = 0;
	lvl = 0;
}

Creature::~Creature()
{}

int Creature::GetHp() const
{
	return hp;
}

int Creature::GetMaxHp() const
{
	return maxHp;
}

bool Creature::Atack()
{
	return true;
}

bool Creature::IsAlive() const
{
	return hp > 0;
}

Room* Creature::GetRoom() const
{
	return (Room*)parent;
}

void Creature::Look() const
{
	cout << name << "\n";
	cout << description << "\n";
	Stats();
}

void Creature::Stats() const
{
	int lifePercent = hp * 100 / maxHp;

	//cout << "You are level " << lvl << endl;

	if (lifePercent > 75)
	{
		cout << name << " is healthy, ";
	}
	else if (lifePercent > 25)
	{
		cout << name << " is hurt, ";
	}
	else if (lifePercent > 0)
	{
		cout << name << " is almost death, ";
	}
	else
	{
		cout << name << " is death, ";
	}

	cout << name << " have " << hp << "/" << maxHp << " hit points" << endl;
}