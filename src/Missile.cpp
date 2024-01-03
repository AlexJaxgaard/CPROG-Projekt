
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
        rectangle = {x, y, 30,30};
        SDL_FreeSurface(surf);
        tc = new TransformComponent(x, y, 30, 30);
        sc = new SpriteComponent("");
    }

    void Missile::draw() const
    {
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &rectangle);
        
    }

    void Missile::moveForward(){
        y--;
        rectangle.y--;
    }

}