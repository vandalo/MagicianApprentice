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
	hp = 0;
	maxHp = 0;
	mana = 0;
	lvl = 0;
}

Monster::~Monster()
{}

unsigned int Monster::ReciveAtack(unsigned int damage)
{
	hp -= damage;
	return damage;
}

void Monster::Look() const
{
	if (hp > 0)
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

bool Monster::Update()
{
	bool ret = false;
	if (IsAlive())
	{
		ret = Atack();
	}
	return ret;
}
