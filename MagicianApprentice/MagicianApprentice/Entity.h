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
	ITEM
};

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);
	virtual ~Entity();

	virtual void Look() const;
	virtual void ChangeParentTo(Entity* new_parent);
	virtual void Update();
	virtual void FindByTypeAndPropietary(EntityType type, list<Entity*>&entity_list, const Entity* propietari) const;

public:
	EntityType type;
	std::string name;
	std::string description;

	Entity* parent;
	list<Entity*> container;
};

#endif