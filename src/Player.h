#pragma once

#include "Component.h"

namespace cwing
{
    class Player : public Component
    {

    private:
        int xpos;
        int ypos;
        int wsize;
        int hsize;

    public:
        Player(int x, int y, int w, int h) : xpos(x), ypos(y), wsize(w), hsize(h), Component(xpos, ypos, wsize, hsize)
        {
        }

        void mouseDown(const SDL_Event &) override { xpos--; }
        void mouseUp(const SDL_Event &) override { xpos++; }
        void keyDown(const SDL_Event &) override { xpos--; }
        void keyUp(const SDL_Event &) override { xpos++; }
        void draw() const override{

        };

    };

} // namespace cwing
