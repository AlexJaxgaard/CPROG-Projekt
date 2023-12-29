#include <string>
#include "Session.h"
#include <iostream>

using namespace cwing;








int main(int argc, char** argv) {
	std::cout << "*** main()\n";
	

	Session ses;
	std::clog << "Session Started" << std::endl;

	//S

	ses.run();
	std::clog << "session running" << std::endl;
	
	
	

	/*Label* lbl = Label::getInstance(270, 100, 100, 70, "0");
	ses.add(lbl);
	Button* b = new OkaKnapp(lbl);
	ses.add(b);
	Button* b2 = new MinskaKnapp(lbl);
	ses.add(b2);
	ses.run();
	*/
	
	return 0;
}