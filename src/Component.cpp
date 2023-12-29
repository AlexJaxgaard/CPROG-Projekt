#include "Component.h"
#include "Session.h"
#include <SDL2/SDL.h>
namespace cwing
{
	Component::Component(){
		this->rect = SDL_Rect();
	}

	Component::Component(int x, int y, int w, int h) : rect{x, y, w, h}
	{
		this->rect = rect;
	}

	Component::~Component()
	{
		

		/*Implementation*/
	}

	SDL_Rect rect;

}