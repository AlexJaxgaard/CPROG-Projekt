#include "Component.h"

namespace cwing
{

	Component::Component() {}

	Component::Component(int x, int y, int w, int h) : rect{x, y, w, h}
	{
	}

	Component::~Component()
	{

		/*Implementation*/
	}

	SDL_Rect rect;

}