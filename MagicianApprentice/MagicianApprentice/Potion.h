#ifndef __Potion__
#define __Potion__

#include <string>
#include <list>
#include "Item.h"

class Player;

class Potion : public Item
{

public:
	Potion(const char* name, const char* description, Entity* parent, Entity* must, bool fix);
	void Use(Player* player, const vector<string>& args);

public:
	bool used;
};

#endif