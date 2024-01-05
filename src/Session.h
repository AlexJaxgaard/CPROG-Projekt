#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include "Component.h"
#include <SDL2/SDL.h>
#include "System.h"
#include "Enemy.h"
#include "Missile.h"
#include <iostream>
#include <algorithm>
#include <string>
namespace cwing 
{

	class Session
	{
	public:
		Session();
		void add(Component* c);
		void remove(Component* c);
		void run();
		int getScreenHeight();
		int getScreenWidth();
		bool collisionCheck(SDL_Rect rect1,SDL_Rect rect2);
		~Session();
	private:
		std::vector<Component*> comps;
		std::vector<Component*> added, removed;
	};
}
#endif