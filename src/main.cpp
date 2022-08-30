// Incluir os arquivos da sfml, considerando baixado no mesmo folder, e usando o compilerun.bash.
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Wall.hpp>



int main(){
    // Configurações iniciais da window.
    unsigned short int wHeight = 500;
    unsigned short int wWidth = 500;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Escape From Dijsktra");
    window.setFramerateLimit(60);

    // Visão da câmera.
    sf::View view;
    view.setSize(wWidth, wHeight);
    view.setCenter(window.getSize().x/2.f, window.getSize().y/2.f);

    // Personagem principal.
    sf::RectangleShape player;
    player.setSize(sf::Vector2f(10, 10));
    sf::Vector2f playerPosition(wWidth/2, wHeight/2);
    player.setPosition(playerPosition); 
    int player_velocity = 10;

    // Parede desenhada
    Wall wall(wHeight, wWidth);
    wall.draw();

    // Main event loop do jogo.
    bool moving_left = false;
    bool moving_down = false;
    bool moving_up = false;
    bool moving_right = false;   
    while (window.isOpen()){
        sf::Event event;

        
        while(window.pollEvent(event)){
            
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                break;

                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Right) moving_right = true;
                    if(event.key.code == sf::Keyboard::Down) moving_down = true;
                    if(event.key.code == sf::Keyboard::Up) moving_up = true;
                    if(event.key.code == sf::Keyboard::Left) moving_left = true;
                break;
                case sf::Event::KeyReleased:
                    if(event.key.code == sf::Keyboard::Right) moving_right = false;
                    if(event.key.code == sf::Keyboard::Down) moving_down = false;
                    if(event.key.code == sf::Keyboard::Up) moving_up = false;
                    if(event.key.code == sf::Keyboard::Left) moving_left = false;
                break;

                default:
                break;
            }

            if(moving_left && player.getPosition().x > 0){
                    player.move(-player_velocity, 0);
            }
            if (moving_down && player.getPosition().y + player.getSize().y < window.getSize().y){
                player.move(0, player_velocity);
            }
            if(moving_up && player.getPosition().y > 0){
                player.move( 0, -player_velocity);
            }
            if(moving_right && player.getPosition().x + player.getSize().x < window.getSize().x){
                player.move(player_velocity, 0);
            }
        }
        // Render.     
        window.clear();
        window.draw(player);
        for (auto w: wall.get_block_list())
            window.draw(w);


        // Renderizar elementos do jogo.
        //window.setView(window.getDefaultView());
        
        // Render ui.
        window.display();
    }


    return 0;
}

