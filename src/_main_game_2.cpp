#include <string>
#include "Session.h"
#include <iostream>
#include <stdlib.h>
#include "GameObject.h"
#include "Component.h"
#include "Enemy.h"
#include "TextComponent.h"
#include "ImageComponent.h"
#include "Snake.h"
using namespace cwing;
using namespace std;


int main(int argc, char **argv)
{

	std::cout << "*** main()\n";

	Session ses;
	std::clog << "Session Started" << std::endl;

	//ImageComponent *backgroundImage = new ImageComponent(0, 0, ses.getScreenWidth(), ses.getScreenHeight(), "bg.bmp");
	//ses.add(backgroundImage);

	GameObject *snake = new Snake(350, 300, 16, 16, "/images/rymdskepp.bmp", ses);

	ses.add(snake);


	ses.run();

	std::clog << "session running" << std::endl;

	return 0;
}