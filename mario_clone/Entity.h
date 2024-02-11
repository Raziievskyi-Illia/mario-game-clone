#pragma once
#include "Components.h"
#include <memory>
#include <tuple>

enum eLevelEntities {
	PLAYER,
	BRICK,
	CLOUDBIG,
	GROUND,
	BUSHBIG,
	QUESTION,
	BUSHSMALL,
	FLAGPOLE,
	PIPESMALL,
	BLOCK,
	BUSH,
	COIN,
	CLOUDSMALL,
	BULLET,
	SMALLBUSH,
	PIPE,
	BUSHER,
	GOOMBA,
	CASTLE
};

enum eEntitiesType {
	DYNAMIC,
	TILE,
	DEC, 
	ITEM, 
	PROJECTILE
};

typedef std::tuple<CTransform,CInput,CAnimation,CState> ComponentsTuple;

class Entity
{
private:
	ComponentsTuple m_components = std::make_tuple(CTransform(),CInput(),CAnimation() ,CState());
	eEntitiesType m_id;
	eLevelEntities m_tag;
	bool m_alive = true; 
	Entity(eEntitiesType& id, eLevelEntities& entityTag);
	Entity() = default;
	friend class EntityManager;
public:
	
	eEntitiesType id() const;
	bool isAlive(); 
	void destroy(); 
	eLevelEntities tag() const;

	template<typename T>
	bool hasComponent() {
		return getComponent<T>().has;
	}

	template<typename T, typename... TArgs>
	T& addComponents(TArgs &&...mArgs) {
		auto& component = getComponent<T>();
		component = T(std::forward<TArgs>(mArgs)...);
		component.has = true;
		return component;
	}

	template<typename T>
	T& getComponent() { return std::get<T>(m_components); }

	template<typename T>
	void removeComponent() { getComponent<T>() = T(); }
};