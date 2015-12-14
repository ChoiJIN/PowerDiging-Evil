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
	modelview = GLUtil::LookAt(Vector3(0.f, 0.f, 1.f), Vector3(0.f, 0.f, 10.f), Vector3(0, 1, 0));

	glLoadIdentity();
	glMultMatrixf(modelview.get());


	GLuint t = ImageLoader::getTextureId("Evil_Title.jpg");
	GLDraw::planeTexture(Vector3(10.f, -10.f, 10.f), Vector3(-10.f, -10.f, 10.f), Vector3(-10.f, 10.f, 10.f), Vector3(10.f, 10.f, 10.f), t);
} // 0123 -> 1032