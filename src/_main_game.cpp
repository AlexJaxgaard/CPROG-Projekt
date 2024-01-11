#include <string>
#include "Session.h"
#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include "Component.h"
#include "Enemy.h"
#include "ImageComponent.h"
using namespace cwing;
using namespace std;

float randomFloat(float min, float max)
{
	return (min + 1) + (((float)rand()) / (float)RAND_MAX) * (max - (min + 1));
}

Component *randomEnemy(Session ses)
{

	vector<int> added_yPos;

	float velocity = 1;
	int iSecret = 3;
	std::string type;

	int yPos = rand() % ses.getScreenWidth() + 1;

	switch (iSecret)
	{
	case 1:
		type = "easy";
		velocity = randomFloat(0.09, 0.10);
		break;
	case 2:
		type = "medium";
		velocity = randomFloat(0.1, 0.2);
		break;
	case 3:
		type = "hard";
		velocity = randomFloat(0.1, 0.4);

	default:
		break;
	}

	Component *enemy = new Enemy(yPos, 0, 25, 25, "images/" + type + ".bmp", type, velocity, ses);
	return enemy;
}

int main(int argc, char **argv)
{

	std::cout << "*** main()\n";

	Session ses;
	std::clog << "Session Started" << std::endl;

	ImageComponent *backgroundImage = new ImageComponent(0, 0, ses.getScreenWidth(), ses.getScreenHeight(), "bg.bmp");
	ses.add(backgroundImage);

	Player *player = new Player(ses.getScreenWidth()/2, ses.getScreenHeight()-(ses.getScreenHeight()/4), 32, 32, "images/rymdskepp.bmp", ses);

	ses.add(player);




	ses.run();

	std::clog << "session running" << std::endl;

	return 0;
}
