#include <string>
#include "Session.h"
#include <iostream>
#include "Player.h"

using namespace cwing;
using namespace std;
int main(int argc, char **argv)
{
	std::cout << "*** main()\n";

	Session ses;
	std::clog << "Session Started" << std::endl;

	Component* p = new Player(10,10,10,10);

	ses.add(p);

	ses.run();

	return 0;
}

