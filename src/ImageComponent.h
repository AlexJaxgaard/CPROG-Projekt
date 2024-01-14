
#ifndef IMAGECOMPONENT_H
#define IMAGECOMPONENT_H
#include "Constants.h"
#include "Component.h"
#include <string>
#include "System.h"
#include "Session.h"

class ImageComponent : public cwing::Component
{

private:
    std::string text;
    SDL_Rect rectangle;
    std::string label = "imagecomponent";

protected:
public:
    ImageComponent(int xpos, int ypos, int width, int height, std::string txt);
    void draw() const override;
    void tick() override;
    const SDL_Rect &getRect() const { return rectangle; }
    void collision(Component *comp) override;
    std::string getLabel() override { return label; }
    ~ImageComponent();
};

#endif