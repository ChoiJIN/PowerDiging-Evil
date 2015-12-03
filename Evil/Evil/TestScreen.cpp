#include "TestScreen.h"


TestScreen::TestScreen()
{
	// object initializtion
	objs.push_back(Object());
	objs[0].loadObj("apple");
//	obj.loadObj("apple");
}


TestScreen::~TestScreen()
{
}

void TestScreen::update(double delta)
{
	//cout << "Screen.h�� update(delta)" << endl;
	// ���⿡�� object���� collision detection�� animation�� ����

	//		cout << "Screen update" << endl;
	//		cout << "obj size = " << objs.size() << endl;
	for (size_t i = 0; i < objs.size(); i++)
	{
//		cout << objs[i].get_box().get_cog() << endl;
//		cout << GS::character->get_box().get_cog() << endl;
		if (GS::character->collision_check(objs[i].get_box(), Vector3(0.f, 0.f, 0.f))
			|| objs[i].get_box().collision_detection_3D(GS::character->get_box(), Vector3(0.f, 0.f, 0.f))) // �浹 ������ �ϸ� true, �ƴϸ� false �̰ɷ� �� ���� ������ ����.
		{
			cout << "objs[" << i << "] �浹 ����" << endl;
//			cout << "������Ʈ �ڽ��� ���� �߽� = " << objs[i].get_box().get_cog() << endl;
//			cout << "ĳ���� �ڽ��� ���� �߽� = " << GS::character->get_box().get_cog() << endl;
		}
		cout << "������Ʈ �ڽ��� ���� �߽� = " << objs[i].get_box().get_cog() << endl;
		cout << "ĳ���� �ڽ��� ���� �߽� = " << GS::character->get_box().get_cog() << endl;

	}
}

void TestScreen::render()
{
	//cout << "Screen.h�� render()" << endl;s
	//cout << "���⿡ ��� Screen���� ������ model, view ����� ȣ���ϸ� �ȴ�." << endl;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	Matrix4 look = GLUtil::LookAt(GS::character->getPosition(), GS::character->getLook(), Vector3(0, 1, 0));
	Matrix4 perspective = GLUtil::perspective(90.f, 1, 0.01f, 100.0f);
	glLoadIdentity();
	glMultMatrixf(perspective.get());
	glMultMatrixf(look.get());

	for (size_t i = 0; i < objs.size(); i++) {

	}

	int t[6] = {};
	//GLDraw::room(200.0, t);
	//GLDraw::drawPlane(Vector3(-0.2, 0.2, 0), Vector3(0.2, 0.2, 0), Vector3(0.2, -0.2, 0), Vector3(-0.2, -0.2, 0));

	/*GLCube cube;
	cube.draw();*/

	objs[0].draw();
//	obj.draw();

	//cout << GS::character->getLook() << endl;
}
