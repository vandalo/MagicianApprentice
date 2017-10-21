#include <iostream>
#include "Utils.h"
#include "Entity.h"
#include "Defines.h"

Entity::Entity(const char* name, const char* description, Entity* parent = nullptr) :
	name(name), description(description), parent(parent)
{
	type = ENTITY;

	if (parent != nullptr)
		parent->container.push_back(this);
}

Entity::~Entity()
{}

void Entity::Look() const
{
	//cout << S_BOLD << name << E_BOLD << "\n";
	cout << description << "\n";
}

void Entity::ChangeParentTo(Entity* new_parent)
{
	if (parent != NULL)
		parent->container.remove(this);

	parent = new_parent;

	if (parent != NULL)
		parent->container.push_back(this);
}


void Entity::Update()
{}

void Entity::FindByTypeAndPropietary(EntityType type, list<Entity*>& entity_list, const Entity* propietari) const
{
	string propietari_name = propietari->name;
	for (list<Entity*>::const_iterator it = propietari->container.begin(); it != propietari->container.cend(); ++it)
	{
		if ((*it)->type == type)
		{
			if (propietari == nullptr)
			{
				entity_list.push_back(*it);
			}
			else if(Same(propietari_name, (*it)->parent->name))
			{
				entity_list.push_back(*it);
			}
		}
		
	}
}

Entity * Entity::GetItemByName(const string item_name)
{
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it)
	{
		if ((*it)->type == ITEM) {
			Entity* entity = (Entity*)*it;
			if (Same(entity->name, item_name))
			{
				return entity;
			}
		}
	}
	return nullptr;
}
