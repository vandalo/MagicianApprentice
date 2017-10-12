#include <iostream>
#include "utils.h"
#include "world.h"
#include "Defines.h"
#include "Entity.h"

World::World()
{
	clock_t timer = clock();
}

bool World::Init() {
	clock_t timer = clock();
	return true;
}

World::~World()
{
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		delete *it;

	entities.clear();
}

bool World::ReadComand(vector<string>& args)
{
	bool ret = true;

	if (args.size() > 0 && args[0].length() > 0)
		ret = ParseCommand(args);

	GameLoop();

	return ret;
}

void World::GameLoop()
{
	clock_t now = clock();

	//Clock every second
	if ((now - timer) / 500 > FRAME_RATE)
	{
		for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
			(*it)->Update();

		timer = now;
	}

}

bool World::ParseCommand(vector<string>& args)
{
	bool ret = true;

	switch (args.size())
	{
	default:
		break;
	}

	return ret;
}