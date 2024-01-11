
#include "Constants.h"
#include "Player.h"
#include <iostream>
#include "Missile.h"

using namespace std;


	Player::Player(int x, int y, int w, int h, std::string txt, cwing::Session &ses) : Component(x, y, w, h, txt), rectangle{x,y,w,h}, ses(ses), drag(false)
	{

	}
	Player *Player::getInstance(int x, int y, int w, int h, std::string txt)
	{
		return new Player(x, y, w, h, txt, ses);
	}
	void Player::mouseDown(const SDL_Event &event)
	{	


		SDL_Point p = {event.button.x, event.button.y};

		if (SDL_PointInRect(&p, &Component::getRect()))
		{ std::cout << "Mouse clicked on rocket" << std::endl;
			drag = true;
		}
	}
	void Player::mouseUp(const SDL_Event &event)
	{
		drag = false;
	}
	void Player::keyDown(const SDL_Event &event)
	{

if (event.key.keysym.sym == SDLK_DOWN)
{
    cout << "turning down " + x << endl;
    if (y <= ses.getScreenHeight() - rectangle.h){
        y += 10;
        rectangle.y += 10;
	}
}
else if (event.key.keysym.sym == SDLK_UP)
{
    if (y >= 0)
    {
        cout << "turning up " << endl;
        y -= 10;
        rectangle.y -= 10;
    }
}
else if (event.key.keysym.sym == SDLK_LEFT)
{   
    if (x >= 0){
        cout << "turning left " << endl;
        x -= 10;
        rectangle.x -= 10;
    }
}
else if (event.key.keysym.sym == SDLK_RIGHT)
{
    if (x <= ses.getScreenWidth() - rectangle.w){
        cout << "turning right " << endl;
        x += 10;
        rectangle.x += 10;
    }
}
		else if (event.key.keysym.sym == SDLK_SPACE)
		{
			cout << "space pressed" << endl;

			Missile *missile = new Missile(getRect().x, getRect().y, ses);
			ses.add(missile);
		}
	}
	void Player::keyUp(const SDL_Event &)
	{
	}

	void Player::mouseMotion(const SDL_Event &event)
	{

		if (drag){
			rectangle.x += event.motion.xrel;
			rectangle.y += event.motion.yrel;
		}
	}
	void Player::draw() const
	{
		Component::draw();
	}
	// virtual void perform(Button* source) {}
	void setSprite(SDL_Texture *texture) {}

	void Player::tick()
	{
		
		Component::setRect(rectangle.x, rectangle.y, rectangle.w, rectangle.h);
		std::cout << (int)getRect().x << ", " << (int)getRect().y << ", " << (int)getRect().w << ", " << (int)getRect().h << std::endl;
	}

	void Player::collision(Component *comp)
	{
		if (comp->getLabel() == "enemy")
		{
			std::cout << "enemy hit on player" << endl;
		}
	}

	Player::~Player()
	{
	}

	// SDL_Texture* upIcon, *downIcon;

