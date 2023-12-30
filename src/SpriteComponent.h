#include "Component.h"
#include "TransformComponent.h"
#include <SDL2/SDL.h>
#include <string>

namespace cwing
{
    class SpriteComponent : Component
    {
    
    private:
        SDL_Texture* texture;

    public:
        SpriteComponent(std::string texture);



    };
}