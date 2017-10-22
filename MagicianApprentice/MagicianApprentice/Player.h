#ifndef __Player__
#define __Player__

#include <string>
#include <list>
#include "creature.h"
#include <vector>

class Room;
class Monster;

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Entity* parent);
	~Player();

	void Look(const vector<string>& args) const;
	void Stats(const vector<string>& args) const;
	void Go(const vector<string>& args);
	void Take(const vector<string>& args);
	Room* GetRoom() const;
	void Inventory(const vector<string>& args) const;
	void Open(const vector<string>& args);
	int GetHp();
	int GetMaxHp();
	bool Atack();
	unsigned int reciveAtack(unsigned int damage);
	void UseSpell(const vector<string>& args);

private:
	void Ignite();
	bool HaveSpell(const vector<string>& args);
	string GetSpellbookpageBySpell(const vector<string>& args);

private:
	unsigned int lvl = 0;
	unsigned int hp = 0;
	unsigned int maxHp = 0;
	unsigned int mana = 0;
};

#endif