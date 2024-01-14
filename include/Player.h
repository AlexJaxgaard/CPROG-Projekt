/*
---------
Alexander Jaxgård ALJA9460
Elias Bennaceur ELBE7219
---------
*/
#ifndef PLAYER_H
#define PLAYER_H
#include "Component.h"
#include <string>
#include "System.h"
#include "Session.h"
#include "Missile.h"
class Player : public cwing::Component
{

private:
	int x;
	int y;
	int w;
	int h;
	std::string text;
	SDL_Texture *texture;
	SDL_Rect rectangle;
	cwing::Session &ses;
	std::string label = "player";

protected:
public:
	Player(int x, int y, int w, int h, std::string txt, cwing::Session &ses);

	Player *getInstance(int x, int y, int w, int h, std::string txt);
	void mouseDown(const SDL_Event &) {}
	void mouseUp(const SDL_Event &) {}
	void keyDown(const SDL_Event &);
	void keyUp(const SDL_Event &);
	void mouseMotion(const SDL_Event &) {}
	void draw() const override;
	// virtual void perform(Button* source) {}
	void tick() override;
	void collision(Component *comp) override;
	std::string getLabel() override { return label; }
	~Player(){}

	// SDL_Texture* upIcon, *downIcon;
};

#endif