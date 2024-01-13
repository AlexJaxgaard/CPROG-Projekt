#include "Component.h"
#include "Session.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.h"
#include <iostream>
#include <Constants.h>
namespace cwing
{

	Component::Component(int x, int y, int w, int h, std::string txt) : rect{x, y, w, h}
	{

		SDL_Surface *surf = IMG_Load((constants::gResPath + txt).c_str());
		if (surf == NULL)
		{
			std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
		}
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
		if (texture == NULL)
		{
			std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
		}
		SDL_FreeSurface(surf);
	}
	void Component::draw() const
	{
		SDL_RenderCopy(cwing::sys.get_ren(), texture, NULL, &rect);
	}

	Component::~Component()
	{

		if (texture != NULL)
		{
			SDL_DestroyTexture(texture);
			texture = NULL;
		}
	}

}