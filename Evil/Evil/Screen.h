#pragma once

//#include "GLApp.h"
#include <GLFW\glfw3.h>

#include "Character.h"
#include "Matrices.h"
#include "GLUtil.h"

using namespace std;

class Screen
{
public:
	Screen()
	{
	}

	virtual ~Screen()
	{
	}

	virtual void update(double delta) = 0
	{
		//cout << "Screen.h의 update(delta)" << endl;
	}

	virtual void render() = 0
	{
		//cout << "Screen.h의 render()" << endl;
		//cout << "여기에 모든 Screen에서 적용할 model, view 행렬을 호출하면 된다." << endl;

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		Matrix4 look = GLUtil::LookAt(GS::character->getPosition() + Vector3(0, 1, 0), GS::character->getLook(), Vector3(0, 1, 0));
		glLoadMatrixf(look.get());
	}

private:
};