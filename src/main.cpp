// Incluir os arquivos da sfml, considerando baixado no mesmo folder, e usando o compilerun.bash.
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


int main(){
    // Configurações iniciais da window.
    const unsigned short int WINDOW_HEIGHT = 360;
    const unsigned short int WINDOW_WIDTH = 840;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Escape From Dijsktra");
    window.setFramerateLimit(60);

    // Visão da câmera.
    sf::View view;
    view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    view.setCenter(window.getSize().x/2.f, window.getSize().y/2.f);

    // Grid, 'menor unidade'
    const float GRID_SIZE = 10.f;

    // Personagem principal.
    sf::RectangleShape player;
    player.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    sf::Vector2f playerPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
    player.setPosition(playerPosition); 
    
    sf::Vector2f player_velocity;
    int movement_speed = GRID_SIZE;

    // Clock.
    float dt;
    sf::Clock dt_clock;

    // Walls.
    std::vector<sf::RectangleShape> WALLS;
    sf::RectangleShape wall_01;
    wall_01.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    wall_01.setPosition(GRID_SIZE*4, GRID_SIZE*4);

    WALLS.push_back(wall_01);

    // Walls colision.
    sf::FloatRect nextpos;

    // Main event loop do jogo.
    bool moving_left = false;
    bool moving_down = false;
    bool moving_up = false;
    bool moving_right = false;   
    while (window.isOpen()){
        sf::Event event;
        dt = dt_clock.restart().asSeconds();
        
        player_velocity.x = 0.f; player_velocity.y = 0.f;
        while(window.pollEvent(event)){
            
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                break;

                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Right){
                        moving_right = true;
                        player_velocity.x = movement_speed;
                    }
                    if(event.key.code == sf::Keyboard::Down){
                        moving_down = true;
                        player_velocity.y = movement_speed;                        
                    }
                    if(event.key.code == sf::Keyboard::Up){
                        moving_up = true;
                        player_velocity.y = -movement_speed;
                    }
                    if(event.key.code == sf::Keyboard::Left){
                        moving_left = true;
                        player_velocity.x = -movement_speed;
                    }
                break;
                case sf::Event::KeyReleased:
                    if(event.key.code == sf::Keyboard::Right){
                        moving_right = false;
                    }
                    if(event.key.code == sf::Keyboard::Down){
                        moving_down = false;
                    }
                    if(event.key.code == sf::Keyboard::Up){
                        moving_up = false;
                    }
                    if(event.key.code == sf::Keyboard::Left){
                        moving_left = false;
                    }
                break;

                default:
                break;
            }
        }

        // Colisão bordas.
        sf::Vector2f nextPosition = player.getPosition() + player.getSize() + player_velocity;
        if(nextPosition.x > 0 and nextPosition.x <= WINDOW_WIDTH and nextPosition.y > 0 and nextPosition.y <= WINDOW_HEIGHT)
            player.move(player_velocity);

        // // Collision Walls.
        // for(auto &wall : WALLS){
        //     sf::FloatRect player_bounds = player.getGlobalBounds();
        //     nextpos.left = player_bounds.left + player_velocity;
        //     nextpos.top = player_bounds.top + player_velocity;
            
        //     sf::FloatRect wall_bound;
        //     wall_bound = wall.getGlobalBounds();

        //     if(wall_bound.intersects(nextpos)){
        //         std::cout << "Colision Detected" << std::endl;
        //     }
        // }

        // Renderizar tudo. 
        window.clear();
        window.draw(player);
        
        for(auto &w : WALLS)
            window.draw(w);

        window.setView(view);
        window.setView(window.getDefaultView());

        window.display();
    }


    return 0;
}


