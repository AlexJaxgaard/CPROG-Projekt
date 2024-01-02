#include "Session.h"
#include <SDL2/SDL.h>
#include "System.h"
#include "Component.h"

#include <iostream>

#define FPS 80

namespace cwing
{

	Session::Session()
	{
		std::cout << "*** Session::Session()\n";
	}

	void Session::add(Component *c)
	{
		comps.push_back(c);
		added.push_back(c);
		c->draw();
	}

	/*void Session::add(Component* comp) {
		added.push_back(comp);
	}*/

	void Session::remove(Component *comp)
	{
		removed.push_back(comp);
	}

	void Session::run()
	{
		bool quit = false;
		Uint32 tickInterval = 1000 / FPS;
		while (!quit)
		{

			// modified
			Uint32 nextTick = SDL_GetTicks() + tickInterval;

			SDL_Event eve;
			while (SDL_PollEvent(&eve))
			{
				switch (eve.type)
				{
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_MOUSEBUTTONDOWN:
					for (Component *c : comps)
						c->mouseDown(eve);
					break;
				case SDL_MOUSEBUTTONUP:
					for (Component *c : comps)
						c->mouseUp(eve);
					break;
				case SDL_KEYDOWN:
					for (Component *c : comps)
						c->keyDown(eve);
					break;
				case SDL_KEYUP:
					for (Component *c : comps)
						c->keyUp(eve);
					break;

				} // switch
			}	  // inre while

			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());

			for (Component *c : comps)
			{
				c->draw();
			}
			SDL_RenderPresent(sys.get_ren());

			// modified
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
			{
				SDL_Delay(delay);
			}

		} // yttre while
	}

	Session::~Session()
	{
	}
}