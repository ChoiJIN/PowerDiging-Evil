#include "StartScreen.h"
#include "GLApp.h"
#include "ImageLoader.h"

StartScreen::StartScreen()
{
	tes = TestScreen();
}


StartScreen::~StartScreen()
{
}

void StartScreen::update(double delta)
{
	if (GS::getPageUpDown() == 1)
	{
		GLApp::getInstance()->pushScreen(&tes);
		ImageLoader::loadTexture("brick.jpg");
		ImageLoader::loadTexture("brick_door.jpg");
		ImageLoader::loadTexture("brick_bottom.jpg");
		GS::setKeyInterface(1);
		GS::setPageUpDown(0);
	}
}

void StartScreen::render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// UI
	glMatrixMode(GL_PROJECTION);
	perspective = GLUtil::Ortho(-10, 10, -10, 10, 0.01, 100);
	glLoadMatrixf(perspective.get());

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	GLuint t = ImageLoader::getTextureId("Start_Title.jpg");
	GLDraw::planeTexture(Vector3(-1.f, -1.f, 1.f), Vector3(1.f, -1.f, 1.f), Vector3(1.f, 1.f, 1.f), Vector3(-1.f, 1.f, 1.f), t);
}