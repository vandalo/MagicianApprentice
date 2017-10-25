#ifndef __Exura__
#define __Exura__

#include <string>
#include <list>
#include "Entity.h"
#include "Spell.h"

class Exura : public Spell
{

public:
	Exura(const char* name, const char* description, Entity* parent, Entity* must, int mana, int cd, const char* nameSpell);
	void effect(Player* player);


private:

};

#endif