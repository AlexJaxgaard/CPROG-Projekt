#include "ImageComponent.h"
namespace cwing
{

    ImageComponent::ImageComponent(int xpos, int ypos, int width, int height, std::string txt) : Component(xpos, ypos, width, height), x(xpos), y(ypos), w(width), h(height)
    {
        SDL_Surface *surf = IMG_Load((constants::gResPath + "images/" + txt).c_str());
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        rectangle = {x, y, w, h};//0, 0 blev x, y
        SDL_FreeSurface(surf);
    }

    void ImageComponent::draw() const
    {
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &rectangle);
    }

    void ImageComponent::tick()
    {
    }

    void ImageComponent::collision(Component *comp)
    {
    }

    ImageComponent::~ImageComponent()
    {
    }

}