#include "Enemy.h"
#include <SDL2/SDL_ttf.h>
#include "Constants.h"
#include <SDL2/SDL_image.h>
namespace cwing
{

    Enemy::Enemy(int x, int y, int w, int h, std::string txt, std::string difficulty) : Component(x, y, w, h), x(x), y(y), w(h), h(h)
    {

        SDL_Surface *surf = IMG_Load((constants::gResPath + txt).c_str());

        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);

        rectangle = {x, y, w, h};
        SDL_FreeSurface(surf);
        tc = new TransformComponent(x, y, w, h);
        sc = new SpriteComponent("");

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
            
        }
    }

    Enemy::~Enemy()
    {
    }

    void Enemy::draw() const
    {
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &rectangle);
    }

}