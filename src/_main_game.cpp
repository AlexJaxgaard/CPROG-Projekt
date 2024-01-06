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

	vector<int> added_yPos;

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

	GameObject *gameObject = new GameObject(1, 0, 16, 16, "/images/rymdskepp.bmp", ses);
	// Component *bg = new Component(ses.getScreenHeight(), ses.getScreenWidth(), ses.getScreenHeight(), ses.getScreenWidth(), "bg.bmp");
	// ses.add(bg);
	ses.add(gameObject);


	//ses.add(points);

	for (int i = 0; i < 20; i++)
	{
		ses.add(randomEnemy(ses));
	}

	ses.run();

	std::clog << "session running" << std::endl;

	return 0;
}
