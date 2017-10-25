#include <iostream>
#include "Utils.h"
#include "Room.h"
#include "Item.h"
#include "Player.h"


Item::Item(const char* name, const char* description, Entity* parent, Entity* must, bool fix) :
	Entity(name, description, parent),fixed(fix),must(must)
{
	type = ITEM;
}

Item::~Item()
{}

void Item::Look() const {
	cout << name;
	if (name.length() > 0)
	{
		cout << "\n";
	}
	cout << description << "\n";

	//Print items if it have items inside
	if (container.size() > 0) cout << name + " contains:\n";
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
	{
		if ((*it)->type == ITEM || (*it)->type == SPELL)
		{
			Item* item = (Item*)*it;
			item->Look();
		}
	}
	cout << "\n";
}

void Item::Use(Player* player, const vector<string>& args)
{
	cout << "This item can\'t not be used!\n";
}
