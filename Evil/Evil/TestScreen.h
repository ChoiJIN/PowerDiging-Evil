#pragma once

#include <GLFW/glfw3.h>
#include "GS.h"
#include "Screen.h"
class TestScreen :
	public Screen
{
public:
	TestScreen();
	~TestScreen();
	
	void update(double delta);
	void render();
};

