#include "sprites.hpp"
#include "settings.hpp"
using namespace std;

class Game
{
    public:
        int width;
        int height;
        bool alive;
        Snake* player = new Snake(3, 5, width, height);
        Apple* target = new Apple(6, 5);

        Game(int w, int h)
        {
            width = w;
            height = h;
            alive = true;
            player->setd(width, height);
        }

        void run() {
            system("clear");

            Game::update();
            Game::draw();
            player->update();
        }

        void update() {

        }

        void draw() {
            for (int w = 1; w <= Game::width+2; w++) {
                cout << Canvas::border;
            }

            cout << endl;

            for (int h = 1; h <= Game::height; h++) {
                for (int w = 1; w <= Game::width+2; w++) {
                    if (w == 1 || w == Game::width+2)
                    {
                        cout << Canvas::border;
                    }
                    else if (w-1 == player->pos[0] && h-1 == player->pos[1])
                    {
                        cout << Canvas::snake;
                    }
                    else if (w-1 == target->pos[0] && h == target->pos[1])
                    {
                        cout << Canvas::apple;
                    }
                    else
                    {
                        cout << Canvas::blank;
                    }
                }
                cout << endl;
            }

            for (int w = 1; w <= width+2; w++) {
                cout << Canvas::border;
            }
            cout << endl;
            cout << player->pos[1] << endl;
        }
};