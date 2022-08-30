#include <Wall.hpp>
#include <SFML/Graphics.hpp>

// Temporário
#include <iostream>

Wall::Wall(int height, int width){
    this->win_height = height;
    this->win_width = width;
}

Wall::~Wall(){}

void Wall::set_block_size(int height, int width){
    this->sq_width = width;
    this->sq_height = height;
}

void Wall::draw(){

    for (int i = 0; i < this->win_width; i+=10){
        for (int j = 0; j < this->win_height; j+=10){
            int val = (i + j) / 10;
            if (val & 1) continue;

            std::cout << i << " " << j << std::endl;

            sf::RectangleShape block;
            block.setSize(sf::Vector2f(this->sq_width, this->sq_height));
            sf::Vector2f blockPosition(i, j);
            block.setPosition(blockPosition); 
            block.setFillColor(sf::Color(100, 100, 100));
            this->blocks_list.push_back(block);
        }
    }
}

sf::RectangleShape Wall::get_block(){
    return this->blocks_list.front();
}