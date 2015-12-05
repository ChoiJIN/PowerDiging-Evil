#include "TestScreen.h"

#include "ImageLoader.h"

TestScreen::TestScreen()
{
	Object obj;
	// object initializtion
	objs.push_back(Object(Vector3(0, -18, 0)));
	objs[0].loadObj("apple");
	objs.push_back(Object(Vector3(10, -18, 0)));
	objs[1].loadObj("apple");
}


TestScreen::~TestScreen()
{
}

void TestScreen::update(double delta)
{
	Screen::update(delta);
	//GS::debug.log(to_string());
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
