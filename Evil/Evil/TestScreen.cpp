#include "TestScreen.h"

TestScreen::TestScreen()
{
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
	//GLDraw::room(100.0, t);
	//GLDraw::drawPlane(Vector3(-0.2, 0.2, 0), Vector3(0.2, 0.2, 0), Vector3(0.2, -0.2, 0), Vector3(-0.2, -0.2, 0));
	int size = 100;
	GLDraw::plane(Vector3(-size, 0, -size), Vector3(-size, 0, size), Vector3(size, 0, size), Vector3(size, 0, -size));

	cout << GS::character->getLook() << endl;
}
