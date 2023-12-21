
#include "Constants.h"
#include "GameObject.h"
#include <SDL2/SDL_ttf.h>
#include "System.h"
#include <SDL2/SDL_image.h>
namespace cwing
{

	

	static GameObject GameObject::*getInstance(int x, int y, int w, int h, std::string txt)
	{
		static SDL_Surface *surf = TTF_RenderText_Solid(sys.get_font(), txt.c_str(), {0, 0, 0});
		SDL_Texture *texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
		SDL_FreeSurface(surf);
		// upIcon = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/UppKnapp.png").c_str() );
		// downIcon = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/NerKnapp.png").c_str() );
	}
	void GameObject::mouseDown(const SDL_Event &)
	{
	}
	void GameObject::mouseUp(const SDL_Event &)
	{
	}
	void GameObject::keyDown(const SDL_Event &)
	{
	}
	void GameObject::keyUp(const SDL_Event &)
	{
	}
	void GameObject::draw() const
	{
	}
	// virtual void perform(Button* source) {}
	void setSprite(SDL_Texture *texture)
	{
	}
	GameObject::~GameObject()
	{
	}

	GameObject::GameObject(int x, int y, int w, int h, std::string txt)
	{
	}

	std::string text;
	static SDL_Texture *texture;
	// SDL_Texture* upIcon, *downIcon;
};
