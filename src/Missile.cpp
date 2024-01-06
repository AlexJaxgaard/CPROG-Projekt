
#include "Constants.h"
#include "GameObject.h"
#include <SDL2/SDL_ttf.h>

#include <SDL2/SDL_image.h>
#include <iostream>
#include "Missile.h"

namespace cwing
{

    Missile::Missile(int xpos, int ypos, Session &ses) : Component(xpos, ypos, 30, 30), x(xpos), y(ypos), ses(ses)
    {

        SDL_Surface *surf = IMG_Load((constants::gResPath + "/images/missile.bmp").c_str());
        if (surf == NULL)
        {
            std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
        }
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        if (texture == NULL)
        {
            std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
        }
        rectangle = {x, y, 30, 30};
        SDL_FreeSurface(surf);
    }

    void Missile::tick()
    {

        SDL_Rect rect = this->getRect();
        if (rect.x + rect.w < 0 || rect.x > ses.getScreenWidth() ||
            rect.y + rect.h < 0 || rect.y > ses.getScreenHeight())
        {
            // If it is, add it to the removed vector
            ses.remove(this);
        }
        else
        {
            moveForward();
        }
    }

    void Missile::collision(Component *c)
    {
        if (c->getLabel() == "enemy")
        {
            hit();
        }
    }

    void Missile::draw() const
    {
        if (isExploding)
        {
            SDL_RenderCopy(sys.get_ren(), spriteSheet, &sourceRects[currentFrame], &rectangle);
        }
        else
        {
            SDL_RenderCopy(sys.get_ren(), texture, NULL, &rectangle);
        }
    }

    void Missile::moveForward()
    {

        y--;
        rectangle.y--;
        setRect(rectangle.x, rectangle.y, rectangle.w, rectangle.h);
    }

    void Missile::hit()
    {
        if (!isExploding)
        {
            isExploding = true;
            explosionStart = SDL_GetTicks();

            // Load the explosion sprite sheet
            SDL_Surface *surf = IMG_Load((constants::gResPath + "spritesheets/explosionsheet.bmp").c_str());

            if (surf == nullptr)
            {
                std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
                return;
            }

            spriteSheet = SDL_CreateTextureFromSurface(sys.get_ren(), surf);

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

}