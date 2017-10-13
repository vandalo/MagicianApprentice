#ifndef __Item__
#define __Item__

#include <string>
#include <list>
#include "Entity.h"

class Entity;

using namespace std;

class Room;

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity* parent);
	~Item();

	void Look() const;



private:

};

#endif