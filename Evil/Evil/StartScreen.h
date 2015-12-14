#pragma once

#include <iostream>
#include <gl/glew.h>

#include "GS.h"
#include "Screen.h"
#include "TestScreen.h"
#include "GLDraw.h"

class StartScreen :
	public Screen
{

public:
	StartScreen();
	~StartScreen();

	virtual void update(double delta);
	virtual void render();

private:
	TestScreen tes;
};