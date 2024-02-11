#pragma once
#include "Entity.h"


typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map < eEntitiesType, EntityVec> EntityMap; 



class EntityManager
{
	EntityVec m_entities; 
	EntityVec m_toAdd; 
	EntityMap m_entityMap; 
	size_t m_totalEntities = 0; 
public:
	EntityManager() = default; 
	void update(); 
	std::shared_ptr<Entity> addEntity(eEntitiesType entities_type, eLevelEntities entities);
	EntityVec& getEntities(); 
	EntityVec& getEntities(eEntitiesType type);
	void removeDeadEntities(EntityVec& vec); 
};
