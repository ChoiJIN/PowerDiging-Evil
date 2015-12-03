#pragma once

//#include "GLApp.h"
#include <GLFW\glfw3.h>
#include <vector>

#include "Character.h"
#include "Object.h"
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
		// 여기에서 object들의 collision detection과 animation을 수행

//		cout << "Screen update" << endl;
//		cout << "obj size = " << objs.size() << endl;
		for (size_t i = 0; i < objs.size(); i++)
		{
//			cout << "objs[" << i << "] 충돌 감지" << endl;
			if (GS::character->collision_check(objs[i].get_box(), Vector3(0.f, 0.f, 0.f))) // 충돌 했을때 하면 true, 아니면 false 이걸로 뭘 할진 생각해 보자.
			{
				cout << "objs[" << i << "] 충돌 감지" << endl;
			}
		}
	}

	virtual void render() = 0
	{
		//cout << "Screen.h의 render()" << endl;s
		//cout << "여기에 모든 Screen에서 적용할 model, view 행렬을 호출하면 된다." << endl;

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		Matrix4 look = GLUtil::LookAt(GS::character->getPosition(), GS::character->getLook(), Vector3(0, 1, 0));
		Matrix4 perspective = GLUtil::perspective(90.f, 1, 0.01f, 100.0f);
		glLoadIdentity();
		glMultMatrixf(perspective.get());
		glMultMatrixf(look.get());

		glTranslatef(0, -GS::option.roomSize, 0);
		for (size_t i = 0; i < objs.size(); i++) {
			objs[i].draw();
		}
		glTranslatef(0, GS::option.roomSize, 0);
	}

protected:
	std::vector<Object> objs;

};