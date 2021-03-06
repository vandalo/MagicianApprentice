#ifndef __Monster__
#define __Monster__

#include <string>
#include <list>
#include "creature.h"
#include <vector>

class Room;

class Monster : public Creature
{
public:
	Monster(const char* name, const char* description, Entity* parent);
	~Monster();
	void Look() const;
	bool Update();
	unsigned int ReciveAtack(unsigned int damage);
	virtual bool Atack() = 0;
	

public:
	unsigned int cooldown1 = 0;
	unsigned int maxCooldown1 = 0;
	unsigned int cooldown2 = 0;
	unsigned int maxCooldown2 = 0;
	unsigned int attack1 = 0;
	unsigned int attack2 = 0;
	const char* information;
};

#endif