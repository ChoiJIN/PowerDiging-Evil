#pragma once

#include <iostream>
#include <gl/glew.h>

#include "GS.h"
#include "Screen.h"
#include "GLDraw.h"

class TestScreen :
	public Screen
{

public:
	TestScreen();
	~TestScreen();
	
	virtual void update(double delta);
	virtual void render();
};

