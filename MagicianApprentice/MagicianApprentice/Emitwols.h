#ifndef __Emitwols__
#define __Emitwols__

#include <string>
#include <list>
#include "Entity.h"
#include "Spell.h"

class Emitwols : public Spell
{

public:
	Emitwols(const char* name, const char* description, Entity* parent, Entity* must, int mana, int cd, const char* nameSpell);
	void effect(Player* player);


private:

};

#endif