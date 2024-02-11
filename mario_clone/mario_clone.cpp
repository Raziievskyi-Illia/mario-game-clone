
#include <iostream>
#include "SFML/Graphics.hpp"
#include <vector>
#include "Game.h"

int main()
{
    Game g;
    g.run(); 


    //    sf::RenderWindow window(sf::VideoMode(1024, 768), "My window" , sf::Style::None);
    //    std::vector<std::vector<sf::RectangleShape>> grid;
    //    const float gridSize = 64;
    //    const float gridX = 20;
    //    const float gridY = 12;
    //    sf::Font font;
    //    font.loadFromFile("my.otf");
    //    sf::Text text;
    //    text.setFont(font);
    //    text.setCharacterSize(16);
    //    text.setFillColor(sf::Color::Black);
    //    sf::View view_x;
    //    view_x.setSize(1024.f, 768.f);
    //    view_x.setCenter(512.f, 384.f);
    //    window.setView(view_x);
    // 
    //    sf::Texture tex; 
    // //   tex.loadFromFile("ground.png");
    //    if (!tex.loadFromFile("D:/work/cpp/mario_clone/mario_clone/ground.png")) {
    //        std::cerr << "Failed to load texture from file" << std::endl;
    //        return EXIT_FAILURE;
    //    }
    ////    sf::Sprite sprite; 
    ////    sprite.setTexture(tex);
    //    std::vector<std::pair<int, int>> tiles;     
    //    for (int x = 0; x < gridX; x++)
    //    {
    //        tiles.push_back(std::make_pair(x, 11));
    //    }
    //    std::vector<sf::Sprite> sprites{tiles.size()};
    //    for (auto& el : sprites)
    //    {
    //        el.setTexture(tex);
    //    }

    //   


    //        
    //    for (size_t x = 0; x < gridX; x++)
    //    {
    //        grid.push_back(std::vector<sf::RectangleShape>());
    //        for (size_t y = 0; y < gridY; y++)
    //        {
    //            grid[x].push_back(sf::RectangleShape(sf::Vector2f(gridSize, gridSize)));
    //            grid[x][y].setFillColor(sf::Color::White);
    //            grid[x][y].setOutlineColor(sf::Color::Black);
    //            grid[x][y].setOutlineThickness(1.f);
    //            grid[x][y].setPosition(sf::Vector2f(x * gridSize, y * gridSize));
    //            
    //        }
    //    }
    //    for (int i = 0 ; i < sprites.size() ; i++)
    //    {
    //        sprites[i].setPosition(grid[tiles[i].first][tiles[i].second].getPosition());
    //    }
    //   
    //  //  sprite.setPosition(grid[8][8].getPosition());
    //    while (window.isOpen())
    //    {

    //        sf::Event event;
    //        while (window.pollEvent(event))
    //        {
    //            if (event.type == sf::Event::Closed)
    //                window.close();
    //            else if (event.type == sf::Event::KeyPressed)
    //            {
    //                if (event.key.code == sf::Keyboard::D)
    //                {
    //                    view_x.move(100.f, 0.f);
    //                    window.setView(view_x);
    //                }
    //                else if (event.key.code == sf::Keyboard::Escape)
    //                {
    //                    window.close(); 
    //                }
    //            }
    //        
    //        }


    //        window.clear(); 
    //        for (int x = 0; x < gridX; x++)
    //        {
    //            for (int y = 0; y < gridY; y++)
    //            {       
    //                window.draw(grid[x][y]);
    //                text.setString(std::to_string(x) + " , " + std::to_string(y));
    //                text.setPosition(grid[x][y].getPosition());
    //                window.draw(text);
    //            }
    //        }
    //   
    //        for (const auto& s : sprites)
    //        {
    //            window.draw(s);
    //        }
    //        window.display();
    //    }

    //    return 0;
    
}


