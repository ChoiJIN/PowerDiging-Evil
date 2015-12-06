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
}


TestScreen::~TestScreen()
{
}

void TestScreen::update(double delta)
{
	Screen::update(delta);
	objs[1].trackpos(character->getPosition());
	
	//GS::debug.log(to_string((GS::character->getposX())));

	if (!GS::inCinematic()) {
		if (GS::character->getposX()>5 && !GS::character->getWatched())
		{
			GS::setCinematic(true);
			GS::character->loadCinematic("cineFile_01");
			/*if (GS::inCinematic()) {
				cout << GS::character->getposX() << " " << GS::character->getposZ() << " ";
				GS::character->showCameraPosition();
			}*/
		}
	}
	//else {
	//	GS::character->playCinematic();
	//	// character pos set
	//}
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
