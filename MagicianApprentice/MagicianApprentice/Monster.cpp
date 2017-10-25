#include <iostream>
#include "Utils.h"
#include "Monster.h"
#include "Exit.h"
#include "Room.h"
#include "Item.h"
#include <string>

Monster::Monster(const char* name, const char* description, Entity* parent) :
	Creature(name, description, parent)
{
	type = MONSTER;

	hp = 50;
	maxHp = 50;
	mana = 100;
	lvl = 1;

}

Monster::~Monster()
{}

int Monster::GetHp()
{
	return hp;
}

int Monster::GetMaxHp()
{
	return maxHp;
}

bool Monster::Atack()
{
	return true;
}

unsigned int Monster::reciveAtack(unsigned int damage)
{
	hp -= damage;
	return damage;
}

Room* Monster::GetRoom() const
{
	return (Room*)parent;
}

void Monster::Look() const
{
	if(hp > 0)
	{
		cout << "You see an " << name << ".\n";
	}
	else
	{
		cout << "You see a defeated " << name << ".\n";
	}
	
	cout << description << "\n";
	cout << information << "\n";
	Stats();
}

void Monster::Stats() const
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
	else
	{
		cout << name << " is almost death, ";
	}

	cout << name << " have " << hp << "/" << maxHp << " hit points" << endl;
}