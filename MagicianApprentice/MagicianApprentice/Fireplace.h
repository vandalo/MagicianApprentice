#ifndef __Fireplace__
#define __Fireplace__

#include <string>
#include <list>
#include "Item.h"

class Player;

class Fireplace : public Item
{

public:
	Fireplace(const char* name, const char* description, Entity* parent, Entity* must, bool fix, bool isOn);
	virtual void Look() const override;
	void Use(Player* player, const vector<string>& args);

public:
	bool used;

private:
	bool isOn;
};

#endif