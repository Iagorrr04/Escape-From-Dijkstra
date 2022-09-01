// Incluir os arquivos da sfml, considerando baixado no mesmo folder, e usando o compilerun.bash.
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <Wall.hpp>
#include <Monster.hpp>

const float RATE_MONSTER_MOVE = 20.0;

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
    sf::Vector2f playerPosition(0, 0);
    player.setPosition(playerPosition); 
    
    sf::Vector2f player_velocity;
    int movement_speed = GRID_SIZE;

    // Clock.
    float dt;
    sf::Clock dt_clock;

    // Walls colision.
    sf::FloatRect nextpos;

    // Parede desenhada
    Wall wall(WINDOW_HEIGHT, WINDOW_WIDTH);
    wall.draw();

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

        // Colisão paredes

        bool can = true;
        for (auto w: wall.get_block_list()){
            auto pos = w.getPosition();
            if (abs(pos.x - nextPosition.x + 10) + abs(pos.y - nextPosition.y + 10) < 10) {
                can = false;
            }      
        }

        if(can and nextPosition.x > 0 and nextPosition.x <= WINDOW_WIDTH and nextPosition.y > 0 and nextPosition.y <= WINDOW_HEIGHT)
            player.move(player_velocity);

        if (dt_monster.getElapsedTime().asMilliseconds() > RATE_MONSTER_MOVE) {
            monster.move(player.getPosition());
            dt_monster.restart().asMilliseconds();
        }
        // Renderizar tudo. 
        window.clear();
        window.draw(player);
        window.draw(monster.get_monster());
        for (auto w: wall.get_block_list())
            window.draw(w);

        window.display();
    }


    return 0;
}


