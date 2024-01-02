#include "Component.h"
#include "TransformComponent.h"

#include <SDL2/SDL.h>
#include <string>

namespace cwing
{
    class SpriteComponent : public Component
    {
    
    private:
        SDL_Texture* texture;

    public:
        SpriteComponent(std::string texture){}
        SpriteComponent(){}
        void draw() const override{

        }





    };
}