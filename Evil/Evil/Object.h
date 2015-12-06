#pragma once
#include <string>
#include <vector>
#include "Vectors.h"
#include "ObjLoader.h"
#include "Box.h"
#include <GL/glew.h>

using namespace std;
class Object
{
private:
	string id;
	GLuint texture = 0;
	bool passable = true;
	Vector3 cog;
	Vector3 trackPosition;
	Vector3 speed = Vector3(0.f, 0.f, 0.f);
	Matrix4 obj_matrix;
	Box Collision_Box;
	CObjLoader loader;
	bool tracking = false;
	unsigned char type = 0; // 충돌할 경우 데미지를 주는 타입인지, 아닌지를 확인해야 한다. 0 : 일반 오브젝트, 1 : 데미지를 1씩 준다.

public:
	Object();
	Object(Vector3 center);
	~Object();

	void set_passable(bool b);
	bool get_passable();

	void set_type(unsigned char c);
	unsigned char get_type();

	void loadObj(string filename);

	void draw();

	void use();

	void setTracking(bool t);
	bool getTracking();

	void trackpos(Vector3 vec);
	Vector3 get_trackposition();

	Box get_box();

	Matrix4 get_matrix();
};

