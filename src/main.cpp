// Incluir os arquivos da sfml, considerando baixado no mesmo folder, e usando o compilerun.bash.
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main(){
    // Configurações iniciais da window.
    unsigned short int wHeight = 360;
    unsigned short int wWidth = 840;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Escape From Dijsktra");

    // Visão da câmera.
    sf::View view;
    view.setSize(wHeight, wWidth);
    view.setCenter(window.getSize().x/2.f, window.getSize().y/2.f);



    // Main loop do jogo.
    while (window.isOpen()){
        sf::Event event;

        
        while(window.pollEvent(event))
            
            if(event.type == sf::Event::Closed)
                window.close();

            
        // Render.     
        window.clear();
        window.setView(view);

        // Renderizar elementos do jogo.
        window.setView(window.getDefaultView());
        
        // Render ui.
        window.display();
    }


    return 0;
}

