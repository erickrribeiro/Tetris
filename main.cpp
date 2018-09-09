#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>

int main() {
    sf::RenderWindow window(sf::VideoMode(320, 400), "The Game!");

    sf::Texture t;
    t.loadFromFile("../images/tiles.png");

    sf::Sprite s(t);


    while (window.isOpen()){
        sf::Event e;
        while(window.pollEvent(e)){
            if(e.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.draw(s);
        window.display();
    }
    return 0;
}
