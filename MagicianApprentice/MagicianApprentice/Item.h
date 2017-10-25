#ifndef __Item__
#define __Item__

#include <string>
#include <list>
#include "Entity.h"

class Player;

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity* parent, Entity* must, bool fix);
	~Item();
	virtual void Look() const;
	virtual void Use(Player* player, const vector<string>& args);
	//bool Update();

public:
	bool fixed;
	Entity* must;	//This entity is a must that player need to collect the item.


private:
	
};

#endif