#include <iostream>
#include "Room.h"
#include "Exit.h"


Exit::Exit(const char * name, const char * description, const char * destinationName, Room* origin, Room *destination, bool locked, bool closed) :
Entity(name, description, (Entity*)origin), closed(locked), locked(closed), destinationName(destinationName), destination(destination)
{
	type = EXIT;
}

Exit::~Exit()
{}

void Exit::Look() const{
	cout << "At " << name << " to " << destinationName << "\n";
	cout << description << "\n";
}

const string& Exit::GetNameByRoom(const Room* room) const
{
	if (room == parent)
	{
		return name;
	}
		
	if (room == destination)
	{
		return destinationName;
	}

	return name;
}

Room* Exit::GetDestinationByRoom(const Room* room) const
{
	if (room == parent)
	{
		return destination;
	}
		
	if (room == destination)
	{
		return (Room*)parent;
	}

	return nullptr;
}