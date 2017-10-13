#ifndef __Exit__
#define __Exit__

#include <string>
#include <list>
#include "Entity.h"


using namespace std;

class Room;

class Exit : public Entity
{
public:
	Exit(const char* name, const char* description, const char* destinationName, Room* origin, Room* destination, bool locked, bool closed);
	~Exit();


	void Look() const;

	const string & GetNameByRoom(const Room * room) const;
	Room* GetDestinationByRoom(const Room * room) const;
	
private:

	Room* destination = nullptr;
	const char* destinationName = nullptr;
	bool closed;
	bool locked;
};

#endif