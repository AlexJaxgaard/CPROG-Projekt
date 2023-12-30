#include "Component.h"
#include "Session.h"
#include <SDL2/SDL.h>
namespace cwing
{

	Component::Component(int x, int y, int w, int h) : rect{x, y, w, h}
	{
	}

	Component::~Component()
	{

		/*Implementation*/
	}

	SDL_Rect rect;

}