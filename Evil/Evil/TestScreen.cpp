#include "TestScreen.h"

#include "ImageLoader.h"

TestScreen::TestScreen()
{
	// object initializtion
	objs.push_back(Object(Vector3(0, -18, 0)));
	objs[0].loadObj("apple");
	objs.push_back(Object(Vector3(10, -18, 0)));
	objs[1].loadObj("apple");
	objs[1].setTracking(true);
	objs[1].trackpos(character->getPosition());
	roomBox = Box(Vector3(0.f, 0.f, 0.f), (GS::option.roomSize*2), (GS::option.roomSize*2) + 4, (GS::option.roomSize*2));
	
}


TestScreen::~TestScreen()
{
}

void TestScreen::update(double delta)
{
	Screen::update(delta);
	if((objs[1].get_trackposition() - objs[1].get_box().get_cog()).length() < 1)
		objs[1].trackpos(character->getPosition());
	if (!roomBox.collision_detection_in(character->get_box(), Vector3(0.f, 0.f, 0.f)))
		cout << "방 밖으로 나감" << endl;
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
