#include "Enemy.h"
#include <SDL2/SDL_ttf.h>
#include "Constants.h"
#include <SDL2/SDL_image.h>
#include <iostream>
namespace cwing
{

    Enemy::Enemy(int x, int y, int w, int h, std::string txt, std::string difficulty, int velocity, Session &ses) : Component(x, y, w, h), x(x), y(y), w(h), h(h), velocity(velocity), ses(ses)
    {

        SDL_Surface *surf = IMG_Load((constants::gResPath + txt).c_str());

        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);

        rectangle = {x, y, w, h};
        SDL_FreeSurface(surf);

        if (difficulty == "easy")
        {
            lives = 1;
        }
        else if (difficulty == "medium")
        {
            lives = 2;
        }
        else
        {
            lives = 3;
        }
    }

    void Enemy::tick()
    {
        moveForward();
        SDL_Rect rect = this->getRect();
        if (rect.x + rect.w < 0 || rect.x > ses.getScreenWidth() ||
            rect.y + rect.h < 0 || rect.y > ses.getScreenHeight())
        {
            // If it is, add it to the removed vector
            ses.remove(this);
        }

        if (dead())
        {
            ses.remove(this);
        }
    }

    void Enemy::collision(Component *comp)
    {
        if (comp->getLabel() == "missile")
        {
            hit();
            std::cout << "enemy hit!" << std::endl;
        }
    }

    void Enemy::hit()
    {
        if (lives - 1 <= 0)
        {
            lives = 0;
        }
        else
        {
            lives--;
        }
    }

    bool Enemy::dead()
    {
        return lives <= 0;
    }

    void Enemy::moveForward()
    {
        rectangle.y += velocity;
        y += velocity;
        setRect(rectangle.x, rectangle.y, rectangle.w, rectangle.h);
    }

    Enemy::~Enemy()
    {
    }

    void Enemy::draw() const
    {
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &rectangle);
    }

}