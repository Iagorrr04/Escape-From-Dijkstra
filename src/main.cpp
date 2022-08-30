// Incluir os arquivos da sfml, considerando baixado no mesmo folder, e usando o compilerun.bash.
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int keyTime = 8;

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

    // Main event loop do jogo.
    while (window.isOpen()){
        sf::Event event;

        
        while(window.pollEvent(event)){
            
            // Pra poder fechar a janela de fato.
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.KeyPressed &&event.key.code == sf::Keyboard::Left && player.getPosition().x > 0){
                std::cout << "Left Arrow Pressed." << std::endl;
                player.move(sf::Vector2f(-5, 0));
    
            }
            else if(event.KeyPressed && event.key.code == sf::Keyboard::Up && player.getPosition().y > 0){
                std::cout << "Up arrow pressed." << std::endl;
                player.move(sf::Vector2f(0, -5));
            }
            else if(event.KeyPressed && event.key.code == sf::Keyboard::Down && player.getPosition().y + player.getSize().y < window.getSize().y){
                std::cout << "Down Arrow Pressed" << std::endl;
                player.move(sf::Vector2f(0, 5));
            }
            else if(event.KeyPressed && event.key.code == sf::Keyboard::Right && player.getPosition().x + player.getSize().x < window.getSize().x){
                std::cout << "Right Arrow Pressed." << std::endl;
                player.move(sf::Vector2f(5, 0));
            }
        
        }
        // Render.     
        window.clear();
        window.draw(player);
        window.setView(view);

        // Renderizar elementos do jogo.
        //window.setView(window.getDefaultView());
        
        // Render ui.
        window.display();
    }


    return 0;
}

