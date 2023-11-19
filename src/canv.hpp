#include <ncurses.h>
#include <iostream>
#include <vector>
#include "sprites.hpp"
#include "settings.hpp"
using std::to_string;
using std::vector;
using std::string;

class Game
{
    public:
        int width;
        int height;
        bool alive;
        bool running;
        Snake* player;
        Tail* body;
        Apple* target;
        double tick;

        Game(int w, int h)
        {
            this->width = w;
            this->height = h;
            this->alive = true;
            this->running = true;
            this->player = new Snake(2, 5);
            this->body = new Tail;
            this->target = new Apple(9, 5);
            this->player->setd(this->width, this->height);
            this->body->add_tail(player->pos[0], player->pos[1]);
            this->tick = Canvas::TPL;
            

            initscr();
            clear();
            noecho();
            cbreak();
            curs_set(0);
        }

        void run() {
            if (tick >= Canvas::TPL) {
                this->input();
                if (alive) {
                    this->body->update_tail(player->pos[0], player->pos[1]);
                    this->player->update();
                }
                this->tick = 0;
                this->Game::checkDeath();
            } else {
                this->tick += 1/Canvas::TPL;
            }
            this->update();
        }

        void update() {
            Game::draw();
        }

        void draw() {
            clear();
            this->drawCanvas();
            mvprintw(this->target->pos[1], this->target->pos[0], Canvas::apple.c_str());

            for (std::vector<int> pos : this->body->positions) {
                mvprintw(pos[1], pos[0], Canvas::body.c_str());
            }
            mvprintw(player->pos[1], player->pos[0], Canvas::snake.c_str());

            if (this->player->pos[0] == this->target->pos[0] && this->player->pos[1] == this->target->pos[1]) {
                this->newApple();
                this->body->add_tail(player->direction);
            }

            mvprintw((int)Canvas::height/2, Canvas::width+4, "Press escape to quit");
            this->alive ? mvprintw((int)Canvas::height/2-1, Canvas::width+4, "Game running...") : mvprintw((int)Canvas::height/2-1, Canvas::width+4, "You died!");

            refresh();
        }

        void input() {
            keypad(stdscr, TRUE);
            halfdelay(1); 

            int c = getch();

            switch(c)
            {
                case KEY_LEFT:
                    this->player->direction = LEFT;
                    break;
                case KEY_RIGHT:
                    this->player->direction = RIGHT;
                    break;
                case KEY_DOWN:
                    this->player->direction = DOWN;
                    break;
                case KEY_UP:
                    this->player->direction = UP;
                    break;
                case 27:
                    this->running = false;
                    break;
            }
        }

        void newApple() {
            delete this->target;
            this->target = new Apple((rand() % this->width) + 1, (rand() % this->height) + 1);
        }

        void cleanUp() {
            getch();
            endwin();
            delete this->player;
            delete this->target;
            delete this->body;
        }

        void drawCanvas() {
            for (int w=0; w <= this->width+1; w++) {
                mvprintw(0, w, Canvas::border.c_str());
                mvprintw(this->height+1, w, Canvas::border.c_str());
            }

            for (int h=1; h <= this->height; h++) {
                mvprintw(h, 0, Canvas::border.c_str());
                mvprintw(h, this->width+1, Canvas::border.c_str());
            }
        }

        void checkDeath() {
            for (int i=1; i < this->body->positions.size(); i++) {
                if (this->body->positions[i][0] == this->player->pos[0] && this->body->positions[i][1] == this->player->pos[1]) {
                    this->alive = false;
                    this->player->direction = NONE;
                }
            }
        }
};