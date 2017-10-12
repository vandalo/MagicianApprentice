#ifndef __Room__
#define __Room__

#include <string>
#include <list>
#include "entity.h"

using namespace std;


class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	~Room();

	void Look() const;


public:
};

#endif