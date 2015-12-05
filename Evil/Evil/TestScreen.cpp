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
}

void TestScreen::render()
{
	Screen::render();
	GLuint t[6] = { 
		ImageLoader::getTextureId("back_wall.png"),
		ImageLoader::getTextureId("side_wall.png"),
		ImageLoader::getTextureId("front_wall.png"),
		ImageLoader::getTextureId("side_wall.png"),
		ImageLoader::getTextureId("bottom_wall.png"),
		ImageLoader::getTextureId("top_wall.png")
	};
	GLDraw::room(GS::option.roomSize, t);
}
