#include <string>
#include "Session.h"
#include <iostream>

#include "GameObject.h"
#include "Component.h"

using namespace cwing;
using namespace std;
int main(int argc, char **argv)
{
	std::cout << "*** main()\n";

	Session ses;
	std::clog << "Session Started" << std::endl;
	GameObject *gameObject = new GameObject(0, 0, 256, 256, "/images/rymdskepp.bmp");

	ses.add(gameObject);
	int num = gameObject->tc->x();
	ses.run();

	std::cout << num << endl;

	std::clog << "session running" << std::endl;

	return 0;
}
