
#include "Constants.h"
#include "GameObject.h"
#include <SDL2/SDL_ttf.h>

#include <SDL2/SDL_image.h>
#include <iostream>
#include "Missile.h"

namespace cwing
{

    Missile::Missile(int xpos, int ypos) : x(xpos), y(ypos)
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
        tc = new TransformComponent(x, y, 30, 30);
        sc = new SpriteComponent("");
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

        if (isExploding)
        {
            // Check if 100 milliseconds have passed since the last frame
            if (SDL_GetTicks() - explosionStart >= 100)
            {
                // Go to the next frame
                currentFrame++;
                if (currentFrame >= sourceRects.size())
                {
                    // All frames have been displayed, so the explosion is over
                    isExploding = false;
                    SDL_DestroyTexture(spriteSheet);
                    spriteSheet = nullptr;
                }

                // Reset the explosion timer
                explosionStart = SDL_GetTicks();
            }
        }
        else
        {
            y--;
            rectangle.y--;
        }
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