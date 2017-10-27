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

	hp = 50;
	maxHp = 50;
	mana = 100;
	lvl = 1;

}

Creature::~Creature()
{}

int Creature::GetHp()
{
	return hp;
}

int Creature::GetMaxHp()
{
	return maxHp;
}

bool Creature::Atack()
{
	return true;
}

bool Creature::IsAlive()
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