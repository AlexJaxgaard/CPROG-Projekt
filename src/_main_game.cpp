#include <string>
#include "Session.h"
#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include "Component.h"
#include "Enemy.h"
#include "ImageComponent.h"
#include <set>
using namespace cwing;
using namespace std;



int main(int argc, char **argv)
{

	std::cout << "*** main()\n";

	Session ses;
	std::clog << "Session Started" << std::endl;


	Player *player = new Player(ses.getScreenWidth()/2, ses.getScreenHeight()-(ses.getScreenHeight()/4), 32, 32, "images/rymdskepp.bmp", ses);

	ses.add(player);
	Enemy *enemy = new Enemy(ses.getScreenWidth()/2, 0, 25, 25, 1, ses);

	ImageComponent *backgroundImage = new ImageComponent(ses.getScreenWidth(), ses.getScreenHeight(), 640, 360, "bg.bmp");
	ses.add(backgroundImage);

	ses.add(enemy);




	ses.run();

	std::clog << "session running" << std::endl;

	return 0;
}
