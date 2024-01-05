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
<<<<<<< Updated upstream
        void colission();
        void tick();
        std::string getLabel() {return label;}
=======
        void tick();
        void colission(Component *c);
        std::string getLabel() { return label; }
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
        std::string label = "";
=======
        std::string label;
>>>>>>> Stashed changes
    };

}