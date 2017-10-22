#include <iostream>
#include "Utils.h"
#include "Player.h"
#include "Exit.h"
#include "Room.h"
#include "Item.h"
#include "Monster.h"
#include <string>

Player::Player(const char* name, const char* description, Entity* parent) :
	Creature(name, description, parent)
{
	type = PLAYER;

	hp = 50;
	maxHp = 50;
	mana = 100;
	lvl = 1;

}

Player::~Player()
{}

int Player::GetHp()
{
	return hp;
}

int Player::GetMaxHp()
{
	return maxHp;
}

bool Player::Atack()
{
	return true;
}

unsigned int Player::reciveAtack(unsigned int damage)
{
	hp -= damage;
	return damage;
}

void Player::UseSpell(const vector<string>& args)
{
	if (HaveSpell(args))
	{
		if (Same(args[0], "ignite"))
		{
			{
				Ignite();
			}
		}
	}
	else
	{
		cout << "You have not learned this spell!\n";
	}
}

bool Player::HaveSpell(const vector<string>& args)
{
	bool ret = false;
	list<Entity*> items;
	FindByTypeAndPropietary(ITEM, items, (Entity*)this);
	string spellbookPageName = GetSpellbookpageBySpell(args);
	for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
	{
		Item* item = (Item*)(*it);

		if (item->container.size() > 0)
		{
			for (list<Entity*>::const_iterator it = item->container.begin(); it != item->container.cend(); ++it)
			{
				if (Same((*it)->name, spellbookPageName))
				{
					ret = true;
				}
			}
		}
	}
	return ret;
}

string Player::GetSpellbookpageBySpell(const vector<string>& args)
{
	string res = "";
	if (Same(args[0], "ignite"))
	{
		res = "Bookpage1";
	}
	else if (Same(args[0], "exura"))
	{
		res = "Bookpage2";
	}

	return res;
}

void Player::Ignite()
{
	Room* room = GetRoom();
	for (list<Entity*>::const_iterator it = room->container.begin(); it != room->container.cend(); ++it)
	{
		if ((*it)->type == MONSTER)
		{
			Monster* monster = (Monster*)(*it);
			if (monster->IsAlive() == true)
			{
				unsigned int damage = monster->reciveAtack(10);
				cout << "You deal " << damage << " damage to " << monster->name << ".\n";
				if (monster->IsAlive() == false)
				{
					cout << "You defeat the " << monster->name << ".\n";
				}
			}
			
		}
	}

}

Room* Player::GetRoom() const
{
	return (Room*)parent;
}

void Player::Look(const vector<string>& args) const
{
	if (args.size() > 1)
	{
		for (list<Entity*>::const_iterator it = parent->container.begin(); it != parent->container.cend(); ++it)
		{
			if (Same((*it)->name, args[1]))
			{
				if ((*it)->type == MONSTER)
				{
					Monster* monster = (Monster*)(*it);
					monster->Look();
				}
				else
				{
					(*it)->Look();
					
				}
				return;
			}
		}

		for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
		{
			if (Same((*it)->name, args[1]))
			{
				(*it)->Look();
				return;
			}
		}

		if (Same(args[1], "me"))
		{
			cout << name << "\n";
			cout << description << "\n";
		}
	}
	else
	{
		parent->Look();
	}
}

void Player::Stats(const vector<string>& args) const
{
	int lifePercent = hp * 100 / maxHp;

	cout << "You are level " << lvl << endl;

	if (lifePercent > 75)
	{
		cout << "You are healthy, ";
	}
	else if (lifePercent > 25)
	{
		cout << "You are hurt, ";
	}
	else
	{
		cout << "You are almost death, ";
	}

	cout << "you have " << hp << "/" << maxHp << " hit points" << endl;
	cout << "You have " << mana << " mana points" << endl;
}

void Player::Inventory(const vector<string>& args) const
{
	list<Entity*> items;
	FindByTypeAndPropietary(ITEM, items, (Entity*)this);

	for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
	{
		(*it)->Look();
	}
}

void Player::Open(const vector<string>& args)
{
	list<Entity*> exits;
	FindByTypeAndPropietary(EXIT, exits, GetRoom());

	for (list<Entity*>::const_iterator it = exits.begin(); it != exits.cend(); ++it)
	{
		Exit* exit = (Exit*)(*it);
		if (exit->name == args[1] || exit->GetDestination() == args[1])
		{
			exit->Open();
		}
	}
}

void Player::Go(const vector<string>& args)
{
	Exit* exit = GetRoom()->GetExitByName(args[1]);
	if (exit == nullptr) 
	{
		cout << "There aren't anything on " + (args[1]) + ".\n";
	}
	else
	{
		if (exit->closed == true)
		{
			cout << "You can't pass " + (args[1]) + " it's locked.\n";
		}
		else
		{
			ChangeParentTo(exit->GetDestinationByRoom(GetRoom()));
			parent->Look();
		}
		
	}
}

void Player::Take(const vector<string>& args)
{	
	Item* item = (Item*)GetItemByName(args[1]);

	if (item != nullptr)
	{
		cout << "You already have " + item->name + ".\n";
	}
	else
	{
		item = (Item*)GetRoom()->GetItemByName(args[1]);
		if (item == nullptr)
		{
			cout << "There aren't any item called " + (args[1]) + ".\n";
		}
		else if (item->fixed)
		{
			cout << "You can't take " + (args[1]) + ".\n";
		}
		else
		{
			if (item->must == nullptr)
			{
				item->ChangeParentTo(this);
				cout << "You added the " + item->name + " to your inventory.\n";
			}
			else
			{
				list<Entity*> items;
				FindByTypeAndPropietary(ITEM, items, (Entity*)this);
				bool find = false;
				for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
				{
					if ((*it)->name == item->must->name)
					{
						item->ChangeParentTo(*it);
						cout << "You added " + item->name + " to your " + (*it)->name + ".\n";
						find = true;
					}
				}
				if (find != true)
				{
					cout << "You can't take " + (args[1]) + ".\n";
				}
			}
		}
	}
}