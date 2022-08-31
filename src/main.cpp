// Incluir os arquivos da sfml, considerando baixado no mesmo folder, e usando o compilerun.bash.
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Player.hpp"
#include <Wall.hpp>
#include <Player.hpp>

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

    // Clock.
    float dt;
    sf::Clock dt_clock;

    // Walls colision.
    sf::FloatRect nextpos;

    // Parede desenhada
    Wall wall(WINDOW_WIDTH, WINDOW_HEIGHT);
    wall.draw();

    // Jagador
    Player player(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2), GRID_SIZE,  WINDOW_WIDTH,  WINDOW_HEIGHT, wall);

    // Main event loop do jogo.
    while (window.isOpen()){
        sf::Event event;
        dt = dt_clock.restart().asSeconds();
        
        while(window.pollEvent(event)){
            
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                break;

                case (sf::Event::KeyPressed):// | sf::Event::KeyReleased ):
                    player.move(event);
                break;

                default:
                break;
            }
        }

        // Renderizar tudo. 
        window.clear();
        window.draw(player.body);

        for (auto w : wall.get_block_list())
            window.draw(w);
        
        window.display();
    }


    return 0;
}


