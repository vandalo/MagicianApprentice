#ifndef __Tortolize__
#define __Tortolize__

#include <string>
#include <list>
#include "Entity.h"
#include "Spell.h"

class Tortolize : public Spell
{

public:
	Tortolize(const char* name, const char* description, Entity* parent, Entity* must, int mana, int cd, const char* nameSpell);
	void effect(Player* player);
};

#endif