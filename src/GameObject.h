#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Component.h"
#include <SDL2/SDL.h>
#include <string>
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "System.h"
#include "Session.h"
#include "Player.h"
#include "TextComponent.h"

namespace cwing
{
	class GameObject : public Component
	{
	public:
		GameObject(int x, int y, int w, int h, std::string txt, Session &ses);

		GameObject *getInstance(int x, int y, int w, int h, std::string txt);
		void mouseDown(const SDL_Event &);
		void mouseUp(const SDL_Event &);
		void keyDown(const SDL_Event &);
		void keyUp(const SDL_Event &);
		void mouseMotion(const SDL_Event &);
		void draw() const override;
		// virtual void perform(Button* source) {}
		void setSprite(SDL_Texture *texture);
		int getPoints();
		void missileHit();
		void colission(Component* comp);
		void tick();
		~GameObject();
		TransformComponent *tc;

	protected:
		Component *sc;

	private:
		int x;
		int y;
		int w;
		int h;
		std::string text;
		SDL_Texture *texture;
		SDL_Rect rectangle;
		bool drag;
		Session &ses;
		Player *player;

		// SDL_Texture* upIcon, *downIcon;
	};
}

#endif