#include <string>
#include "Session.h"
#include <iostream>
#include <stdlib.h>
#include "GameObject.h"
#include "Component.h"
#include "Enemy.h"
#include "TextComponent.h"
#include "ImageComponent.h"

using namespace cwing;
using namespace std;


int main(int argc, char **argv)
{

	std::cout << "*** main()\n";

	Session ses;
	std::clog << "Session Started" << std::endl;

	//ImageComponent *backgroundImage = new ImageComponent(0, 0, ses.getScreenWidth(), ses.getScreenHeight(), "bg.bmp");
	//ses.add(backgroundImage);






	ses.run();

	std::clog << "session running" << std::endl;

	return 0;
}