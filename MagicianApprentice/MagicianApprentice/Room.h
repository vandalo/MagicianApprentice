#ifndef __Room__
#define __Room__

#include <string>
#include <list>
#include "entity.h"

class Exit;
class Item;

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	~Room();
	void Look() const;
	Exit* GetExitByName(const string exit_name) const;
};

#endif