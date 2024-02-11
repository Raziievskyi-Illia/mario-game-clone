#include "Map.h"


Vec2 getMidCoord( const sf::RectangleShape& grid, const sf::Sprite& image)
{
    return Vec2(grid.getPosition().x - grid.getSize().x / 2 + image.getLocalBounds().width / 2, grid.getPosition().y + grid.getSize().y / 2 - image.getLocalBounds().height / 2);
}


Map::Map()
{
    font.loadFromFile("my.otf");
    text.setFont(font);
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::Black);

    for (size_t x = 0; x < gridX; x++)
    {   
        grid.push_back(std::vector<sf::RectangleShape>());
        for (size_t y = 0; y < gridY; y++)
        {
         
            grid[x].push_back(sf::RectangleShape(sf::Vector2f(gridSize, gridSize)));
            grid[x][y].setFillColor(sf::Color::Transparent);
            grid[x][y].setOutlineColor(sf::Color::Black);
            grid[x][y].setOutlineThickness(1.f);
            grid[x][y].setOrigin(gridSize / 2, gridSize / 2);
            grid[x][y].setPosition(sf::Vector2f(x * gridSize + gridSize/2, y * gridSize + gridSize / 2));
        }
    }
    
    excludeGroundCoord = { 19,20,45,46,47,44,50,51,52,53,54,57,58,59,60,61,64,65,66,67,68};
    groundCoord = {  {115,5} , {115,6},{115,7},{115,8},{115,9},{115,10} };
    int k = 109;
    for (int i = 10; i > 3 ; i--)
    {
        for(int j = k ; j <115;j++ )
        {
            groundCoord.push_back({j , i});
        }
        k++;
    }
    for (int x = 0; x < gridX; x++)
    {
        if (std::any_of(excludeGroundCoord.begin(), excludeGroundCoord.end(), [&x](int value) {return x == value; })) continue;
        groundCoord.push_back({x ,gridY-1});
    }
    
    brickCoord = { { 7,8 } , {9, 8} , {36,10} , {37 ,9} , {38,8} ,{39,7}, {40,6} , {41,5} , {42,5},{43,5},{44,5},{45,5}  , {81,8} , {82,8} , {77,5} , {78,5} , {85,5}
    , {86,5}  , {89,8} , {90,8} ,  {94,4} , {95,4} , {96,4} ,{97,4} , {98,4} ,{94,6},{95,6},{96,6},{97,6},{98,6} , {11,8} , {99,4} , {100 ,4} , {101,4} , {102,4} , {103,4} ,{99,6} , {100 ,6} , {101,6} , {102,6} , {103,6}  , {104,4} , {104 ,5} , {104,6} };
    QBlockCoord = { {8, 8}, { 10,8 }};
    BCloudCoord = { {3 , 3} ,{38,2} , {59,8} , {67,2} , {88,2} ,{108,3} };
    PipeCoord = { {16,10}};
    TallPipeCoord = { {21, 10},{48,10},{55,10},{62,10},{69,10} };
    GoombaCoord = { {26 ,10} , {41,4} , {42,4} , {43,4} , {103,5} };
    CoinCoord = { {97,5}  , {77,4} , {86,4} ,{42,10} , {95,5} , {99,5} , {101,5} };
    SCloudCoord = { {18,2} , {127,2} };
    BushCoord = { {30,10} };
    castleCoord =  {128, 10} ;
    flagCoorg = { 121 ,10 };
    BusherCoord = { {75,10} ,{79,10} };
}
