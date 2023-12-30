#include <string>
#include "Session.h"
#include <iostream>
#include "Label.h"
#include "Button.h"
using namespace cwing;
using namespace std;
int main(int argc, char **argv)
{
	std::cout << "*** main()\n";

	Session ses;
	std::clog << "Session Started" << std::endl;

	Label *lbl = Label::getInstance(270, 100, 100, 70, "0");
	ses.add(lbl);
	Button *b = new OkaKnapp(lbl);
	ses.add(b);
	Button *b2 = new MinskaKnapp(lbl);
	ses.add(b2);
	ses.run();
	ses.run();
	std::clog << "session running" << std::endl;

	return 0;
}

int value = 0;

class OkaKnapp : public Button
{
public:
	OkaKnapp(Label *lbl) : Button(100, 100, 150, 70, "Oka"), label(lbl) {}
	void perform(Button *source)
	{
		value++;
		label->setText(to_string(value));
	}

private:
	Label *label;
};

class MinskaKnapp : public Button
{
public:
	MinskaKnapp(Label *lbl) : Button(400, 100, 150, 70, "Minska"), label(lbl) {}
	void perform(Button *source)
	{
		value--;
		label->setText(to_string(value));
	}

private:
	Label *label;
};