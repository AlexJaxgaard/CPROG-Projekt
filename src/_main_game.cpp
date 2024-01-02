#include <string>
#include "Session.h"
#include <iostream>
#include <stdlib.h>
#include "GameObject.h"
#include "Component.h"
#include "Enemy.h"
using namespace cwing;
using namespace std;

Component *randomEnemy(Session ses)
{
	int iSecret = rand() % 3 + 1;
	std::string type;

	int yPos = rand() % ses.getScreenWidth() + 1;

	switch (iSecret)
	{
	case 1:
		type = "easy";
		break;
	case 2:
		type = "medium";
		break;
	case 3:
		type = "hard";

	default:
		break;
	}

	Component *enemy = new Enemy(yPos, 0, 25, 25, "images/"+type+".bmp", type);
	return enemy;
}

int main(int argc, char **argv)
{
	std::cout << "*** main()\n";

	Session ses;
	std::clog << "Session Started" << std::endl;

	GameObject *gameObject = new GameObject(ses.getScreenHeight(), ses.getScreenWidth()/2, 16, 16, "/images/rymdskepp.bmp");
	// Component *bg = new Component(ses.getScreenHeight(), ses.getScreenWidth(), ses.getScreenHeight(), ses.getScreenWidth(), "bg.bmp");
	// ses.add(bg);

	for (int i = 0; i < 20; i++){
		ses.add(randomEnemy(ses));
	}
	int num = gameObject->tc->x();

	
	ses.add(randomEnemy(ses));

	ses.run();



	std::cout << num << endl;

	std::clog << "session running" << std::endl;

	return 0;
}




