#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>

const int M = 20;
const int N = 10;
struct Point{
    int x, y;
}a[4], b[4];

int field[M][N] = {0};
int figures[7][4] = {
        1,3,5,7, //I
        2,4,5,7, //Z
        3,5,4,6, //S
        3,5,4,7, //T
        2,3,5,7, //L
        3,5,7,6, //J
        2,3,4,5  //0
};

int main() {
    sf::RenderWindow window(sf::VideoMode(320, 400), "The Game!");

    sf::Texture t;
    t.loadFromFile("../images/tiles.png");

    sf::Sprite s(t);
    s.setTextureRect(sf::IntRect(0,0,18,18));


    while (window.isOpen()){
        sf::Event e;
        while(window.pollEvent(e)){
            if(e.type == sf::Event::Closed){
                window.close();
            }
        }

        int n = 2;
        for (int i=0;i < 4; i++){
            a[i].x = figures[n][i] % 2;
            a[i].y = figures[n][i] / 2;
        }

        window.clear(sf::Color::White);

        for (int i=0; i < 4; i++ ){
            s.setPosition(a[i].x * 18, a[i].y * 18);
            window.draw(s);
        }

        window.display();
    }
    return 0;
}
