
#ifndef IMAGECOMPONENT_H
#define IMAGECOMPONENT_H
#include "Constants.h"
#include "Component.h"
#include <SDL2/SDL.h>
#include <string>

#include "System.h"
#include "Session.h"
#include <SDL2/SDL_ttf.h>

#include <SDL2/SDL_image.h>

namespace cwing
{

    class ImageComponent : public Component
    {
    public:
        ImageComponent(int xpos, int ypos, int width, int height, std::string txt);
        void draw() const override;
        void tick() override;
        void collision(Component *comp) override;
        std::string getLabel() override { return label; }
        ~ImageComponent();

    protected:
    private:
        int x;
        int y;
        int w;
        int h;
        std::string text;
        SDL_Texture *texture;
        SDL_Rect rectangle;
        bool drag;
        std::string label = "imagecomponent";
    };

}

#endif