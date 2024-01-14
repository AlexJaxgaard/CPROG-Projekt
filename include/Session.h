#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Component.h"
#include <SDL2/SDL.h>
#include "System.h"
#include "Component.h"
#include <iostream>
#include <algorithm>

namespace cwing
{

	class Session
	{

	private:
		std::vector<Component *> comps;
		std::vector<Component *> added, removed;
		int tickCounter = 1;
	public:
		Session();
		void add(Component *c);
		void remove(Component *c);
		void run();
		int getScreenHeight();
		int getScreenWidth();
		int getCurrentTick() { return tickCounter; }
		bool collisionCheck(SDL_Rect rect1, SDL_Rect rect2);
		~Session();
	};
}
#endif