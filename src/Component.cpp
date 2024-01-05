#include "Component.h"

namespace cwing
{

	Component::Component() {}

	Component::Component(int x, int y, int w, int h, std::string label) : rect{x, y, w, h}, label(label)
	{
	}

	Component::~Component()
	{

		/*Implementation*/
	}

	SDL_Rect rect;

}