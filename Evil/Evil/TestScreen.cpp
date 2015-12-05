#include "TestScreen.h"

#include "ImageLoader.h"

TestScreen::TestScreen()
{
	Object obj;
	// object initializtion
	objs.push_back(Object());
	objs[0].loadObj("apple");
	objs.push_back(Object(Vector3(10, 0, 0)));
	objs[1].loadObj("apple");
}


TestScreen::~TestScreen()
{
}

void TestScreen::update(double delta)
{
	Screen::update(delta);
}

void TestScreen::render()
{
	Screen::render();
	//cout << "Screen.h의 render()" << endl;s
	//cout << "여기에 모든 Screen에서 적용할 model, view 행렬을 호출하면 된다." << endl;
	Screen::render();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	Matrix4 look = GLUtil::LookAt(GS::character->getPosition(), GS::character->getLook(), Vector3(0, 1, 0));
	Matrix4 perspective = GLUtil::perspective(90.f, 1, 0.01f, 100.0f);
	glLoadIdentity();
	glMultMatrixf(perspective.get());
	glMultMatrixf(look.get());

	for (size_t i = 0; i < objs.size(); i++) {
		glMultMatrixf(objs[i].get_matrix().get());
		objs[i].draw();
		glMultMatrixf(objs[i].get_matrix().invert().get());
	}
	GLuint t[6] = { 
		ImageLoader::getTextureId("back_wall.png"),
		ImageLoader::getTextureId("side_wall.png"),
		ImageLoader::getTextureId("front_wall.png"),
		ImageLoader::getTextureId("side_wall.png"),
		ImageLoader::getTextureId("bottom_wall.png"),
		ImageLoader::getTextureId("top_wall.png")
	};
	GLDraw::room(GS::option.roomSize, t);
}
