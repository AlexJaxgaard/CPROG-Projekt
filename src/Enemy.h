#include "Component.h"
#include <SDL2/SDL.h>
#include <string>
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "System.h"
#include "Session.h"

namespace cwing
{

    class Enemy : public Component
    {
    public:
        Enemy(int x, int y, int w, int h, std::string txt, std::string difficulty);
        ~Enemy();
        void draw() const;
        TransformComponent *tc;
        void hit();

    protected:
        int x;
        int y;
        int w;
        int h;
        int lives;
        std::string text;
        SDL_Texture *texture;
        SDL_Rect rectangle;
        Component *sc;

    private:
    };

}