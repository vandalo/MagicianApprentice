#ifndef __Ignite__
#define __Ignite__

#include <string>
#include <list>
#include "Entity.h"
#include "Spell.h"

class Ignite : public Spell
{

public:
	Ignite(const char* name, const char* description, Entity* parent, Entity* must, int mana, int cd, const char* nameSpell);
	void effect(Player* player);
};

#endif