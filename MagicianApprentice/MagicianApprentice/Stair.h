#ifndef __Stair__
#define __Stair__

#include <string>
#include <list>
#include "Item.h"

class Player;

class Stair : public Item
{

public:
	Stair(const char* name, const char* description, Entity* parent, Entity* must, bool fix);
	void Use(Player* player, const vector<string>& args);

public:
	bool used;
};

#endif