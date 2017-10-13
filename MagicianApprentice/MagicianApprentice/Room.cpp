#include <iostream>
#include "Utils.h"
#include "Room.h"
#include "Exit.h"

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

	//Print exits
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
	{
		if ((*it)->type == EXIT)
		{
			Exit* exit = (Exit*)*it;
			cout << "At " << exit->GetNameByRoom(this) << " you can see " << exit->GetDestinationByRoom(this)->name << "\n";
		}
	}

}

Exit * Room::GetExitByName(const string exit_name)
{
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
	{
		if ((*it)->type == EXIT) {
			Exit* exit = (Exit*)*it;
			if (Same(exit->GetNameByRoom(this), exit_name))
			{
				return exit;
			}
		}
	}
	return nullptr;
}
