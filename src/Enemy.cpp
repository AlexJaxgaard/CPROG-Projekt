#include "Enemy.h"
#include "Constants.h"
#include <iostream>

Enemy::Enemy(int x, int y, int w, int h, int velocity, cwing::Session &ses)
    : cwing::Component(x, y, w, h, "images/medium.bmp"),
      velocity(velocity),
      text("images/medium.bmp"),
      ses(ses),
      lives(2),
      rectangle{x, y, w, h}
{

        std::cout << "Creating enemy with parameters: " << x << ", " << y << ", " << w << ", " << h << ", " << velocity << std::endl;

}

    void Enemy::tick()
    {
        //moveForward();
        
        if (getRect().x + getRect().w < 0 || getRect().x > ses.getScreenWidth() ||
            getRect().y + getRect().h < 0 || getRect().y > ses.getScreenHeight())
        {
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
        cwing::Component::draw();
    }
