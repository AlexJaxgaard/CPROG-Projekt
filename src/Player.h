#include "Component.h"
#include <SDL2/SDL.h>
#include <string>
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "System.h"
#include "Session.h"

namespace cwing
{

    class Player
    {
    
    public:
        Player();
        void increasePoints();
        int getPoints() {return points;}


    protected:

    private:
        int points;
    };

}