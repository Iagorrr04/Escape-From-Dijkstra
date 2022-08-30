#include<vector>
#include <SFML/Graphics.hpp>

class Wall{
    private:

    int sq_height = 10;
    int sq_width = 10;

    int win_height;
    int win_width;

    std::vector<sf::RectangleShape> blocks_list;

    public:
    Wall(int height, int width);
    ~Wall();

    void set_block_size(int height, int width);
    void draw();
    std::vector<sf::RectangleShape> &get_block_list();
};