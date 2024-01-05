#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL2/SDL.h>
#include "Session.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
<<<<<<< Updated upstream
#include <String>
=======
#include <string>
>>>>>>> Stashed changes

namespace cwing
{
    class Component
    {
    public:
        Component();
        ~Component();
        virtual void mouseDown(const SDL_Event &) {}
        virtual void mouseUp(const SDL_Event &) {}
        virtual void keyDown(const SDL_Event &) {}
        virtual void keyUp(const SDL_Event &) {}
        virtual void mouseMotion(const SDL_Event &) {}
        virtual void draw() const = 0;
        virtual void tick() = 0;
        virtual void colission(Component *comp) = 0;
        virtual std::string getLabel() { return label; }

        const SDL_Rect &getRect() const { return rect; }
        virtual std::string getLabel() {return label;}

    protected:
        Component(int x, int y, int w, int h, std::string label);

    private:
        SDL_Rect rect;
        Component(const Component &) = delete;
        const Component &operator=(const Component &) = delete;
<<<<<<< Updated upstream
        std::string label;
=======
        std::string label = "";
>>>>>>> Stashed changes
    };
}

#endif