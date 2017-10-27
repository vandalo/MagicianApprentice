#ifndef __Creature__
#define __Creature__

#include <string>
#include <list>
#include "entity.h"
#include <vector>

class Room;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Entity* parent);
	~Creature();

	void Look() const;
	void Stats() const;
	Room* GetRoom() const;
	int GetHp();
	int GetMaxHp();
	bool Atack();
	bool IsAlive();

public:
	unsigned int lvl = 0;
	unsigned int hp = 0;
	unsigned int maxHp = 0;
	unsigned int mana = 0;
	unsigned int cooldown = 0;
	unsigned int maxCooldown = 0;
};

#endif