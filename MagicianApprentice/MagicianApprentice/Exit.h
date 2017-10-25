#ifndef __Exit__
#define __Exit__

#include <string>
#include <list>
#include "Entity.h"

class Room;
class Player;

class Exit : public Entity
{
public:
	Exit(const char* name, const char* description, const char* destinationName, Room* origin, Room* destination, bool closed, Entity* condition);
	~Exit();


	void Look() const;

	const string GetNameByRoom(const Room * room) const;
	Room* GetDestinationByRoom(const Room * room) const;
	const string GetDestination() const;
	void Open(Player* player);
	
public:
	bool closed;
	Entity* condition;

private:
	const char* destinationName = nullptr;
	Room* destination = nullptr;
};

#endif