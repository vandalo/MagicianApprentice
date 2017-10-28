#ifndef __Spell__
#define __Spell__

#include <string>
#include <list>
//#include "Entity.h"
#include "Item.h"

class Room;
class Player;

class Spell : public Item
{
public:
	Spell(const char* name, const char* description, Entity* parent, Entity* must, int mana, int cd, const char* nameSpell);
	~Spell();
	virtual void Look() const;
	virtual void effect(Player* player) = 0;
	virtual bool Update();

public:
	const char* nameSpell = nullptr;
	unsigned int mana = 0;
	unsigned int cd = 0;
	unsigned int cdTime = 0;

private:

	
};

#endif