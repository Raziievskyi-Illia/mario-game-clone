#pragma once

#include "Animation.h"
#include <map>
#include "SFML/Graphics.hpp"


enum eTextureTypes {
    marioUNACQBlock,
    marioCOIN,
    marioQBlock,
    marioGround,
    marioBRICK ,
    megaRUN,
    megaJUMP,
    megaSTAND,
    megaSHOT,
    megaBuster,
    marioExplosion,
    marioBUSH,
    marioSMALLBUSH,
    marioSCLOUD,
    marioGOOMBA,
    marioPIPE,
    marioTallPIPE,
    marioBCLOUD,
    marioGOODEATH,
    marioCASTLE,
    marioFLAG
};


class Assets {
    std::map<eTextureTypes, sf::Texture> m_textureMap;
    std::map<eAnimationTypes, Animation> m_animationMap;
  
    
public:
    Assets() = default;
    void addTexture(eTextureTypes texture_types, const std::string& path,bool smooth = true);
    void addAnimation(eAnimationTypes animation_types,eTextureTypes texture_types, size_t frameCount,size_t speed);
    const sf::Texture& getTexture(eTextureTypes texture_types) const;
    const Animation& getAnimation(eAnimationTypes animation_types) const;
};
