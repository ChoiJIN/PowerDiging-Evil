#include "TestScreen.h"

TestScreen::TestScreen()
{
	Object obj;
	// object initializtion
	obj.loadObj("apple");
	obj.setPosition(0, 2, 0);
	objs.push_back(obj);
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
	GLDraw::room(GS::option.roomSize, t);
	//GLDraw::drawPlane(Vector3(-0.2, 0.2, 0), Vector3(0.2, 0.2, 0), Vector3(0.2, -0.2, 0), Vector3(-0.2, -0.2, 0));

	/*GLCube cube;
	cube.draw();*/


	//cout << GS::character->getLook() << endl;
}
