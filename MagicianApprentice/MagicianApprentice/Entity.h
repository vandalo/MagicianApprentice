#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	PLAYER,
	EXIT,
	ITEM,
	CREATURE,
	MONSTER,
	SPELL
};

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);
	virtual ~Entity();

	virtual void Look() const;
	virtual void ChangeParentTo(Entity* new_parent);
	virtual bool Update();
	virtual void FindByTypeAndPropietary(EntityType type, list<Entity*>&entity_list, const Entity* propietari) const;
	virtual Entity* GetItemByName(const string item_name) const;

public:
	EntityType type;
	string name;
	string description;

	Entity* parent;
	list<Entity*> container;
};

#endif