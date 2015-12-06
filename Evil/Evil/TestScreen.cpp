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
	if (character->collision_check(objs[1].get_box(), Vector3(0, 0, 0))
		|| objs[1].get_box().collision_detection_3D(character->get_box(), Vector3(0, 0, 0)))
	{ 
		objs[1].setTracking(false);
	}
	else
	{
		objs[1].setTracking(true);
		objs[1].trackpos(character->getPosition());
	}
		

	if (!roomBox.collision_detection_in(character->get_box(), character->getCdelta(0)))
	{
		character->setFrontCollision(true);
	}
	else
		character->setFrontCollision(false);

	if (!roomBox.collision_detection_in(character->get_box(), character->getCdelta(1)))
	{
		character->setBackCollision(true);
	}
	else
		character->setBackCollision(false);

	if (!roomBox.collision_detection_in(character->get_box(), character->getCdelta(2)))
	{
		character->setLeftCollision(true);
	}
	else
		character->setLeftCollision(false);

	if (!roomBox.collision_detection_in(character->get_box(), character->getCdelta(3)))
	{
		character->setRightCollision(true);
	}
	else
		character->setRightCollision(false);

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
