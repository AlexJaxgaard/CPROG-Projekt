#ifndef CWING_TEXT_COMPONENT_H
#define CWING_TEXT_COMPONENT_H

#include "Component.h"
#include "Constants.h"
#include "GameObject.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>

namespace cwing
{

    class TextComponent : public Component
    {
    public:
        TextComponent(int xpos, int ypos, int width, int height, std::string text);
        void setText(std::string text);
        TransformComponent *tc;
        void draw() const;

    protected:
        Component *sc;

    private:
        int x;
        int y;
        int w;
        int h;
        std::string text;
        SDL_Texture *texture;
        SDL_Rect rectangle;
        SDL_Surface *surface;
        SDL_Color color;
        TTF_Font *font;
    };
}

#endif