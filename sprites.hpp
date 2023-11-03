#include <vector>

class Snake
{
    public:
        int pos[2];
        int length;
        char direction = 'e';
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
                case 'n':
                    if (pos[1] < screen_height) {
                        pos[1] += 1;
                    } else {
                        pos[0] = screen_height;
                        direction = ' ';
                    }
                    break;
                case 's':
                    if (pos[1] > 0) {
                        pos[1] -= 1;
                    } else {
                        pos[1] = 0;
                        direction = ' ';
                    }
                    break;
                case 'e':
                    if (pos[0] < screen_width) {
                        pos[0] += 1;
                    } else {
                        pos[0] = screen_width;
                        direction = ' ';
                    }
                    break;
                case 'w':
                    if (pos[0] > 1) {
                        pos[0] -= 1;
                    } else {
                        pos[0] = 1;
                        direction = ' ';
                    }
                    break;
                default: break;
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