#include "TestScreen.h"

#include "ImageLoader.h"

TestScreen::TestScreen()
{
	// object initializtion
	objs.push_back(Object(Vector3(5, -18, 0)));
	objs[0].loadObj("apple");
	objs[0].set_passable(false);
	
/*
	objs.push_back(Object(Vector3(10, -18, 0)));
	objs[1].loadObj("apple");
	objs[1].set_passable(false);
	objs[1].setTracking(true);
	objs[1].set_type(1);
	objs[1].trackpos(character->getPosition());*/
	objs.push_back(Object(Vector3(10, -20, 0)));
	objs[1].loadObj("apple");
	objs[1].set_passable(false);
	roomBox = Box(Vector3(0.f, 0.f, 0.f), (GS::option.roomSize * 2), (GS::option.roomSize * 2) + 4, (GS::option.roomSize * 2));
}


TestScreen::~TestScreen()
{
}

void TestScreen::update(double delta)
{
	Screen::update(delta);

	//Object_Tracking_Character(1);

	Screen::Character_Room_Collision_Detection();
	Screen::Character_Objects_Collision_Detection();

	if (!roomBox.collision_detection_in(character->get_box(), character->getCdelta(3)))
	{
		character->setRightCollision(true);
	}
	else
		character->setRightCollision(false);

	/*if (!GS::inCinematic() && !character->getWatched()) {
		if (character->getposX() > 5)
		{
			GS::setCinematic(true);
			character->loadCinematic("test_cine");
		}
	}*/

	//if (sqrt(pow((GS::character->getposX() - objs.at(0).getCog()[0]),2)+ pow(( (-18)- objs.at(0).getCog()[1]), 2)+ pow((GS::character->getposZ() - objs.at(0).getCog()[2]), 2))<3) {
	if(GS::character->checkInteract() && GS::character->checkCollision()){
		objs.at(0).use();
	}
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
