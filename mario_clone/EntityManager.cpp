#include "EntityManager.h"

void EntityManager::update()
{
    for (auto& e : m_toAdd) {  
        m_entities.push_back(e);
        m_entityMap[e->id()].push_back(e);
    }
    m_toAdd.clear();
    removeDeadEntities(m_entities);
    for (auto& kv : m_entityMap) {
        removeDeadEntities(kv.second);
    }
}

std::shared_ptr<Entity> EntityManager::addEntity(eEntitiesType entities_type, eLevelEntities entities)
{
	auto entity = std::shared_ptr<Entity>(new Entity(entities_type , entities));
	m_toAdd.push_back(entity); 
	m_totalEntities++;
	return entity; 
}


EntityVec& EntityManager::getEntities()
{
	return m_entities; 
}

EntityVec& EntityManager::getEntities(eEntitiesType type)
{
	return m_entityMap[type];
}

void EntityManager::removeDeadEntities(EntityVec& vec)
{
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](std::shared_ptr<Entity>& e) {return !e->isAlive(); }), vec.end());
}
