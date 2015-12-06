#include "TestScreen.h"

#include "ImageLoader.h"

TestScreen::TestScreen()
{
	// object initializtion
	objs.push_back(Object(Vector3(5, -18, 0)));
	objs[0].loadObj("apple");
	objs[0].set_passable(false);

	objs.push_back(Object(Vector3(10, -18, 0)));
	objs[1].loadObj("apple");
	objs[1].set_passable(false);
	objs[1].setTracking(true);
	objs[1].set_type(1);
	objs[1].trackpos(character->getPosition());
	roomBox = Box(Vector3(0.f, 0.f, 0.f), (GS::option.roomSize*2), (GS::option.roomSize*2) + 4, (GS::option.roomSize*2));
	
}


TestScreen::~TestScreen()
{
}

void TestScreen::update(double delta)
{
	Screen::update(delta);

	Object_Tracking_Character(1);

	Screen::Character_Room_Collision_Detection();
	Screen::Character_Objects_Collision_Detection();
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
