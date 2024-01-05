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
        void colission(Component *c);
        void tick();
        std::string getLabel() {return label;}

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
        bool isExploding = false;
        SDL_Texture *spriteSheet = nullptr;
        std::vector<SDL_Rect> sourceRects;
        int currentFrame = 0;
        Uint32 explosionStart;
        std::string label;
    };

}