#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Component.h"
#include <SDL2/SDL.h>
#include <string>

namespace cwing 
{
	class GameObject : public Component
	{
	public:
	    GameObject* getInstance(int x, int y, int w, int h, std::string txt);
		void mouseDown(const SDL_Event&);
		void mouseUp(const SDL_Event&);
        void keyDown(const SDL_Event&);
        void keyUp(const SDL_Event&);
		void draw() const;
		void update() const;
		//virtual void perform(Button* source) {}
        void setSprite(SDL_Texture* texture);
		~ GameObject();
	protected:
		GameObject(int x, int y, int w, int h, std::string txt);
	private:
		std::string text;
		SDL_Texture* texture;
		//SDL_Texture* upIcon, *downIcon;
	};
}

#endif