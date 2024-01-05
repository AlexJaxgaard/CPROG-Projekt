#include "TextComponent.h"
namespace cwing
{
    TextComponent::TextComponent(int xpos, int ypos, int width, int height, std::string text) : x(xpos), y(ypos), w(width), h(height), text(text), label("textcomponent")
    {
        font = TTF_OpenFont((constants::gResPath + "/fonts/Kalnia/Kalnia.ttf").c_str(), 36);
        if (font == NULL)
        {
            std::cout << "Failed to load text: " << TTF_GetError() << std::endl;
        }

        color = {0, 0, 0};
        surface = TTF_RenderText_Solid(font, text.c_str(), color);

        if (surface == NULL)
        {
            std::cout << "Failed to load text: " << TTF_GetError() << std::endl;
        }

        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surface);

        if (texture == NULL)
        {
            std::cout << "Failed to load text: " << TTF_GetError() << std::endl;
        }

        rectangle = {x, y, surface->w, surface->h};
        if (surface == NULL)
        {
            std::cout << "Failed to load text: " << TTF_GetError() << std::endl;
        }
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surface);
        if (texture == NULL)
        {
            std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
        }
        rectangle = {0, 0, w, h};
        SDL_FreeSurface(surface);
    }

    void TextComponent::setText(std::string newText)
    {

        this->text = newText;
        surface = TTF_RenderText_Solid(font, text.c_str(), color);
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surface);
        rectangle = {x, y, surface->w, surface->h};
        if (surface == NULL)
        {
            std::cout << "Failed to load text: " << TTF_GetError() << std::endl;
        }
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surface);
        if (texture == NULL)
        {
            std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
        }
        rectangle = {0, 0, w, h};
        SDL_FreeSurface(surface);
    }

    void TextComponent::draw() const
    {
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &rectangle);
    }

}