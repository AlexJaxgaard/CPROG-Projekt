
#include "Constants.h"
#include "Player.h"
#include <SDL2/SDL_ttf.h>

#include <SDL2/SDL_image.h>
#include <iostream>
#include "Missile.h"
#include "Enemy.h"

Missile::Missile(int xpos, int ypos, cwing::Session &ses)
    : cwing::Component(xpos, ypos, 30, 30, "/images/missile.bmp"),
      rect{xpos, ypos, 30, 30},
      ses(ses),
      hasExploded(false)
{
}

void Missile::tick()
{

    if (getRect().x + getRect().w < 0 || getRect().x > ses.getScreenWidth() ||
        getRect().y + getRect().h < 0 || getRect().y > ses.getScreenHeight())
    {
        ses.remove(this);
    }
    else
    {
        moveForward();
    }

    if (isExploding)
    {
        Uint32 now = SDL_GetTicks();
        Uint32 elapsedTime = now - explosionStart;
        currentFrame = elapsedTime / 167;

        if (static_cast<size_t>(currentFrame) >= sourceRects.size())
        {
            ses.remove(this);
        }
    }
}

void Missile::collision(cwing::Component *c)
{
    if (c->getLabel() == "enemy")
    {
        if (!hasExploded)
        {
            hit();
            dynamic_cast<Enemy *>(c)->hit();
            if (dynamic_cast<Enemy *>(c)->isDead())
            {
                ses.remove(c);
            }
            hasExploded = true;
        }
    }
}

void Missile::draw() const
{
    if (isExploding)
    {

        SDL_RenderCopy(cwing::sys.get_ren(), spriteSheet, &sourceRects[currentFrame], &rect);
        
    }
    else
    {
        Component::draw();
    }
}

void Missile::moveForward()
{

    rect.y--;
    Component::setRect(rect.x, rect.y, rect.w, rect.h);
}

void Missile::hit()
{
    if (!isExploding)
    {
        cwing::sys.play_sound("explosion.wav");
        isExploding = true;
        explosionStart = SDL_GetTicks();

        // Load the explosion sprite sheet
        SDL_Surface *surf = IMG_Load((constants::gResPath + "spritesheets/explosionsheet.bmp").c_str());

        if (surf == nullptr)
        {
            std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
            return;
        }

        SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 255, 255, 255));

        spriteSheet = SDL_CreateTextureFromSurface(cwing::sys.get_ren(), surf);

        if (spriteSheet == nullptr)
        {
            std::cout << "Failed to load texture: " << IMG_GetError() << std::endl;
            return;
        }

        // Define the source rectangle for each frame
        int frameWidth = surf->w / 3;  // Assuming 3 frames per row
        int frameHeight = surf->h / 2; // Assuming 2 rows
        sourceRects.clear();
        for (int i = 0; i < 6; i++)
        {
            SDL_Rect rect = {(i % 3) * frameWidth, (i / 3) * frameHeight, frameWidth, frameHeight};
            sourceRects.push_back(rect);
        }
        SDL_FreeSurface(surf);
    }
}
