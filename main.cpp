#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>

int main() {
    sf::RenderWindow window(sf::VideoMode(320, 400), "The Game!");

    while (window.isOpen()){
        sf::Event e;
        while(window.pollEvent(e)){
            if(e.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::White);
        window.display();
    }
    return 0;
}
