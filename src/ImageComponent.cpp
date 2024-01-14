/*
---------
Alexander Jaxgård ALJA9460
Elias Bennaceur ELBE7219
---------
*/
#include "Constants.h"
#include "ImageComponent.h"

ImageComponent::ImageComponent(int xpos, int ypos, int width, int height, std::string txt) : cwing::Component(xpos, ypos, width, height, "images/" + txt), text(txt), rectangle{xpos, ypos, width, height}
{
}

void ImageComponent::draw() const
{
    cwing::Component::draw();
}