#include "Session.h"
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
				case SDL_MOUSEMOTION:
					for (Component *c : comps)
						c->mouseMotion(eve);

				} // switch
			}	  // inre while

			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());

			for (Component *c : comps)
			{
				c->tick();
			}

			for (Component *c : comps)
			{
				c->draw();
			}

			for (Component *i : comps)
			{
				for (Component *j : comps)
				{
					if (i != j && i->getLabel() != j->getLabel() && collisionCheck(i->getRect(), j->getRect()))
					{
						i->collision(j);
					}
				}
			}

			for (Component *c : removed)
			{
				comps.erase(std::remove(comps.begin(), comps.end(), c), comps.end());
			}
			removed.clear();

			SDL_RenderPresent(sys.get_ren());

			// modified
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
			{
				SDL_Delay(delay);
			}
			tickCounter++;
		} // yttre while
	}

	int Session::getScreenWidth()
	{
		int w, h;

		SDL_GetRendererOutputSize(sys.get_ren(), &w, &h);

		return w;
	}

	int Session::getScreenHeight()
	{
		int w, h;

		SDL_GetRendererOutputSize(sys.get_ren(), &w, &h);

		return h;
	}

	bool Session::collisionCheck(SDL_Rect a, SDL_Rect b)
	{
		if (a.x + a.w < b.x)
			return false;
		if (a.x > b.x + b.w)
			return false;
		if (a.y + a.h < b.y)
			return false;
		if (a.y > b.y + b.h)
			return false;

		return true;
	}

	Session::~Session()
	{
		for (Component *comp : comps)
		{
			delete comp;
		}
	}
}