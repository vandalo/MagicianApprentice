#include <iostream>
#include "Room.h"
#include "Exit.h"
#include "Player.h"


Exit::Exit(const char * name, const char * description, const char * destinationName, Room* origin, Room *destination, bool closed, Entity* condition) :
Entity(name, description, (Entity*)origin), closed(closed), destinationName(destinationName), destination(destination), condition(condition)
{
	type = EXIT;
}

Exit::~Exit()
{}

void Exit::Look() const{
	cout << "At " << name << " to " << destinationName << "\n";
	cout << description << "\n";
	if (closed == true)
	{
		cout << "The " << destinationName << " is locked.\n";
	}
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

const string Exit::GetDestination() const
{
	if (destinationName != nullptr)
	{
		return destinationName;
	}
	else
	{
		return "";
	}
	
}

void Exit::Open()
{
	if (condition == nullptr)
	{
		closed = false;
		cout << "The " << destinationName << " is open now.\n";
	}
	else if (condition->type == PLAYER)
	{
		Player* player = (Player*)condition;
		if ((player->GetHp() * 100 / player->GetMaxHp()) > 75)
		{
			closed = false;
			cout << "The " << destinationName << " is open now.\n";
		}
		else
		{
			cout << "Only the healthy's can open " << destinationName << ".\n";
		}
	}
}
