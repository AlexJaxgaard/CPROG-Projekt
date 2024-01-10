#include "Component.h"
#include <string>
#include "System.h"
#include "Session.h"
#include <iostream>
#include "GameObject.h"

class Snake : public GameObject{

public:

    Snake(int x, int y, int w, int h, std::string txt, cwing::Session &ses);

    Snake* getInstance(int x, int y, int w, int h, std::string txt, cwing::Session &ses);

    ~Snake();

    void mouseDown(const SDL_Event &);
    void mouseUp(const SDL_Event &);
    void keyDown(const SDL_Event &);
    void keyUp(const SDL_Event &);
    void mouseMotion(const SDL_Event &);
    void draw() const;
    void tick();
    void collision(Component *comp);
    void move();

private:
    int direction = 0;

    SDL_Rect head;

};