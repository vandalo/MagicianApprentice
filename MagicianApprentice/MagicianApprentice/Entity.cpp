#include <iostream>
#include "Utils.h"
#include "Entity.h"

// ----------------------------------------------------
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
	cout << name << "\n";
	cout << description << "\n";
}

void Entity::Update()
{}