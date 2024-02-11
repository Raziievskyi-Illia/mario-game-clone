#include "Entity.h"


bool Entity::isAlive()
{
	return this->m_alive; 
}

void Entity::destroy()
{
	this->m_alive = false; 
}

Entity::Entity(eEntitiesType& id, eLevelEntities& entityTag)
	: m_tag(entityTag), m_id(id) {
}

eEntitiesType Entity::id() const {
	return m_id;
}

eLevelEntities Entity::tag() const {
	return m_tag;
}