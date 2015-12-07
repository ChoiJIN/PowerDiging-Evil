#include "SecondRoom.h"

#include "ImageLoader.h"

SecondRoom::SecondRoom()
{
}


SecondRoom::~SecondRoom()
{
}

void SecondRoom::update(double delta)
{
	Screen::update(delta);
	character->RefreshCamera();

}

void SecondRoom::render()
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
