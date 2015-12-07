#include "TestScreen.h"

#include "ImageLoader.h"

TestScreen::TestScreen()
{
	// object initializtion
	// 0�� ������Ʈ�� ��
	objs.push_back(Object(Vector3(GS::option.roomSize, -18, 0)));
	objs[0].loadObj("apple");

	objs.push_back(Object(Vector3(5, -18, 0)));
	objs[1].loadObj("apple");
	objs[1].set_passable(false);

	objs.push_back(Object(Vector3(10, -18, 0)));
	objs[2].loadObj("apple");
	objs[2].set_passable(false);
	objs[2].setTracking(true);
	objs[2].set_type(1);
	objs[2].trackpos(character->getPosition());

	roomBox = Box(Vector3(0.f, 0.f, 0.f), (GS::option.roomSize * 2), (GS::option.roomSize * 2) + 4, (GS::option.roomSize * 2));
}


TestScreen::~TestScreen()
{
}

void TestScreen::update(double delta)
{
	Screen::update(delta);
	Screen::Object_Object_Collision_Detection();

	GS::debug.log(to_string(character->getposX()));

	//if (!GS::inCinematic() && !character->getWatched()) {
	//	if (character->getposX() > 0.5)
	//	{
	//		GS::setCinematic(true);
	//		character->loadCinematic("test_cine");

	//	}
	//}

	Object_Tracking_Character(objs.size() - 1);

	Screen::Character_Room_Collision_Detection();
	Screen::Character_Objects_Collision_Detection();

	if (GS::character->checkInteract() && GS::character->checkCollision()) {  // ���ͷ��ǰ� �ݸ����� �Ѵ� üũ.
		objs.erase(objs.begin()+1); // ����� 0��° ��ü�� �ݸ��� �������̾����Ƿ� 0���� ����.
		character->resetCollision();
		character->setLife(character->getLife() + 1);
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
