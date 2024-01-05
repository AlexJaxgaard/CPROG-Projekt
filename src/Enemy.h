#include "Component.h"
#include <string>
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "System.h"
#include "Session.h"
//Spelklass
//namespace cwing
//{

    class Enemy : public cwing::Component
    {
    public:
        Enemy(int x, int y, int w, int h, std::string txt, std::string difficulty, int velocity);
        ~Enemy();
        void draw() const;
        TransformComponent *tc;
        void hit();
        void moveForward();
        bool dead();
        void tick();
        const SDL_Rect &getRect() const { return rectangle; } // Kan finnas i Component

    protected:
        Component *sc;
        int velocity;

    private:
        int x;
        int y;
        int w;
        int h;
        int lives;
        std::string text;
        SDL_Texture *texture;
        SDL_Rect rectangle;
    };

//}