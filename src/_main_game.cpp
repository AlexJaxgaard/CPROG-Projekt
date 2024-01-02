#include <string>
#include "Session.h"
#include <iostream>
<<<<<<< Updated upstream
#include "Player.h"
=======
#include "GameObject.h"
#include "Component.h"
>>>>>>> Stashed changes

using namespace cwing;
using namespace std;
int main(int argc, char **argv)
{
	std::cout << "*** main()\n";

	Session ses;
	std::clog << "Session Started" << std::endl;
	GameObject *gameObject = new GameObject(0, 0, 256, 256, "/images/rymdskepp.bmp");
	

<<<<<<< Updated upstream
	Component* p = new Player(10,10,10,10);

	ses.add(p);

	ses.run();

	return 0;
}

=======
	ses.add(gameObject);
	int num = gameObject->tc->x();
	ses.run();

	std::cout << num << endl;

	std::clog << "session running" << std::endl;

	return 0;
}
>>>>>>> Stashed changes
