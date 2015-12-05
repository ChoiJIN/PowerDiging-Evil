#include "TestScreen.h"

#include "ImageLoader.h"

TestScreen::TestScreen()
{
//	Object obj;
	// object initializtion
	objs.push_back(Object(Vector3(0, -18, 0)));
	objs[0].loadObj("apple");
	objs.push_back(Object(Vector3(10, -18, 0)));
	objs[1].loadObj("apple");
	objs[1].setTracking(true);
//				cout << "������Ʈ �ڽ��� ���� �߽� = " << objs[0].get_box().get_cog() << endl;
//				cout << "ĳ���� �ڽ��� ���� �߽� = " << GS::character->get_box().get_cog() << endl;
//				cout << "������Ʈ �ڽ��� ���� �߽� = " << objs[1].get_box().get_cog() << endl;
//				cout << "ĳ���� �ڽ��� ���� �߽� = " << GS::character->get_box().get_cog() << endl;
//	obj.loadObj("apple");
}


TestScreen::~TestScreen()
{
}

void TestScreen::update(double delta)
{
	Screen::update(delta);
	objs[1].trackpos(character->getPosition());
}

void TestScreen::render()
{
	Screen::render();
	GLuint t[6] = { 
		ImageLoader::getTextureId("brick.jpg"),
		ImageLoader::getTextureId("brick.jpg"),
		ImageLoader::getTextureId("brick_door.jpg"),
		ImageLoader::getTextureId("brick.jpg"),
		ImageLoader::getTextureId("brick_bottom.jpg"),
		ImageLoader::getTextureId("brick.jpg")
	};
	GLDraw::room(GS::option.roomSize, t);
}
