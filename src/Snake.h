#include "Component.h"
#include <string>
#include "System.h"
#include "Session.h"
#include <iostream>

class Snake : public cwing::Component{

    Snake(int x, int y, int w, int h);


    void mouseDown(const SDL_Event &);
    void mouseUp(const SDL_Event &);
    void keyDown(const SDL_Event &);
    void keyUp(const SDL_Event &);
    void mouseMotion(const SDL_Event &);
    void draw() const = 0;
    void tick() = 0;
    void collision(Component *comp) = 0;

    int direction = 0;

    SDL_Rect head;

};