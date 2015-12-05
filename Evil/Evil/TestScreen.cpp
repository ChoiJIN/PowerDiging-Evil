#include "TestScreen.h"


TestScreen::TestScreen()
{
	Object obj;
	// object initializtion
	objs.push_back(Object(Vector3(0, -18, 0)));
	objs[0].loadObj("apple");
	objs.push_back(Object(Vector3(10, -18, 0)));
	objs[1].loadObj("apple");
	objs[1].setTracking(true);
	objs[1].trackpos(GS::character->getPosition());

//				cout << "오브젝트 박스의 무게 중심 = " << objs[0].get_box().get_cog() << endl;
//				cout << "캐릭터 박스의 무게 중심 = " << GS::character->get_box().get_cog() << endl;
//				cout << "오브젝트 박스의 무게 중심 = " << objs[1].get_box().get_cog() << endl;
//				cout << "캐릭터 박스의 무게 중심 = " << GS::character->get_box().get_cog() << endl;
//	obj.loadObj("apple");
}


TestScreen::~TestScreen()
{
}

void TestScreen::update(double delta)
{
	Screen::update(delta);
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
