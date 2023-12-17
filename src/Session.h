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
		~Session();
	private:
		std::vector<Component*> comps;
		std::vector<Component*> added, removed;
	};
}
#endif