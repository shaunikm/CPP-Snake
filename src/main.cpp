/**
 * Simple console-based snake game.
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