/**
 * Simple console-based snake game for MacOS.
 * The input function I used is based off: https://github.com/10sabana/SnakeGame_macos/blob/master/snakegame.cpp
 * 
 * @author Shaunik Musukula
 * @version 1.2
*/
#include "canv.hpp"

int main() {
    Game g(Canvas::width, Canvas::height);
    while (g.running) {
        g.run();
    }
    g.cleanUp();
}