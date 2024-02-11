#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
#include "Vec2.h"


Vec2 getMidCoord(const sf::RectangleShape& grid, const sf::Sprite& image);


class Map
{
      
public:
    sf::Font font;
    const float gridX = 135;
    const float gridY = 12;
    sf::Text text;
    Map(); 
    const float gridSize = 64;
    std::vector<std::vector<sf::RectangleShape>> grid;
    std::vector<std::pair<int, int>> groundCoord; 
    std::vector<std::pair<int, int>> brickCoord;
    std::vector<std::pair<int, int>> QBlockCoord;
    std::vector<std::pair<int, int>> BCloudCoord;
    std::vector<std::pair<int, int>> PipeCoord;
    std::vector<std::pair<int, int>> TallPipeCoord;
    std::vector<std::pair<int, int>> GoombaCoord;
    std::vector<std::pair<int, int>> CoinCoord;
    std::vector<std::pair<int, int>> SCloudCoord;
    std::vector<std::pair<int, int>> BushCoord;
    std::pair<int, int> castleCoord;
    std::pair<int, int> flagCoorg;
    std::vector<std::pair<int, int>> BusherCoord;
    std::vector<int> excludeGroundCoord;
};