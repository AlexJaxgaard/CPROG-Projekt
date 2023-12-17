
#include "Constants.h"
#include "GameObject.h"
#include <SDL2/SDL_ttf.h>
#include "System.h"
#include <SDL2/SDL_image.h>
namespace cwing 
{
	class GameObject : public Component
	{
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