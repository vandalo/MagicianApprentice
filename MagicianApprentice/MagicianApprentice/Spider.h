#ifndef __Spider__
#define __Spider__

#include <string>
#include <list>
#include "Monster.h"
#include <vector>

class Room;

class Spider : public Monster
{
public:
	Spider(const char* name, const char* description, Entity* parent);
	~Spider();

	Room* GetRoom() const;
	int GetHp();
	int GetMaxHp();
	bool Atack();
	bool Update();

private:
};

#endif