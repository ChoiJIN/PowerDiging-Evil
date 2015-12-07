#pragma once

#include <iostream>
#include <gl/glew.h>

#include "GS.h"
#include "Screen.h"
#include "GLDraw.h"

class SecondRoom : public Screen
{
public:
	SecondRoom();
	~SecondRoom();

	virtual void update(double delta);
	virtual void render();
};

