/**
 * Simple console-based snake game.
 * The input function I used is based off: https://github.com/10sabana/SnakeGame_macos/blob/master/snakegame.cpp
 * 
 * @author Shaunik Musukula
 * @version 1.1
*/
#include "canv.hpp"

int main() {
    Game g(Canvas::width, Canvas::height);
    while (g.alive) {
        g.run();
    }
    g.cleanUp();

    return 0;
}