
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
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &rectangle);
    }

    void Missile::moveForward()
    {
        y--;
        rectangle.y--;
    }

    void Missile::hit()
    {

        if (explosionTriggered)
        {
            return;
        }

        // Load the explosion sprite sheet
        SDL_Surface *surf = IMG_Load((constants::gResPath + "spritesheets/explosionsheet.bmp").c_str());

        if (surf == nullptr)
        {
            std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
            return;
        }

        SDL_Texture *spriteSheet = SDL_CreateTextureFromSurface(sys.get_ren(), surf);

        if (spriteSheet == nullptr)
        {
            std::cout << "Failed to load texture: " << IMG_GetError() << std::endl;
            return;
        }

        SDL_FreeSurface(surf);

        // Define the source rectangle for each frame
        int frameWidth = surf->w / 3;  // Assuming 3 frames per row
        int frameHeight = surf->h / 2; // Assuming 2 rows
        std::vector<SDL_Rect> sourceRects;
        for (int i = 0; i < 6; i++)
        {
            SDL_Rect rect = {(i % 3) * frameWidth, (i / 3) * frameHeight, frameWidth, frameHeight};
            sourceRects.push_back(rect);
        }
        // Start the explosion timer
        Uint32 explosionStart = SDL_GetTicks();

        // Display the explosion frames one by one
        for (SDL_Rect &sourceRect : sourceRects)
        {
            // Check if 100 milliseconds have passed since the last frame
            if (SDL_GetTicks() - explosionStart >= 100)
            {
                SDL_RenderCopy(sys.get_ren(), spriteSheet, &sourceRect, &rectangle);
                SDL_RenderPresent(sys.get_ren());

                // Reset the explosion timer
                explosionStart = SDL_GetTicks();
            }
        }

        explosionTriggered = true;
        SDL_DestroyTexture(spriteSheet);
    }

}