#ifndef __GiantSpider__
#define __GiantSpider__

#include <string>
#include <list>
#include "Monster.h"
#include <vector>

class Room;

class GiantSpider : public Monster
{
public:
	GiantSpider(const char* name, const char* description, Entity* parent);
	~GiantSpider();

	//void Look() const;
	//void Stats(const vector<string>& args) const;
	Room* GetRoom() const;
	int GetHp();
	int GetMaxHp();
	bool Atack();
	bool Update();

private:
	/*unsigned int lvl = 0;
	unsigned int hp = 0;
	unsigned int maxHp = 0;
	unsigned int mana = 0;*/
	unsigned int atack = 0;
	unsigned int cooldown = 0;
	unsigned int maxCooldown = 0;
};

#endif