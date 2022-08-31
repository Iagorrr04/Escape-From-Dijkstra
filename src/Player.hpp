#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Player{
    
public:

    float WINDOW_WIDTH, WINDOW_HEIGHT;
    float GRID_SIZE;
    float movement_speed;
    sf::RectangleShape body;
    sf::Vector2f velocity;
    sf::Vector2f position;


    Player(sf::Vector2f position, float GRID_SIZE, float WINDOW_WIDTH, float WINDOW_HEIGHT );

    void move(sf::Event event);

};
