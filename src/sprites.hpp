#include <vector>
enum directions {UP, DOWN, LEFT, RIGHT, NONE};

class Snake
{
    public:
        int pos[2];
        int length;
        directions direction;
        int screen_width;
        int screen_height;

        Snake(int x_pos, int y_pos) {
            this->pos[0] = x_pos;
            this->pos[1] = y_pos;
            this->direction = RIGHT;
        }

        void setd(int sw, int sh) {this->screen_width = sw; this->screen_height = sh;}

        void update() {
            this->move();
        }

        void move() {
            switch (this->direction) {
                case DOWN:
                    if (this->pos[1] < this->screen_height) {
                        pos[1]++;
                    } else {
                        this->pos[1] = this->screen_height;
                        this->direction = NONE;
                    }
                    break;
                case UP:
                    if (this->pos[1] > 1) {
                        this->pos[1]--;
                    } else {
                        this->pos[1] = 1;
                        this->direction = NONE;
                    }
                    break;
                case RIGHT:
                    if (this->pos[0] < this->screen_width) {
                        this->pos[0]++;
                    } else {
                        this->pos[0] = this->screen_width;
                        this->direction = NONE;
                    }
                    break;
                case LEFT:
                    if (this->pos[0] > 1) {
                        this->pos[0]--;
                    } else {
                        this->pos[0] = 1;
                        this->direction = NONE;
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


            this->positions.push_back(pos);
        }

        void add_tail(directions dir) {
            std::vector<int> pos;

            int ilp = this->positions.size()-1;
            std::vector<int> last_pos = this->positions[ilp];

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
                case NONE: break;
            }

            this->positions.push_back(pos);
        }

        void update_tail(int head_posx, int head_posy) {
            std::vector<std::vector<int> > temp;
            std::vector<int> head;
            head.push_back(head_posx);
            head.push_back(head_posy);
            for (std::vector<int> pos : this->positions) {
                temp.push_back(pos);
            }

            for (int i = 1; i < positions.size(); i++) {
                this->positions[i] = temp[i-1];
            }

            this->positions[0] = head;
        }
};

class Apple
{
    public:
        int pos[2];

        Apple(int x_pos, int y_pos) {
            this->pos[0] = x_pos;
            this->pos[1] = y_pos;
        }
};