/*#pragma once

#include "Session.h"

namespace cwing
{

    class TransformComponent : public Component
    {

    private:
        int xpos;
        int ypos;
        int wsize;
        int hsize;

    public:
        TransformComponent(int x, int y, int w, int h)
            : Component(xpos, ypos, wsize, hsize), xpos(x), ypos(y), wsize(w), hsize(h)
        {
        }

        void update(int x, int y, int w, int h)
        {
            xpos += x;
            ypos += y;
            wsize += w;
            hsize += h;
        }

        int x() { return xpos; }
        void x(int x) { xpos = x; }
        int y() { return ypos; }
        void y(int y) { ypos = y; }
        void setPos(int x, int y)
        {
            xpos = x;
            ypos = y;
        }
        int w() { return wsize; }
        void w(int w) { wsize = w; }
        int h() { return hsize; }
        void h(int h) { hsize = h; }
        void setSize(int w, int h)
        {
            wsize = w;
            hsize = h;
        }
        void draw() const override {}
    };

}*/