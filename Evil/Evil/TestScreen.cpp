#include "TestScreen.h"

#include "ImageLoader.h"

TestScreen::TestScreen()
{
	// object initializtion
	objs.push_back(Object(Vector3(10, -18, 0)));
	Object& apple = objs[0];
	apple.loadObj("apple");
	apple.set_passable(false);
	apple.setTracking(true);
	apple.set_type(1);
	apple.trackpos(character->getPosition());

	objs.push_back(Object(Vector3(10, -18, 0)));
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

	if (GS::inCinematic()) {
		character->playCinematic();
		if (character->currentFrame > character->maxFrame - 1) {
			character->alreadyWatched(); // ??????????????? ???? ??????? ??
			GS::setCinematic(false); // ??? ??????? ???? ??? ??????? ???.
			character->currentFrame = 0;
		}
	}
	else {
		character->RefreshCamera();
	}


	Object_Tracking_Character(0);

	Screen::Character_Room_Collision_Detection();
	Screen::Character_Objects_Collision_Detection();

	if (!roomBox.collision_detection_in(character->get_box(), character->getCdelta(3)))
	{
		character->setRightCollision(true);
	}
	else
		character->setRightCollision(false);

	if (GS::character->checkInteract() && GS::character->checkCollision()) {  // 인터렉션과 콜리젼을 둘다 체크.
		objs.erase(objs.begin()); // 현재는 0번째 물체가 콜리젼 실험대상이었으므로 0번을 제거.
		character->setLife(character->getLife()+1);
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
