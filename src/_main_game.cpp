#include <string>
#include "Session.h"
#include <iostream>
#include <stdlib.h>
#include "GameObject.h"
#include "Component.h"
#include "Enemy.h"
#include "TextComponent.h"
using namespace cwing;
using namespace std;

float randomFloat(float min, float max)
{
	return (min + 1) + (((float)rand()) / (float)RAND_MAX) * (max - (min + 1));
}

Component *randomEnemy(Session ses)
{
	float velocity = 1;
	int iSecret = rand() % 3 + 1;
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
		velocity = randomFloat(0.3, 0.4);

	default:
		break;
	}

	Enemy *enemy = new Enemy(yPos, 0, 25, 25, "images/" + type + ".bmp", type, velocity);
	return enemy;
}

int main(int argc, char **argv)
{

	std::cout << "*** main()\n";

	Session ses;
	std::clog << "Session Started" << std::endl;

	GameObject *gameObject = new GameObject(ses.getScreenHeight(), ses.getScreenWidth()/2, 16, 16, "/images/rymdskepp.bmp", ses);
	// Component *bg = new Component(ses.getScreenHeight(), ses.getScreenWidth(), ses.getScreenHeight(), ses.getScreenWidth(), "bg.bmp");
	// ses.add(bg);
	ses.add(gameObject);

	TextComponent *tc = new TextComponent(0,0,10,10,"0");
	ses.add(tc);

	int num = gameObject->tc->x();
	for (int i = 0; i < 20; i++)
	{
		ses.add(randomEnemy(ses));
	}

	ses.run();

	std::cout << num << endl;

	std::clog << "session running" << std::endl;

	return 0;
}

