#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include "Component.h"

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