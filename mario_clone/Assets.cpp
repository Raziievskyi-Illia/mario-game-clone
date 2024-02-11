#include "Assets.h"
#include <iostream>

void Assets::addTexture(eTextureTypes texture_types, const std::string& path,
    bool smooth) {
    m_textureMap[texture_types] = sf::Texture();
    if (!m_textureMap[texture_types].loadFromFile(path)) {
        std::cerr << "Could not load texture file: " << path << std::endl;
        m_textureMap.erase(texture_types);
    }
    else {
        m_textureMap[texture_types].setSmooth(smooth);
        std::cout << "Loaded Texture: " << path << std::endl;
    }
}

const sf::Texture& Assets::getTexture(eTextureTypes texture_types) const 
{
    return m_textureMap.at(texture_types);
}

void Assets::addAnimation(eAnimationTypes animation_types,
    eTextureTypes texture_types, size_t frameCount,
    size_t speed) {
    m_animationMap[animation_types] =
        Animation(animation_types, getTexture(texture_types), frameCount, speed);
}

const Animation& Assets::getAnimation(eAnimationTypes animation_types) const 
{
    return m_animationMap.at(animation_types);
}
