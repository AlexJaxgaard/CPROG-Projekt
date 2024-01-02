
#include "Constants.h"
#include "GameObject.h"
#include <SDL2/SDL_ttf.h>
#include "System.h"
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;
namespace cwing
{

	GameObject::GameObject(int x, int y, int w, int h, std::string txt) : Component(x, y, w, h), x(x), y(y), w(h), h(h)
	{
<<<<<<< Updated upstream:_exempelfiler/BaseCodeStart/GameObject.cpp
	public:
	    GameObject::GameObject* getInstance(int x, int y, int w, int h, std::string txt){
            SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), txt.c_str(), { 0,0,0 });
            texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
            SDL_FreeSurface(surf);
            //upIcon = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/UppKnapp.png").c_str() );
            //downIcon = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/NerKnapp.png").c_str() );
        }
		void mouseDown(const SDL_Event&);
		void mouseUp(const SDL_Event&);
        void keyDown(const SDL_Event&);
        void keyUp(const SDL_Event&);
		void draw() const;
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
=======
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
		tc = new TransformComponent(x, y, w, h);
		sc = new SpriteComponent("");
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
		return new GameObject(x, y, w, h, txt);
	}
	void GameObject::mouseDown(const SDL_Event &)
	{
	}
	void GameObject::mouseUp(const SDL_Event &)
	{
	}
	void GameObject::keyDown(const SDL_Event &event)
	{
		if (event.key.keysym.sym == SDLK_DOWN)
		{
			cout << "turning down " + x << endl;

			x--;
			rectangle.x--;
		}
		else if (event.key.keysym.sym == SDLK_UP)
		{
			cout << "turning up " << endl;
			x++;
			rectangle.x++;
		}
		else if (event.key.keysym.sym == SDLK_LEFT)
		{
			cout << "turning left " << endl;
			y--;
			rectangle.y--;
		}
		else if (event.key.keysym.sym == SDLK_RIGHT)
		{
			cout << "turning right " << endl;
			y++;
			rectangle.y++;
		}
	}
	void GameObject::keyUp(const SDL_Event &)
	{
	}
	void GameObject::draw() const
	{
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &rectangle);
	}
	// virtual void perform(Button* source) {}
	void setSprite(SDL_Texture *texture) {}
	GameObject::~GameObject()
	{
	}

	// SDL_Texture* upIcon, *downIcon;
}
>>>>>>> Stashed changes:src/GameObject.cpp
