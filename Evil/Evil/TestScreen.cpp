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
	GLDraw::room(200.0, t);
	//GLDraw::drawPlane(Vector3(-0.2, 0.2, 0), Vector3(0.2, 0.2, 0), Vector3(0.2, -0.2, 0), Vector3(-0.2, -0.2, 0));

	cout << GS::character->getLook() << endl;
}
