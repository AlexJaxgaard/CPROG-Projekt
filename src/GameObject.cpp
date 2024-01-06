
#include "Constants.h"
#include "GameObject.h"
#include <SDL2/SDL_ttf.h>

#include <SDL2/SDL_image.h>
#include <iostream>
#include "Missile.h"

using namespace std;
namespace cwing
{

	GameObject::GameObject(int x, int y, int w, int h, std::string txt, Session& ses) : Component(x, y, w, h), x(x), y(y), w(h), h(h),ses(ses)
	{
		// SDL_Surface *surf = TTF_RenderText_Solid(sys.get_font(), txt.c_str(), {0, 0, 0});
		SDL_Surface *surf = IMG_Load((constants::gResPath + txt).c_str());
		if (surf == NULL)
		{
			std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
		}
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
		if (texture == NULL)
		{
			std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
		}
		rectangle = {0, 0, w, h};
		SDL_FreeSurface(surf);
		cout << SDL_GetError();
		// upIcon = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/UppKnapp.jpg").c_str() );
		//  downIcon = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/NerKnapp.png").c_str() );
	}
	GameObject *GameObject::getInstance(int x, int y, int w, int h, std::string txt)
	{
		/* SDL_Surface *surf = TTF_RenderText_Solid(sys.get_font(), txt.c_str(), {0, 0, 0});
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
		SDL_FreeSurface(surf);
		tc = new TransformComponent(x, y, w, h);
		sc = new SpriteComponent("");
		// upIcon = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/UppKnapp.png").c_str() );
		// downIcon = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/NerKnapp.png").c_str() ); */
		return new GameObject(x, y, w, h, txt,ses);
	}
	void GameObject::mouseDown(const SDL_Event &event)
	{

		SDL_Point p = {event.button.x, event.button.y};

		if (SDL_PointInRect(&p, &rectangle))
		{
			drag = true;
		}
	}
	void GameObject::mouseUp(const SDL_Event &event)
	{
		drag = false;
	}
	void GameObject::keyDown(const SDL_Event &event)
	{

		if (event.key.keysym.sym == SDLK_DOWN)
		{
			cout << "turning down " + x << endl;

			y += 1;
			rectangle.y += 1;
		}
		else if (event.key.keysym.sym == SDLK_UP)
		{
			cout << "turning up " << endl;
			y -= 1;
			rectangle.y -= 1;
		}
		else if (event.key.keysym.sym == SDLK_LEFT)
		{
			cout << "turning left " << endl;
			x -= 1;
			rectangle.x -= 1;
		}
		else if (event.key.keysym.sym == SDLK_RIGHT)
		{
			cout << "turning right " << endl;
			x += 1;
			rectangle.x += 1;
		}
		else if (event.key.keysym.sym == SDLK_SPACE)
		{
			sys.play_sound("shot.wav");
			cout << "space pressed" << endl;
			
			Missile *missile = new Missile(rectangle.x,rectangle.y);
			ses.add(missile);
			

		}
	}
	void GameObject::keyUp(const SDL_Event &)
	{
	}

	void GameObject::mouseMotion(const SDL_Event &event)
	{
		if (drag)
		{
			rectangle.x += event.motion.xrel;
			rectangle.y += event.motion.yrel;
		}
	}
	void GameObject::draw() const
	{
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &rectangle);
	}
	// virtual void perform(Button* source) {}
	void setSprite(SDL_Texture *texture) {}

	void GameObject::tick(){

	}


	GameObject::~GameObject()
	{
	}
	
	
	// SDL_Texture* upIcon, *downIcon;
}
