#include "Component.h"
#include <SDL2/SDL.h>
#include <string>
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "System.h"
#include "Session.h"

namespace cwing
{

    class Missile : public Component{
        
        Missile();
        ~Missile();
        void draw() const{}
        



    };


}