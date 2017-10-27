#ifndef __Picture__
#define __Picture__

#include <string>
#include <list>
#include "Item.h"

class Player;

class Picture : public Item
{

public:
	Picture(const char* name, const char* description, Entity* parent, Entity* must, bool fix);
	void Use(Player* player, const vector<string>& args);
	void Look() const;

public:
	bool used;

private:
};

#endif