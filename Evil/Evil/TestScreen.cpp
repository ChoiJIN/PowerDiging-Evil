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
//	if (!roomBox.collision_detection_in(character->get_box(), Vector3(0.f, 0.f, 0.f)))
//	{
//		if(character->get_front_move() == true)  // 0번 FRONT, 1번 BACK, 2번 LEFT, 3번 RIGHT
//			character->moveFunction(-character->getCdelta(0).x, character->getCdelta(0).y, false);
//		if (character->get_back_move() == true)
//			character->moveFunction(-character->getCdelta(1).x, character->getCdelta(1).y, false);
//		if (character->get_left_move() == true)
//			character->moveFunction(-character->getCdelta(2).x, character->getCdelta(2).y, false);
//		if (character->get_right_move() == true)
//			character->moveFunction(-character->getCdelta(3).x, character->getCdelta(3).y, false);
		//		cout << "방 밖으로 나감" << endl;
//	}
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
