#include "Component.h"
#include <SDL2/SDL.h>
#include <string>
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "System.h"
#include "Session.h"

namespace cwing
{

    class Missile : public Component
    {

    public:
        Missile(int xpos, int ypos);
        ~Missile();
        void draw() const;
        void moveForward();
        TransformComponent *tc;
        const SDL_Rect &getRect() const { return rectangle; }
        void hit();

    protected:
        Component *sc;
        SDL_Rect rectangle;

    private:
        int x;
        int y;
        int w;
        int h;
        std::string text;
        SDL_Texture *texture;
        bool explosionTriggered = false;
    };

}