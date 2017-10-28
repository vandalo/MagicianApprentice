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

	virtual void Look() const;
	virtual void Stats() const;
	virtual Room* GetRoom() const;
	virtual int GetHp() const;
	virtual int GetMaxHp() const;
	virtual bool Atack();
	virtual bool IsAlive() const;

public:
	unsigned int lvl = 0;
	unsigned int hp = 0;
	unsigned int maxHp = 0;
	unsigned int mana = 0;
	unsigned int cooldown = 0;
	unsigned int maxCooldown = 0;
};

#endif