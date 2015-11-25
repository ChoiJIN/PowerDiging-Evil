#include "TestScreen.h"

TestScreen::TestScreen()
{
	// object initializtion
}


TestScreen::~TestScreen()
{
}

void TestScreen::update(double delta)
{

}

void TestScreen::render()
{
	Screen::render();

	int t[6] = {};
	int size = 100;
	GLDraw::plane(Vector3(-size, 0, -size), Vector3(-size, 0, size), Vector3(size, 0, size), Vector3(size, 0, -size));

	cout << GS::character->getLook() << endl;
}
