#include <iostream>
#include "canv.hpp"
using namespace std;

int main() {
    Game g(Canvas::width, Canvas::height);
    while (true) {
        g.run();
    }

    cout << "You died!" << endl;

    return 0;
}