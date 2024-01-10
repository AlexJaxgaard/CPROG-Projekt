#include "Snake.h"
using namespace std;

enum Direction
{
    DOWN,
    LEFT,
    RIGHT,
    UP
};

Snake::Snake(int x, int y, int w, int h, std::string txt, cwing::Session &ses) : GameObject(x, y, w, h, txt, ses){
    head = getRect();
}

Snake* Snake::getInstance(int x, int y, int w, int h, std::string txt, cwing::Session &ses){
    return new Snake(x, y, w, h, txt, ses);
}


void Snake::keyDown(const SDL_Event &event)
{

    if (event.key.keysym.sym == SDLK_DOWN)
    {
        cout << "turning down "  << endl;
        direction = DOWN;
    }
    else if (event.key.keysym.sym == SDLK_UP)
    {
        cout << "turning up " << endl;
        direction = UP;
    }
    else if (event.key.keysym.sym == SDLK_LEFT)
    {
        cout << "turning left " << endl;
        direction = LEFT;
    }
    else if (event.key.keysym.sym == SDLK_RIGHT)
    {
        cout << "turning right " << endl;
        direction = RIGHT;
    }
}

void Snake::move(){
    switch(direction)
    {
        case DOWN:
            head.y += 10;
            break;
        case UP:
            head.y -= 10;
            break;
        case LEFT:
            head.x -= 10;
            break;
        case RIGHT:
            head.x += 10;
            break;
    }
}

void Snake::draw()const{
    GameObject::draw();
}

void Snake::tick(){
    move();
    setRect(head.x, head.y, head.w, head.h);

}