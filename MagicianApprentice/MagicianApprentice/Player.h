#ifndef __Player__
#define __Player__

#include <string>
#include <list>
#include "creature.h"
#include <vector>

class Room;
class Monster;
class Spell;
class World;

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Entity* parent, World* myWorld);
	~Player();

	void Look(const vector<string>& args) const;
	void Stats() const;
	void Inventory(const vector<string>& args) const;

	void Go(const vector<string>& args);
	void Take(const vector<string>& args);
	
	bool Update() override;
	void UpdateMana(int mana);
	void UpdateHp(int hp);
	void UpdateShield(int shieldPoints);

	void Open(const vector<string>& args);
	unsigned int ReciveAtack(unsigned int damage);
	void UseSpell(const vector<string>& args);
	void Use(const vector<string>& args);
	void UseOn(const vector<string>& args);

	void CreateBookpage3() const;
	void CreateKey1() const;
	void CreateSecretExit() const;

private:
	Spell* HaveSpellAndMana(const vector<string>& args) const;

private:
	unsigned int shield = 0;
	World* myWorld = nullptr;
};

#endif