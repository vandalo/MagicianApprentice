#include <iostream>
#include "Utils.h"
#include "Room.h"
#include "Spell.h"


Spell::Spell(const char* name, const char* description, Entity* parent, Entity* must, int mana, int cd, const char* nameSpell) :
	Item(name, description, parent, must, false), mana(mana), cd(cd), nameSpell(nameSpell)
{
	type = SPELL;
	cdTime = 0;
}

Spell::~Spell()
{}

void Spell::Look() const {
	cout << name << "\n";
	cout << description << "\n";
	cout << "It costs " << mana << " mana points.\n";
	cout << "It have 10 seconds of cooldown.\n";
}

bool Spell::Update()
{
	if (cdTime > 0)
	{
		cdTime--;
	}
	return false;
}
