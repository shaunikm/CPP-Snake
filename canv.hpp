#include <ncurses.h>
#include "sprites.hpp"
#include "settings.hpp"
#include <format>
#include <vector>
using namespace std;

class Game
{
    public:
        int width;
        int height;
        bool alive;
        Snake* player = new Snake(2, 5, width, height);
        Apple* target = new Apple(6, 5);
        double tick;

        Game(int w, int h)
        {
            width = w;
            height = h;
            alive = true;
            player->setd(width, height);
            tick = Canvas::FPL;

            initscr();
            clear();
            noecho();
            cbreak();
            curs_set(0);

            srand(time(NULL));
        }

        void run() {
            if (tick >= Canvas::FPL) {
                input();
                player->update();
                tick = 0;
                
            } else {
                tick += 1/Canvas::FPL;
            }

            Game::update();
        }

        void update() {
            Game::draw();
            // printf("Tick is at %f\n", tick);
        }

        void draw() {
            clear();
            drawCanvas();
            mvprintw(target->pos[1], target->pos[0], Canvas::apple);
            mvprintw(player->pos[1], player->pos[0], Canvas::snake);
            /*
            mvprintw(height+3, 0, to_string(player->pos[0]).c_str());
            mvprintw(height+3, 5, to_string(player->pos[1]).c_str());
            mvprintw(height+4, 0, to_string(target->pos[0]).c_str());
            mvprintw(height+4, 5, to_string(target->pos[1]).c_str());
            */
            if (player->pos[0] == target->pos[0] && player->pos[1] == target->pos[1]) {
                newApple();
                mvprintw(height+3, 0, to_string(player->pos[0]).c_str());
                mvprintw(height+3, 5, to_string(player->pos[1]).c_str());
                mvprintw(height+4, 0, to_string(target->pos[0]).c_str());
                mvprintw(height+4, 5, to_string(target->pos[1]).c_str());
            }
            refresh();
        }

        void input() {
            keypad(stdscr, TRUE); // Check whether there is input, function from ncurses
            halfdelay(1); 

            int c = getch(); // Save the typed key by gamer

            switch(c)
            {
                case KEY_LEFT:
                    player->direction = LEFT;
                    break;
                case KEY_RIGHT:
                    player->direction = RIGHT;
                    break;
                case KEY_DOWN:
                    player->direction = DOWN;
                    break;
                case KEY_UP:
                    player->direction = UP;
                    break;
                case 27:
                    alive = false;
                    break;
            }
        }

        void newApple() {
            delete target;
            target = new Apple((rand() % width) + 1, (rand() % height) + 1);
        }

        void cleanUp() {
            getch();
            endwin();
            delete player;
            delete target;
        }

        void drawCanvas() {
            for (int w=0; w <= width+1; w++) {
                mvprintw(0, w, Canvas::border);
                mvprintw(height+1, w, Canvas::border);
            }

            for (int h=1; h <= height; h++) {
                mvprintw(h, 0, Canvas::border);
                mvprintw(h, width+1, Canvas::border);
            }
        }
};