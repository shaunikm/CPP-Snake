#include <iostream>
#include "canv.hpp"

int main() {
    Game g(Canvas::width, Canvas::height);
    while (g.alive) {
        g.run();
    }
    g.cleanUp();
    
    
    std::cout << "You died!" << std::endl;

    return 0;
}