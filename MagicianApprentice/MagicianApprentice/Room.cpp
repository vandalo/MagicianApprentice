#include <iostream>
#include "Utils.h"
#include "Room.h"

// ----------------------------------------------------
Room::Room(const char* name, const char* description) :
	Entity(name, description, nullptr)
{
	type = ROOM;

	if (parent != nullptr)
		parent->container.push_back(this);
}

Room::~Room()
{}

void Room::Look() const
{
	cout << name << "\n";
	cout << description << "\n";
}
