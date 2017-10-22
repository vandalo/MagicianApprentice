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
	void Stats(const vector<string>& args) const;
	Room* GetRoom() const;
	int GetHp();
	int GetMaxHp();
	bool Atack();
	unsigned int reciveAtack(unsigned int damage);

public:
	const char* information;
};

#endif