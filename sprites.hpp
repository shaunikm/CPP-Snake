#include <vector>
enum directions {UP, DOWN, LEFT, RIGHT, NONE};

class Snake
{
    public:
        int pos[2];
        int length;
        directions direction = RIGHT;
        int screen_width;
        int screen_height;

        Snake(int x_pos, int y_pos, int sw, int sh) {
            pos[0] = x_pos;
            pos[1] = y_pos;
        }

        void setd(int sw, int sh) {screen_width = sw; screen_height = sh;}

        void update() {
            move();
        }

        void move() {
            switch (direction) {
                case DOWN:
                    if (pos[1] < screen_height) {
                        pos[1]++;
                    } else {
                        pos[1] = screen_height;
                        direction = NONE;
                    }
                    break;
                case UP:
                    if (pos[1] > 1) {
                        pos[1]--;
                    } else {
                        pos[1] = 1;
                        direction = NONE;
                    }
                    break;
                case RIGHT:
                    if (pos[0] < screen_width) {
                        pos[0]++;
                    } else {
                        pos[0] = screen_width;
                        direction = NONE;
                    }
                    break;
                case LEFT:
                    if (pos[0] > 1) {
                        pos[0]--;
                    } else {
                        pos[0] = 1;
                        direction = NONE;
                    }
                    break;
                case NONE: break;
            }
        }
};

class Apple
{
    public:
        int pos[2];

        Apple(int x_pos, int y_pos) {
            pos[0] = x_pos;
            pos[1] = y_pos;
        }
};