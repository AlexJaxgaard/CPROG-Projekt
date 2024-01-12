#include "Enemy.h"
#include <SDL2/SDL_ttf.h>
#include "Constants.h"
#include <SDL2/SDL_image.h>
#include <iostream>

Enemy::Enemy(int x, int y, int w, int h, std::string txt, std::string difficulty, int velocity, cwing::Session &ses)
    : cwing::Component(x, y, w, h, txt),
      velocity(velocity),
      text(txt),
      ses(ses)
{

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
        
        if (rectangle.x + rectangle.w < 0 || rectangle.x > ses.getScreenWidth() ||
            rectangle.y + rectangle.h < 0 || rectangle.y > ses.getScreenHeight())
        {
            // If it is, add it to the removed vector
            ses.remove(this);
        }
    }

    void Enemy::collision(Component *comp)
    {

        if (comp->getLabel() == "missile")
        {   
           
        }


    }

    void Enemy::hit()
    {

       if (!isDead()){
            lives--;
       }
    }

    void Enemy::moveForward()
    {
        rectangle.y += velocity;
        Component::setRect(rectangle.x, rectangle.y, rectangle.w, rectangle.h);
    }

    Enemy::~Enemy()
    {
    }

    void Enemy::draw() const
    {
        Component::draw();
    }
