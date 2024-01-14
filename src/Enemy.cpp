/*
---------
Alexander Jaxgård ALJA9460
Elias Bennaceur ELBE7219
---------
*/
#include "Constants.h"
#include "Enemy.h"

#include <iostream>

Enemy::Enemy(int x, int y, int w, int h, cwing::Session &ses)
    : cwing::Component(x, y, w, h, "images/medium.bmp"),
      velocity(1),
      text("images/medium.bmp"),
      ses(ses),
      lives(2),
      rectangle{x, y, w, h}
{
}

void Enemy::tick()
{

    if (ses.getCurrentTick() % 10 == 0)
    {
        moveForward();
    }

    if (getRect().x + getRect().w < 0 || getRect().x > ses.getScreenWidth() ||
        getRect().y + getRect().h < 0 || getRect().y > ses.getScreenHeight())
    {
        ses.remove(this);
    }
}

void Enemy::hit()
{

    if (!isDead())
    {
        lives--;
    }
}

void Enemy::moveForward()
{
    rectangle.y += velocity;
    Component::setRect(rectangle.x, rectangle.y, rectangle.w, rectangle.h);
}

void Enemy::draw() const
{
    cwing::Component::draw();
}
