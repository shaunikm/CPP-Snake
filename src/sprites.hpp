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

        Snake(int x_pos, int y_pos) {
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

class Tail
{
    public:
        std::vector<std::vector<int> > positions;
        int length = 0;

        void add_tail(int x_pos, int y_pos) {
            std::vector<int> pos;
            pos.push_back(x_pos);
            pos.push_back(y_pos);

            positions.push_back(pos);
        }

        void add_tail(directions dir) {
            std::vector<int> pos;

            int ilp = positions.size()-1;
            std::vector<int> last_pos = positions[ilp];

            switch (dir) {
                case DOWN:
                    pos.push_back(last_pos[0]);
                    pos.push_back(last_pos[1]+1);
                    break;
                case UP:
                    pos.push_back(last_pos[0]);
                    pos.push_back(last_pos[1]-1);
                    break;
                case RIGHT:
                    pos.push_back(last_pos[0]-1);
                    pos.push_back(last_pos[1]);
                    break;
                case LEFT:
                    pos.push_back(last_pos[0]-1);
                    pos.push_back(last_pos[1]);
                    break;
            }

            positions.push_back(pos);
        }

        void update_tail(int head_posx, int head_posy) {
            std::vector<std::vector<int> > temp;
            std::vector<int> head;
            head.push_back(head_posx);
            head.push_back(head_posy);
            for (std::vector<int> pos : positions) {
                temp.push_back(pos);
            }

            for (int i = 1; i < positions.size(); i++) {
                positions[i] = temp[i-1];
            }

            positions[0] = head;
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