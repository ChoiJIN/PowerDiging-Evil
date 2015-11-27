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
		//cout << "Screen.h�� update(delta)" << endl;
	}

	virtual void render() = 0
	{
		//cout << "Screen.h�� render()" << endl;
		//cout << "���⿡ ��� Screen���� ������ model, view ����� ȣ���ϸ� �ȴ�." << endl;

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		Matrix4 look = GLUtil::LookAt(GS::character->getPosition(), GS::character->getLook(), Vector3(0, 1, 0));
		Matrix4 perspective = GLUtil::perspective(90, 1, 0.01, 1000.0);
		glLoadIdentity();
		glMultMatrixf(perspective.get());
		glMultMatrixf(look.get());
		//		glLoadMatrixf(look.get());

	}

private:
};