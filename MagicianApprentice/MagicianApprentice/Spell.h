#ifndef __Spell__
#define __Spell__

#include <string>
#include <list>
#include "Entity.h"
#include "Item.h"

class Room;
class Player;

class Spell : public Item
{
public:
	Spell(const char* name, const char* description, Entity* parent, Entity* must, int mana, int cd, const char* nameSpell);
	~Spell();
	void Look() const;
	virtual void effect(Player* player) = 0;
	bool Update();

public:
	const char* nameSpell;
	unsigned int mana;
	unsigned int cd;
	unsigned int cdTime;

private:

	
};

#endif