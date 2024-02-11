#include "Game.h"
// #define DEBUG
void Game::loadLevel(const Map& level)
{
	for (size_t i = 0; i < level.BusherCoord.size(); i++)
	{
		auto Busher = m_manager.addEntity(eEntitiesType::DEC, eLevelEntities::BUSHER);
		Busher->addComponents<CAnimation>(Animation(eAnimationTypes::NoAni, m_assets.getTexture(eTextureTypes::marioSMALLBUSH)), true);
		Busher->addComponents<CTransform>(getMidCoord(level.grid[level.BusherCoord[i].first][level.BusherCoord[i].second] , Busher->getComponent<CAnimation>().animation.getSprite()), Vec2(0.f, 0.f), 0.f);
	}
	for (size_t i = 0; i < level.SCloudCoord.size(); i++)
	{
		auto SCloud = m_manager.addEntity(eEntitiesType::DEC, eLevelEntities::CLOUDSMALL);
		SCloud->addComponents<CAnimation>(Animation(eAnimationTypes::NoAni, m_assets.getTexture(eTextureTypes::marioSCLOUD)), true);
		SCloud->addComponents<CTransform>(Vec2(level.grid[level.SCloudCoord[i].first][level.SCloudCoord[i].second].getPosition().x, level.grid[level.SCloudCoord[i].first][level.SCloudCoord[i].second].getPosition().y), Vec2(0.f, 0.f), 0.f);
	}
	for (size_t i = 0; i < level.BCloudCoord.size(); i++)
	{
		auto BCloud = m_manager.addEntity(eEntitiesType::DEC, eLevelEntities::CLOUDBIG);
		BCloud->addComponents<CAnimation>(Animation(eAnimationTypes::NoAni, m_assets.getTexture(eTextureTypes::marioBCLOUD)), true);
		BCloud->addComponents<CTransform>(Vec2(level.grid[level.BCloudCoord[i].first][level.BCloudCoord[i].second].getPosition().x, level.grid[level.BCloudCoord[i].first][level.BCloudCoord[i].second].getPosition().y), Vec2(0.f, 0.f), 0.f);
	}
	for (size_t i = 0; i < level.BushCoord.size(); i++)
	{
		auto Bush = m_manager.addEntity(eEntitiesType::DEC, eLevelEntities::BUSHBIG);
		Bush->addComponents<CAnimation>(Animation(eAnimationTypes::NoAni, m_assets.getTexture(eTextureTypes::marioBUSH)), true);
		Bush->addComponents<CTransform>(getMidCoord(level.grid[level.BushCoord[i].first][level.BushCoord[i].second], Bush->getComponent<CAnimation>().animation.getSprite()), Vec2(0.f, 0.f), 0.f);
	}
	for (size_t i = 0; i < level.groundCoord.size(); i++)
	{
		auto ground = m_manager.addEntity(eEntitiesType::TILE, eLevelEntities::GROUND);
		ground->addComponents<CAnimation>(Animation(eAnimationTypes::NoAni, m_assets.getTexture(eTextureTypes::marioGround)), true);
		ground->addComponents<CTransform>(Vec2(level.grid[level.groundCoord[i].first][level.groundCoord[i].second].getPosition().x, level.grid[level.groundCoord[i].first][level.groundCoord[i].second].getPosition().y), Vec2(0.f, 0.f), 0.f);
	}
	for (size_t i = 0; i < level.brickCoord.size(); i++)
	{
		auto brick = m_manager.addEntity(eEntitiesType::TILE, eLevelEntities::BRICK);
		brick->addComponents<CAnimation>(Animation(eAnimationTypes::NoAni, m_assets.getTexture(eTextureTypes::marioBRICK)), true);
		brick->addComponents<CTransform>(Vec2(level.grid[level.brickCoord[i].first][level.brickCoord[i].second].getPosition().x, level.grid[level.brickCoord[i].first][level.brickCoord[i].second].getPosition().y), Vec2(0.f, 0.f), 0.f);
	}
	for (size_t i = 0; i < level.QBlockCoord.size(); i++)
	{
		auto QBlock = m_manager.addEntity(eEntitiesType::TILE, eLevelEntities::QUESTION);
		QBlock->addComponents<CAnimation>(Animation(eAnimationTypes::AniBRICK, m_assets.getTexture(eTextureTypes::marioQBlock), 4, 10), true);
		QBlock->addComponents<CTransform>(Vec2(level.grid[level.QBlockCoord[i].first][level.QBlockCoord[i].second].getPosition().x, level.grid[level.QBlockCoord[i].first][level.QBlockCoord[i].second].getPosition().y), Vec2(0.f, 0.f), 0.f);
		QBlock->addComponents<CState>();
	}
	
	for (size_t i = 0; i < level.PipeCoord.size(); i++)
	{
		auto pipe = m_manager.addEntity(eEntitiesType::TILE, eLevelEntities::PIPESMALL);
		pipe->addComponents<CAnimation>(Animation(eAnimationTypes::NoAni, m_assets.getTexture(eTextureTypes::marioPIPE)), true);
		pipe->addComponents<CTransform>(getMidCoord(level.grid[level.PipeCoord[i].first][level.PipeCoord[i].second], pipe->getComponent<CAnimation>().animation.getSprite()), Vec2(0.f, 0.f), 0.f);
	}
	for (size_t i = 0; i < level.TallPipeCoord.size(); i++)
	{
		auto TallPipe = m_manager.addEntity(eEntitiesType::TILE, eLevelEntities::PIPE);
		TallPipe->addComponents<CAnimation>(Animation(eAnimationTypes::NoAni, m_assets.getTexture(eTextureTypes::marioTallPIPE)), true);
		TallPipe->addComponents<CTransform>(getMidCoord(level.grid[level.TallPipeCoord[i].first][level.TallPipeCoord[i].second], TallPipe->getComponent<CAnimation>().animation.getSprite()), Vec2(0.f, 0.f), 0.f);
	}
	for (size_t i = 0; i < level.CoinCoord.size(); i++)
	{
		auto coin = m_manager.addEntity(eEntitiesType::ITEM, eLevelEntities::COIN);
		coin->addComponents<CAnimation>(m_assets.getAnimation(eAnimationTypes::aniCOIN), true);
		coin->addComponents<CTransform>(Vec2(level.grid[level.CoinCoord[i].first][level.CoinCoord[i].second].getPosition().x, level.grid[level.CoinCoord[i].first][level.CoinCoord[i].second].getPosition().y), Vec2(0.f, 0.f), 0.f);
	}
	
	auto Castle = m_manager.addEntity(eEntitiesType::DEC, eLevelEntities::CASTLE);
	Castle->addComponents<CAnimation>(Animation(eAnimationTypes::NoAni, m_assets.getTexture(eTextureTypes::marioCASTLE)) , true);
	Castle->addComponents<CTransform>(getMidCoord(level.grid[level.castleCoord.first][level.castleCoord.second], Castle->getComponent<CAnimation>().animation.getSprite()), Vec2(0.f, 0.f), 0.f);

	auto flag = m_manager.addEntity(eEntitiesType::DEC, eLevelEntities::FLAGPOLE);
	flag->addComponents<CAnimation>(Animation(eAnimationTypes::NoAni, m_assets.getTexture(eTextureTypes::marioFLAG)), true);
	flag->addComponents<CTransform>(getMidCoord(level.grid[level.flagCoorg.first][level.flagCoorg.second], flag->getComponent<CAnimation>().animation.getSprite()), Vec2(0.f, 0.f), 0.f);




	for (size_t i = 0; i < level.GoombaCoord.size(); i++)
	{
		auto Goo = m_manager.addEntity(eEntitiesType::DYNAMIC, eLevelEntities::GOOMBA);
		Goo->addComponents<CAnimation>(m_assets.getAnimation(eAnimationTypes::aniGOOMBA), true);
		Goo->addComponents<CTransform>(getMidCoord(level.grid[level.GoombaCoord[i].first][level.GoombaCoord[i].second], Goo->getComponent<CAnimation>().animation.getSprite()), Vec2(-2.5f, 0.f), 10.f, -1.f);
		Goo->addComponents<CState>();
		Goo->getComponent<CState>().canJump = true;
	}

}

void Game::sMovement()
{
	for (auto& dynamic : m_manager.getEntities(eEntitiesType::DYNAMIC))
	{
		dynamic->getComponent<CTransform>().velocity = Vec2(0.f, 0.f);
		if (dynamic->tag() == eLevelEntities::GOOMBA && dynamic->getComponent<CState>().canMove)
		{
				dynamic->getComponent<CTransform>().velocity.x = m_gooCFG.movespeed * dynamic->getComponent<CTransform>().xScale;
		}
	}
	
	static float currentHeight = m_pCFG.jumpHeight;

	
	if (!m_player->getComponent<CInput>().left && !m_player->getComponent<CInput>().right &&
		!m_player->getComponent<CInput>().up && !m_player->getComponent<CInput>().down && m_player->getComponent<CState>().canJump)
	{
		m_player->getComponent<CState>().running = false;
		m_player->addComponents<CAnimation>(Animation(eAnimationTypes::STAND, m_assets.getTexture(eTextureTypes::megaSTAND)), true);
	}


	if (m_player->getComponent<CInput>().right && m_player->getComponent<CState>().canShoot)
	{	
		m_player->getComponent<CTransform>().xScale = 1;
		if (m_player->getComponent<CState>().canJump && !m_player->getComponent<CState>().running) {
			m_player->getComponent<CState>().running = true;
			m_player->addComponents<CAnimation>(m_assets.getAnimation(eAnimationTypes::RUN), true);
	
		}
		m_player->getComponent<CTransform>().velocity.x = m_pCFG.movespeed;	
	}

	if (m_player->getComponent<CInput>().left && m_player->getComponent<CState>().canShoot)
	{	
		m_player->getComponent<CTransform>().xScale = -1;
		if (m_player->getComponent<CState>().canJump && !m_player->getComponent<CState>().running) {
			m_player->getComponent<CState>().running = true;
			m_player->addComponents<CAnimation>(m_assets.getAnimation(eAnimationTypes::RUN), true);
		}
		m_player->getComponent<CTransform>().velocity.x = -m_pCFG.movespeed;
	}

	if (m_player->getComponent<CInput>().up && m_player->getComponent<CState>().canJump && m_player->getComponent<CState>().canShoot)
	{
		m_player->getComponent<CState>().isJumping = true;
		currentHeight = m_pCFG.jumpHeight;
	}


	if (m_player->getComponent<CState>().isJumping && currentHeight > 0)
	{
		m_player->addComponents<CAnimation>(m_assets.getAnimation(eAnimationTypes::JUMP), true);
		m_player->getComponent<CTransform>().velocity.y = m_pCFG.jumpspeed;
		currentHeight += m_pCFG.jumpspeed;
		m_player->getComponent<CState>().running = false;
	}
	

	if (m_player->getComponent<CInput>().left && m_player->getComponent<CInput>().right && m_player->getComponent<CState>().canJump)
	{
		m_player->getComponent<CState>().running = false;
		m_player->addComponents<CAnimation>(Animation(eAnimationTypes::STAND, m_assets.getTexture(eTextureTypes::megaSTAND)), true);
		m_player->getComponent<CTransform>().velocity.x = 0;
	}

	if (!m_player->getComponent<CState>().canJump && m_player->getComponent<CState>().running && !m_player->getComponent<CState>().isJumping) {
		m_player->addComponents<CAnimation>(m_assets.getAnimation(eAnimationTypes::JUMP), true);
		m_player->getComponent<CState>().running = false;
	}

	if (!m_player->getComponent<CState>().canShoot)
	{
		m_player->addComponents<CAnimation>(m_assets.getAnimation(eAnimationTypes::SHOT), true);
		m_player->getComponent<CTransform>().velocity.x = 0;
	}

	m_player->getComponent<CAnimation>().animation.getSprite().setScale(m_player->getComponent<CTransform>().xScale, 1.f);
	
	for (auto& ent : m_manager.getEntities(eEntitiesType::DYNAMIC))
	{
		if (!ent->getComponent<CState>().canJump)
			ent->getComponent<CTransform>().velocity.y += ent->getComponent<CTransform>().gravity;
		ent->getComponent<CTransform>().pos += ent->getComponent<CTransform>().velocity;
	}
	for (auto& proj : m_manager.getEntities(eEntitiesType::PROJECTILE))
	{
		proj->getComponent<CTransform>().pos += proj->getComponent<CTransform>().velocity;
	}
}

void Game::sUserInput()
{
	
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
			{
				m_running = false;
				break;
			}
			case sf::Keyboard::A:
			{
#ifdef DEBUG
				std::cout << "A key pressed\n";
#endif // DEBUG
				m_player->getComponent<CInput>().left = true;
				break;
			}
			case sf::Keyboard::D:
			{

#ifdef DEBUG
				std::cout << "D key pressed\n";
#endif // DEBUG
				m_player->getComponent<CInput>().right = true;
				break;
			}
			case sf::Keyboard::W:
			{
				m_player->getComponent<CInput>().up = true;
				break;
			}
			case sf::Keyboard::S:
			{
				m_player->getComponent<CInput>().down = true;
				break;
			}
			case sf::Keyboard::G:
			{
				!drawGrid ? drawGrid = true : drawGrid = false;
				break;
			}
			case sf::Keyboard::Space:
			{
				if (m_player->getComponent<CState>().canShoot && m_player->getComponent<CState>().canJump) {
					SpawnBullet();
					m_player->getComponent<CState>().canShoot = false;
				}
				break;
			}
			default:break;
			}
			break;
		}
		case sf::Event::KeyReleased:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
			{
				m_player->getComponent<CInput>().up = false;
				break;
			}
			case sf::Keyboard::A:
			{
				m_player->getComponent<CInput>().left = false;
				break;
			}
			case sf::Keyboard::D:
			{
				m_player->getComponent<CInput>().right = false;
				break;
			}
			case sf::Keyboard::S:
			{
				m_player->getComponent<CInput>().down = false;
				break;
			}
			case sf::Keyboard::Space:
			{
				m_player->getComponent<CState>().canShoot = true;
				break;
			}
			default:break;
			}
			break;
		}
		}
	}
}

void Game::sCollision()
{
	for (auto& dynamic : m_manager.getEntities(eEntitiesType::DYNAMIC)) { dynamic->getComponent<CState>().CollisionDetected = false; }
	for (auto& dynamic : m_manager.getEntities(eEntitiesType::DYNAMIC)) {
		for (auto& tile : m_manager.getEntities(eEntitiesType::TILE))
		{
			switch (dynamic->tag())
			{
			case eLevelEntities::PLAYER:
			{
				float dx = std::abs(tile->getComponent<CTransform>().pos.x - m_player->getComponent<CTransform>().pos.x);
				float dy = std::abs(tile->getComponent<CTransform>().pos.y - m_player->getComponent<CTransform>().pos.y);
				if (m_player->getComponent<CAnimation>().animation.getSize().x / 2 + tile->getComponent<CAnimation>().animation.getSize().x / 2 >= dx &&
					m_player->getComponent<CAnimation>().animation.getSize().y / 2 + tile->getComponent<CAnimation>().animation.getSize().y / 2 >= dy)
				{
					float diffX = m_player->getComponent<CTransform>().pos.x - tile->getComponent<CTransform>().pos.x;
					float diffY = m_player->getComponent<CTransform>().pos.y - tile->getComponent<CTransform>().pos.y;
					float overlapX = m_player->getComponent<CAnimation>().animation.getSize().x / 2 + tile->getComponent<CAnimation>().animation.getSize().x / 2 - std::abs(diffX);
					float overlapY = m_player->getComponent<CAnimation>().animation.getSize().y / 2 + tile->getComponent<CAnimation>().animation.getSize().y / 2 - std::abs(diffY);
					if (std::abs(overlapX) < std::abs(overlapY)) {
						if (diffX > 0)
							m_player->getComponent<CTransform>().pos.x += overlapX;
						else
							m_player->getComponent<CTransform>().pos.x -= overlapX;
					}
					else 
					{
						if (diffY > 0)
						{
							m_player->getComponent<CTransform>().pos.y += overlapY;
							m_player->getComponent<CState>().isJumping = false;
							if (tile->tag() == eLevelEntities::QUESTION)
							{
								if (tile->getComponent<CState>().active) {
									auto coin = m_manager.addEntity(eEntitiesType::ITEM, eLevelEntities::COIN);
									coin->addComponents<CAnimation>(m_assets.getAnimation(eAnimationTypes::aniCOIN), true);
									coin->addComponents<CTransform>(Vec2(tile->getComponent<CTransform>().pos.x, tile->getComponent<CTransform>().pos.y - m_map.gridSize), Vec2(0.f, 0.f), 0.f);
									tile->getComponent<CState>().active = false;

									tile->addComponents<CAnimation>(Animation(eAnimationTypes::NoAni, m_assets.getTexture(eTextureTypes::marioUNACQBlock)), true);
								}
							}
						}
						else
						{
							m_player->getComponent<CState>().CollisionDetected = true;
							m_player->getComponent<CState>().isJumping = false;
							m_player->getComponent<CState>().canJump = true;
							//std::cout << m_player->getComponent<CState>().canJump << std::endl;
							m_player->getComponent<CTransform>().pos.y -= overlapY;
						}
					}
				}
				break;
			}
			case eLevelEntities::GOOMBA:
			{
				float dx = std::abs(tile->getComponent<CTransform>().pos.x - dynamic->getComponent<CTransform>().pos.x);
				float dy = std::abs(tile->getComponent<CTransform>().pos.y - dynamic->getComponent<CTransform>().pos.y);
				if (dynamic->getComponent<CAnimation>().animation.getSize().x / 2 + tile->getComponent<CAnimation>().animation.getSize().x / 2 >= dx &&
					dynamic->getComponent<CAnimation>().animation.getSize().y / 2 + tile->getComponent<CAnimation>().animation.getSize().y / 2 >= dy)
				{
					float diffX = dynamic->getComponent<CTransform>().pos.x - tile->getComponent<CTransform>().pos.x;
					float diffY = dynamic->getComponent<CTransform>().pos.y - tile->getComponent<CTransform>().pos.y;
					float overlapX = dynamic->getComponent<CAnimation>().animation.getSize().x / 2 + tile->getComponent<CAnimation>().animation.getSize().x / 2 - std::abs(diffX);
					float overlapY = dynamic->getComponent<CAnimation>().animation.getSize().y / 2 + tile->getComponent<CAnimation>().animation.getSize().y / 2 - std::abs(diffY);
					if (std::abs(overlapX) < std::abs(overlapY)) {
						if (diffX > 0) {
							dynamic->getComponent<CTransform>().pos.x += overlapX;
							dynamic->getComponent<CTransform>().xScale = 1;
							std::cout << "WALL HIT" << std::endl;
						}
						else {
							dynamic->getComponent<CTransform>().xScale = -1;
							dynamic->getComponent<CTransform>().pos.x -= overlapX;
						}
					}
					else
					{
						if (diffY > 0)
						{
							dynamic->getComponent<CTransform>().pos.y += overlapY;
						}
						else
						{
							dynamic->getComponent<CState>().CollisionDetected = true;
						//	dynamic->getComponent<CState>().isJumping = false;
							dynamic->getComponent<CState>().canJump = true;
							dynamic->getComponent<CTransform>().pos.y -= overlapY;
						}
					}
				}
				break;
			}
			default:
				break;
			}
		}
	}

	for (auto& dynamic : m_manager.getEntities(eEntitiesType::DYNAMIC))
	{
		switch (dynamic->tag())
		{
		case eLevelEntities::GOOMBA:
		{
			float dx = std::abs(m_player->getComponent<CTransform>().pos.x - dynamic->getComponent<CTransform>().pos.x);
			float dy = std::abs(m_player->getComponent<CTransform>().pos.y - dynamic->getComponent<CTransform>().pos.y);
			if (dynamic->getComponent<CAnimation>().animation.getSize().x / 2 + m_player->getComponent<CAnimation>().animation.getSize().x / 2 >= dx &&
				dynamic->getComponent<CAnimation>().animation.getSize().y / 2 + m_player->getComponent<CAnimation>().animation.getSize().y / 2 >= dy)
			{
				float diffX = dynamic->getComponent<CTransform>().pos.x - m_player->getComponent<CTransform>().pos.x;
				float diffY = dynamic->getComponent<CTransform>().pos.y - m_player->getComponent<CTransform>().pos.y;
				float overlapX = dynamic->getComponent<CAnimation>().animation.getSize().x / 2 + m_player->getComponent<CAnimation>().animation.getSize().x / 2 - std::abs(diffX);
				float overlapY = dynamic->getComponent<CAnimation>().animation.getSize().y / 2 + m_player->getComponent<CAnimation>().animation.getSize().y / 2 - std::abs(diffY);
				if (std::abs(overlapX) < std::abs(overlapY)) {
					if (m_player->getComponent<CTransform>().velocity.y > 0)
					{
						dynamic->addComponents<CAnimation>(m_assets.getAnimation(eAnimationTypes::aniGOODEATH), false);
						dynamic->getComponent<CTransform>().xScale = 0;
					}
					else {
						for (auto& ent : m_manager.getEntities())
						{
							ent->destroy();	
						}
						m_coinScore = 0;
						loadLevel(m_map);
						SpawnPlayer(m_map);
					}
				}
				else
				{
					if (diffY > 0)
					{
						dynamic->getComponent<CTransform>().xScale = 0;
						dynamic->addComponents<CAnimation>(m_assets.getAnimation(eAnimationTypes::aniGOODEATH), false);
						m_player->getComponent<CState>().CollisionDetected = true;
						m_player->getComponent<CState>().isJumping = false;
						m_player->getComponent<CState>().canJump = true;
						m_player->getComponent<CInput>().up = true;
					
					}
					else
					{
						for (auto& ent : m_manager.getEntities())
						{
								ent->destroy();
						}
						m_coinScore = 0;
						loadLevel(m_map);
						SpawnPlayer(m_map);
					}
				}
			}
			break;
		}
		default:
			break;
		}
	}

	for (auto& item : m_manager.getEntities(eEntitiesType::ITEM))
	{
		switch (item->tag())
		{
		case eLevelEntities::COIN:
		{
			const float& Iwidth = item->getComponent<CAnimation>().animation.getSprite().getTextureRect().width;
			const float& Iheight = item->getComponent<CAnimation>().animation.getSprite().getTextureRect().height;
			float radiusItem = std::sqrtf(Iwidth * Iwidth + Iheight * Iheight) / 2.f;

			const float& Pwidth = m_player->getComponent<CAnimation>().animation.getSprite().getTextureRect().width;
			const float& Pheight = m_player->getComponent<CAnimation>().animation.getSprite().getTextureRect().height;
			float radiusPlayer = std::sqrtf(Pwidth * Pwidth + Pheight * Pheight) / 2.f;

			Vec2 D(item->getComponent<CTransform>().pos - m_player->getComponent<CTransform>().pos);
		
			if ((D.x * D.x + D.y * D.y) <= ((radiusPlayer + radiusItem) * (radiusPlayer + radiusItem)) / 4.f) {
				item->destroy();
				++m_coinScore;
			}
			break;
		}
		default:
			break;
		}
	}

	for (auto& projectile : m_manager.getEntities(eEntitiesType::PROJECTILE))
	{
		switch (projectile->tag())
		{
		case eLevelEntities::BULLET:
		{
			for (auto& dynamic : m_manager.getEntities(eEntitiesType::DYNAMIC))
			{
				switch (dynamic->tag())
				{
				case eLevelEntities::GOOMBA:
				{
					const float& Pwidth = projectile->getComponent<CAnimation>().animation.getSprite().getTextureRect().width;
					const float& Pheight = projectile->getComponent<CAnimation>().animation.getSprite().getTextureRect().height;
					float radiusProj = std::sqrtf(Pwidth * Pwidth + Pheight * Pheight) / 2.f;

					const float& Dwidth = dynamic->getComponent<CAnimation>().animation.getSprite().getTextureRect().width;
					const float& Dheight = dynamic->getComponent<CAnimation>().animation.getSprite().getTextureRect().height;
					float radiusDynamic = std::sqrtf(Dwidth * Dwidth + Dheight * Dheight) / 2.f;

					Vec2 D(projectile->getComponent<CTransform>().pos - dynamic->getComponent<CTransform>().pos);

					if ((D.x * D.x + D.y * D.y) <= ((radiusDynamic + radiusProj) * (radiusDynamic + radiusProj)) /4.f) {
						projectile->destroy();
						dynamic->getComponent<CTransform>().xScale = 0;
						dynamic->addComponents<CAnimation>(m_assets.getAnimation(eAnimationTypes::aniGOODEATH), false);
					}
					break;
				}
				default:
					break;
				}
			}
			for (auto& tile : m_manager.getEntities(eEntitiesType::TILE))
			{
				const float& Pwidth = projectile->getComponent<CAnimation>().animation.getSprite().getTextureRect().width;
				const float& Pheight = projectile->getComponent<CAnimation>().animation.getSprite().getTextureRect().height;
				float radiusProj = std::sqrtf(Pwidth * Pwidth + Pheight * Pheight) / 2.f;

				const float& Twidth = tile->getComponent<CAnimation>().animation.getSprite().getTextureRect().width;
				const float& Theight = tile->getComponent<CAnimation>().animation.getSprite().getTextureRect().height;
				float radiusTile = std::sqrtf(Twidth * Twidth + Theight * Theight) / 2.f;

				Vec2 D(projectile->getComponent<CTransform>().pos - tile->getComponent<CTransform>().pos);

				if ((D.x * D.x + D.y * D.y) <= ((radiusTile + radiusProj) * (radiusTile + radiusProj))/1.5) {
					projectile->destroy();
					if(tile->getComponent<CTransform>().pos.x == m_map.grid[36][10].getPosition().x && tile->getComponent<CTransform>().pos.y == m_map.grid[36][10].getPosition().y)
					{
						tile->addComponents<CAnimation>(m_assets.getAnimation(eAnimationTypes::EXPLOSION), false);
					}
				}
			}
			break;
		}
		default:
			break;
		}
	}

	for (auto& dynamic : m_manager.getEntities(eEntitiesType::DYNAMIC))
	{

		switch (dynamic->tag())
		{
		case eLevelEntities::PLAYER:
		{
			if (!dynamic->getComponent<CState>().CollisionDetected) {
				dynamic->getComponent<CState>().canJump = false;
				dynamic->getComponent<CInput>().up = false;
			}
			break;
		}
		case eLevelEntities::GOOMBA:
		{
			if (!dynamic->getComponent<CState>().CollisionDetected) {
				dynamic->getComponent<CState>().canJump = false;
			}
			if (std::abs(m_player->getComponent<CTransform>().pos.x - dynamic->getComponent<CTransform>().pos.x) < m_window.getSize().x / 2.f + 150.f)
				dynamic->getComponent<CState>().canMove = true;
			break;
		}
		default:
			break;
		}

		
	}

	if (m_player->getComponent<CTransform>().pos.y > m_map.gridY * m_map.gridSize)
	{
		for (auto& ent : m_manager.getEntities())
		{
				ent->destroy();
		}
		m_coinScore = 0;
		loadLevel(m_map);
		SpawnPlayer(m_map);
	}

	if (m_player->getComponent<CTransform>().pos.x >=  m_map.grid[m_map.castleCoord.first][m_map.castleCoord.second].getPosition().x + 140)
	{
		m_running = false;
	}
}


void Game::sAnimation() {

	for (auto& e : m_manager.getEntities()) {
		if (e->hasComponent<CAnimation>()) {
			e->getComponent<CAnimation>().animation.update();
			if (e->getComponent<CAnimation>().animation.hasEnded() && !e->getComponent<CAnimation>().repeat)
				e->destroy();
		}
	}
}






void Game::sRender()
{
	m_window.clear(sf::Color(100, 150, 250));
	
	// grid
	if (drawGrid) {
		for (int x = 0; x < m_map.gridX; x++)
		{
			for (int y = 0; y < m_map.gridY; y++)
			{
				m_window.draw(m_map.grid[x][y]);
				m_map.text.setString(std::to_string(x) + " , " + std::to_string(y));
				m_map.text.setPosition(m_map.grid[x][y].getPosition() - sf::Vector2f(m_map.gridSize / 2, m_map.gridSize / 2));
				m_window.draw(m_map.text);
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////
	for ( auto& ent : m_manager.getEntities())
	{
		ent->getComponent<CAnimation>().animation.getSprite().setPosition(ent->getComponent<CTransform>().pos.x, ent->getComponent<CTransform>().pos.y);
		m_window.draw(ent->getComponent<CAnimation>().animation.getSprite());
	}
	if (m_manager.getEntities().empty())
	{
		std::cout << "Error";
	}
	if (m_player->getComponent<CTransform>().pos.x < m_window.getSize().x / 2.f)
		m_view_x.setCenter(m_window.getSize().x / 2.f, m_window.getSize().y / 2.f);
	else
		m_view_x.setCenter(m_player->getComponent<CTransform>().pos.x, m_window.getSize().y /2.f);

	if (m_player->getComponent<CTransform>().pos.x > m_map.gridSize * m_map.gridX - m_window.getSize().x / 2.f)
		m_view_x.setCenter(m_map.gridSize * m_map.gridX - m_window.getSize().x / 2.f, m_window.getSize().y / 2.f);

	m_text.setString("x " + std::to_string(m_coinScore));
	m_text.setPosition(m_view_x.getCenter().x - m_window.getSize().x / 2.f + m_text.getLocalBounds().width, m_view_x.getCenter().y - m_window.getSize().y / 2.f);
	m_coinCount.setPosition(m_view_x.getCenter().x - m_window.getSize().x / 2.f, m_view_x.getCenter().y - m_window.getSize().y / 2.f + 10);
	m_window.draw(m_text);
	m_window.draw(m_coinCount);
	m_window.setView(m_view_x);
	m_window.display();
}

void Game::SpawnPlayer(const Map& level)
{
	m_player = m_manager.addEntity(eEntitiesType::DYNAMIC, eLevelEntities::PLAYER);
	m_player->addComponents<CAnimation>(Animation(eAnimationTypes::STAND, m_assets.getTexture(eTextureTypes::megaSTAND)), true);
	m_player->addComponents<CTransform>(Vec2(level.grid[2][2].getPosition().x, level.grid[2][2].getPosition().y), Vec2(0.f, 0.f), 10.f);
	m_player->addComponents<CInput>();
	m_player->getComponent<CAnimation>().animation.getSprite().setPosition(m_player->getComponent<CTransform>().pos.x, m_player->getComponent<CTransform>().pos.y);
}

void Game::SpawnBullet()
{
	auto bullet = m_manager.addEntity(eEntitiesType::PROJECTILE, eLevelEntities::BULLET);
	bullet->addComponents<CAnimation>(Animation(eAnimationTypes::NoAni, m_assets.getTexture(eTextureTypes::megaBuster)), true);
	bullet->addComponents<CTransform>(m_player->getComponent<CTransform>().pos, Vec2(m_BulletSpeed * m_player->getComponent<CTransform>().xScale, 0.f), 0.f);
}

Game::Game()
{
	m_window.create(sf::VideoMode(1024, 768), "Mario" );
	m_window.setFramerateLimit(60); 
	m_window.setMouseCursorVisible(false);


	m_assets.addTexture(eTextureTypes::marioGround, "mario/ground.png");
	m_assets.addTexture(eTextureTypes::marioBRICK, "mario/brick.png");
	m_assets.addTexture(eTextureTypes::megaSTAND, "megaman/megaStand.png");
	m_assets.addTexture(eTextureTypes::marioQBlock, "animations/QuestionBlock.png");
	m_assets.addTexture(eTextureTypes::marioBCLOUD, "mario/BigCloud.png");
	m_assets.addTexture(eTextureTypes::marioPIPE, "mario/SmallPipe.png");
	m_assets.addTexture(eTextureTypes::marioTallPIPE, "mario/TallPipe.png");
	m_assets.addTexture(eTextureTypes::megaJUMP, "megaman/megaJUMP.png");
	m_assets.addAnimation(eAnimationTypes::JUMP, eTextureTypes::megaJUMP, 1, 1);
	m_assets.addTexture(eTextureTypes::megaRUN, "megaman/megaRUN.png");
	m_assets.addAnimation(eAnimationTypes::RUN, eTextureTypes::megaRUN, 3, 9);
	m_assets.addTexture(eTextureTypes::marioGOOMBA, "mario/GoombaWalk.png");
	m_assets.addAnimation(eAnimationTypes::aniGOOMBA, eTextureTypes::marioGOOMBA, 2, 20);
	m_assets.addTexture(eTextureTypes::marioCOIN, "animations/coinspin.png");
	m_assets.addAnimation(eAnimationTypes::aniCOIN, eTextureTypes::marioCOIN, 6, 10);
	m_assets.addTexture(eTextureTypes::marioUNACQBlock, "mario/question2.png");
	m_assets.addTexture(eTextureTypes::marioGOODEATH, "mario/GoombaDeath.png");
	m_assets.addAnimation(eAnimationTypes::aniGOODEATH, eTextureTypes::marioGOODEATH, 2, 5);
	m_assets.addTexture(eTextureTypes::marioSMALLBUSH, "mario/Busher.png");
	m_assets.addTexture(eTextureTypes::marioBUSH, "mario/BigBush.png");
	m_assets.addTexture(eTextureTypes::marioSCLOUD, "mario/SmallCloud.png");
	m_assets.addTexture(eTextureTypes::marioCASTLE, "mario/castle.png");
	m_assets.addTexture(eTextureTypes::marioFLAG, "mario/Flagpole.png");
	m_assets.addTexture(eTextureTypes::megaBuster, "megaman/megaBuster.png");
	m_assets.addTexture(eTextureTypes::megaSHOT, "megaman/megaShot.png");
	m_assets.addAnimation(eAnimationTypes::SHOT, eTextureTypes::megaSHOT, 1, 60);
	m_assets.addTexture(eTextureTypes::marioExplosion, "animations/explosion.png");
	m_assets.addAnimation(eAnimationTypes::EXPLOSION, eTextureTypes::marioExplosion, 12, 4);
	m_assets.addTexture(eTextureTypes::marioCOINDEC, "mario/coin.png");
	m_coinCount.setTexture(m_assets.getTexture(eTextureTypes::marioCOINDEC));
	m_font.loadFromFile("my.otf");
	m_text.setFont(m_font);
	m_text.setCharacterSize(64);
	m_text.setString("x " + std::to_string(m_coinScore));


	m_view_x.setSize(m_window.getSize().x , m_window.getSize().y);
	m_view_x.setCenter(m_window.getSize().x / 2.f, m_window.getSize().y / 2.f);
	m_window.setView(m_view_x);
	loadLevel(m_map);
	SpawnPlayer(m_map); 
}

void Game::run()
{
	while (m_running)
	{	
			m_manager.update();	
			sUserInput();
			sMovement();		
			sCollision();
			sAnimation();
			sRender();
	}
}
