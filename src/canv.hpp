#include <ncurses.h>
#include <iostream>
#include <vector>
#include "sprites.hpp"
#include "settings.hpp"
using std::to_string, std::vector, std::string;

class Game
{
    public:
        int width;
        int height;
        bool alive;
        Snake* player = new Snake(2, 5);
        Tail* body = new Tail;
        Apple* target = new Apple(6, 5);
        double tick;

        Game(int w, int h)
        {
            width = w;
            height = h;
            alive = true;
            player->setd(width, height);
            body->add_tail(player->pos[0], player->pos[1]);
            tick = Canvas::TPL;

            initscr();
            clear();
            noecho();
            cbreak();
            curs_set(0);

            srand(time(NULL));

        }

        void run() {
            if (tick >= Canvas::TPL) {
                input();
                player->update();
                body->update_tail(player->pos[0], player->pos[1]);
                tick = 0;
                
            } else {
                tick += 1/Canvas::TPL;
            }

            Game::update();
        }

        void update() {
            Game::draw();
        }

        void draw() {
            clear();
            drawCanvas();
            mvprintw(target->pos[1], target->pos[0], Canvas::apple);
            int width_count = 0;
            // mvprintw(height+3, 0, to_string(body->positions.size()).c_str());
            for (std::vector<int> pos : body->positions) {
                mvprintw(pos[1], pos[0], Canvas::body);
                width_count += 4;
            }
            mvprintw(player->pos[1], player->pos[0], Canvas::snake);

            /*
            mvprintw(height+3, 0, to_string(player->pos[0]).c_str());
            mvprintw(height+3, 5, to_string(player->pos[1]).c_str());
            mvprintw(height+4, 0, to_string(target->pos[0]).c_str());
            mvprintw(height+4, 5, to_string(target->pos[1]).c_str());
            */
            if (player->pos[0] == target->pos[0] && player->pos[1] == target->pos[1]) {
                newApple();
                body->add_tail(player->direction);
            }
            refresh();
        }

        void input() {
            keypad(stdscr, TRUE);
            halfdelay(1); 

            int c = getch();

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