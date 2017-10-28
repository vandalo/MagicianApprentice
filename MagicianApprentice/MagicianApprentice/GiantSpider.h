#ifndef __GiantSpider__
#define __GiantSpider__

#include <string>
#include <list>
#include "Monster.h"
#include <vector>

class Room;

class GiantSpider : public Monster
{
public:
	GiantSpider(const char* name, const char* description, Entity* parent);
	~GiantSpider();
	bool Atack();
};

#endif