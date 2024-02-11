#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "EntityManager.h"
#include "Assets.h"
#include "Map.h"
#include "Animation.h"



struct PlayerConfig
{
	float jumpHeight = 450.f;
	float movespeed = 6.f;
	float jumpspeed = -25.f;
};

struct GoombaConfig
{
	float movespeed = 2.5f;
};

class Game
{
	sf::RenderWindow m_window; 
	EntityManager m_manager; 
	Map m_map; 
	PlayerConfig m_pCFG;
	GoombaConfig m_gooCFG;
	float m_BulletSpeed = 15.f;
	int m_coinScore = 0;
	std::shared_ptr<Entity> m_player; 
	bool m_running = true; 
	sf::View m_view_x;
	Assets m_assets;
	bool drawGrid = false; 
	void loadLevel(const Map &level); 
	void sMovement(); 
	void sUserInput(); 
	void sCollision(); 
	void sAnimation();
	void sRender(); 
	void SpawnPlayer(const Map &level);  
	void SpawnBullet();
public:
	Game(); 
	void run(); 


};