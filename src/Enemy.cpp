#include "Enemy.h"
#include "Constants.h"
#include <iostream>
namespace cwing
{

    Enemy::Enemy(int x, int y, int w, int h, std::string txt, std::string difficulty, int velocity) : Component(x, y, w, h, "enemy"), x(x), y(y), w(h), h(h), velocity(velocity)
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

        if (dead())
        {
            velocity = 0;
        }
    }

    bool Enemy::dead()
    {
        return lives <= 0;
    }

    void Enemy::tick()
    {

        moveForward();
    }

    void Enemy::colission(Component *comp)
    {

        if (comp->getLabel() == "missile"){
            hit();
        } 
    
    }

    void Enemy::moveForward()
    {
        rectangle.y += velocity;
        y += velocity;
    }

    Enemy::~Enemy()
    {
    }

    void Enemy::draw() const
    {
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &rectangle);
    }

}