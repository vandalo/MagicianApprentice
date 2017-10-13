#ifndef __Player__
#define __Player__

#include <string>
#include <list>
#include "entity.h"

class Room;

using namespace std;


class Player : public Entity
{
public:
	Player(const char* name, const char* description, Entity* parent);
	~Player();

	void Look(const vector<string>& args) const;
	void Stats(const vector<string>& args) const;
	void Go(const vector<string>& args);
	Room* GetRoom() const;

private:
	unsigned int lvl = 0;
	unsigned int hp = 0;
	unsigned int maxHp = 0;
	unsigned int mana = 0;
};

#endif