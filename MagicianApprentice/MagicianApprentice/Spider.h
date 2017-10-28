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
	bool Atack();
};

#endif