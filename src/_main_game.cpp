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

Enemy *randomEnemy(Session &ses)
{

	int xVal = rand() % ses.getScreenWidth();
	Enemy *enemy = new Enemy(xVal, 0, 25, 25, ses);
	return enemy;
}

int main(int argc, char **argv)
{

	std::cout << "*** main()\n";

	Session ses;
	std::clog << "Session Started" << std::endl;
	ImageComponent *backgroundImage = new ImageComponent(0, 0, ses.getScreenWidth(), ses.getScreenHeight(), "bg.bmp");

	Player *player = new Player(ses.getScreenWidth() / 2, ses.getScreenHeight() - (ses.getScreenHeight() / 4), 32, 32, "images/rymdskepp.bmp", ses);
	ses.add(backgroundImage);
	ses.add(player);
	for (int i = 0; i < 8; i++)
	{
		ses.add(randomEnemy(ses));
	}

	ses.run();

	std::clog << "session running" << std::endl;

	return 0;
}
