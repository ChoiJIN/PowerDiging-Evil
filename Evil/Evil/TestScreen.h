#pragma once

#include "GLCube.h"


#include "GS.h"
#include "Screen.h"
#include "GLDraw.h"

class TestScreen :
	public Screen
{
private:
	Object obj;

public:
	TestScreen();
	~TestScreen();
	
	virtual void update(double delta);
	virtual void render();
};

