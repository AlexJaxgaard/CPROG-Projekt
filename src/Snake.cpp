#include "Snake.h"
using namespace std;

enum Direction
{
    DOWN,
    LEFT,
    RIGHT,
    UP
};

Snake::Snake(int x, int y, int w, int h) : cwing::Component(x, y, w, h){
    
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