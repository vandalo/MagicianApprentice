#ifndef __Dragon__
#define __Dragon__

#include <string>
#include <list>
#include "Monster.h"
#include <vector>

class Room;

class Dragon : public Monster
{
public:
	Dragon(const char* name, const char* description, Entity* parent);
	~Dragon();
	bool Atack();
};

#endif