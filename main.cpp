#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

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

    int dy =0; int dx = 0; bool rotate = false; int colorNum = 1;
    int lastTimer=0; float timer = 0; float delay = 3.0;

    sf::Clock clock;

    while (window.isOpen()){

        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+= time;

        sf::Event e;
        while(window.pollEvent(e)){
            if(e.type == sf::Event::Closed){
                window.close();
            }

            if(e.type == sf::Event::KeyPressed){
                if(e.key.code == sf::Keyboard::Up){
                    rotate = true;
                }else if(e.key.code == sf::Keyboard::Left){
                    dx -= 1;
                }else if(e.key.code == sf::Keyboard::Right){
                    dx += 1;
                }else if(e.key.code == sf::Keyboard::Down){
                    dy += 1;
                }
            }
        }


        /// <- Move (Left, Rights or Down) ->
        for(int i=0; i < 4; i++){
            a[i].x += dx;
            a[i].y += dy;
        }

        /// Rotate
        if(rotate){
            Point p = a[1]; // center rotation
            for(int i=0; i < 4; i++){
                int x = a[i].y - p.y;
                int y = a[i].x - p.x;

                a[i].x = p.x - x;
                a[i].y = p.y + y;
            }
        }

        ////// Tick //////
//        if(timer > delay){
        int iTimer = static_cast<int>(timer);

        if(lastTimer != iTimer){
            for(int i=0; i < 4; i++) {
                a[i].y += 1;
            }
//            std::cout << "tick: " << ((int)timer) << std::endl;
            lastTimer = iTimer;
            timer += 0;
        }


        int n = 3;
        if(a[0].x == 0) {
            for (int i = 0; i < 4; i++) {
                a[i].x = figures[n][i] % 2;
                a[i].y = figures[n][i] / 2;
            }
        }

        dx = 0;
        dy = 0;
        rotate = false;

        window.clear(sf::Color::White);

        for (int i=0; i < 4; i++ ){
            s.setPosition(a[i].x * 18, a[i].y * 18);
            window.draw(s);
        }

        window.display();
    }
    return 0;
}
