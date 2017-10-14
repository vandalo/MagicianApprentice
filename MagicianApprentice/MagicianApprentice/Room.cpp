#include <iostream>
#include "Utils.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"

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
		if ((*it)->type == ITEM)
		{
			Item* item = (Item*)*it;
			cout << "You can see a " << item->name.c_str() << ".\n";
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

/*Item * Room::GetItemByName(const string item_name)
{
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
	{
		if ((*it)->type == ITEM) {
			Item* item = (Item*)*it;
			if (Same(item->name, item_name))
			{
				return item;
			}
		}
	}
	return nullptr;
}*/
