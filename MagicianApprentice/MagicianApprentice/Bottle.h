#ifndef __Bottle__
#define __Bottle__

#include <string>
#include <list>
#include "Item.h"

class Player;

class Bottle : public Item
{

public:
	Bottle(const char* name, const char* description, Entity* parent, Entity* must, bool fix);
	void Use(Player* player);

public:
	bool used;

private:

};

#endif