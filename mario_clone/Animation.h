#pragma once
#include "Vec2.h"
#include <vector>
#include <SFML/Graphics.hpp>

enum eAnimationTypes {
    AniBRICK,
    RUN,
    JUMP,
    STAND,
    SHOT,
    BUSTER,
    EXPLOSION,
    AniCLOUDSMALL,
    aniSMALLBUSH,
    aniPIPE,
    aniBUSHER,
    aniGOOMBA,
    aniBCLOUD,
    aniGOODEATH,
    aniCOIN,
    NoAni
};

class Animation {
    sf::Sprite m_sprite;
    size_t m_frameCount = 1;  
    size_t m_currentFrame = 0;
    size_t m_speed = 0;       
    Vec2 m_size = { 1, 1 };
    eAnimationTypes m_name;
public:
    Animation();
    Animation(eAnimationTypes name, const sf::Texture& t);
    Animation(eAnimationTypes name, const sf::Texture& t, size_t frameCount,size_t speed);
    void update();
    bool hasEnded() const;
    eAnimationTypes getName() const;
    const Vec2& getSize() const;
    sf::Sprite& getSprite();
};