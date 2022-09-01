// Incluir os arquivos da sfml, considerando baixado no mesmo folder, e usando o compilerun.bash.
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Player.hpp>
#include <SFML/Audio.hpp>
#include <Wall.hpp>


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
    Wall wall(WINDOW_HEIGHT, WINDOW_WIDTH);
    wall.draw();

    // Jagador
    Player player(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2), GRID_SIZE,  WINDOW_WIDTH,  WINDOW_HEIGHT, wall);

    // Main event loop do jogo.

    // Main event loop do jogo.
    bool moving_left = false;
    bool moving_down = false;
    bool moving_up = false;
    bool moving_right = false;   

    // Musica.
    sf::Music main_theme;
    main_theme.openFromFile("./media/main_theme.wav"); // deve ser comparado com a localização do make
    main_theme.setVolume(100);
    main_theme.play();
    
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


