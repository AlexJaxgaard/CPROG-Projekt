#include "Component.h"
#include <SDL2/SDL.h>
#include <string>
#include "System.h"
#include "Session.h"

namespace cwing
{

    class Enemy : public Component 
    {
    public:
        Enemy(int x, int y, int w, int h, std::string txt, std::string difficulty, int velocity);
        ~Enemy();
        void draw() const;
        void hit();
        void moveForward();
        bool dead();
        const SDL_Rect &getRect() const { return rectangle; }
        void tick() override;
        void collision(Component *comp) override;
        std::string getLabel() override {return label;}

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
        std::string label = "enemy";
    };

}