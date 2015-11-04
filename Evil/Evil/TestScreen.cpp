#include "TestScreen.h"



TestScreen::TestScreen()
{
}


TestScreen::~TestScreen()
{
}

void TestScreen::update(double delta)
{
}

void TestScreen::render()
{
	GS::debug.log("render");
	glClearColor(1.0f, 0.3f, 0.3f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	
}
