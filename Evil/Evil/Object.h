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
	bool collision = false;
	Vector3 cog;
	float cogx;
	float cogy;
	float cogz;
	Vector3 trackPosition;
	Vector3 speed = Vector3(0.f, 0.f, 0.f);
	Matrix4 obj_matrix;
	Box Collision_Box;
	CObjLoader loader;
	unsigned char tracking = 0; // 0 : 애초에 추적하는 물체가 아님, 1 : 추적하는 물체이고 추적 중, 2 : 추적하는 물체이지만 정지한 상태
	unsigned char type = 0; // 충돌할 경우 데미지를 주는 타입인지, 아닌지를 확인해야 한다. 0 : 일반 오브젝트, 1 : 데미지를 1씩 준다. 2 : 먹을 수 있다.

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
	void update(double delta);

	void use();

	void setCollision(bool b);
	bool getCollision();

	void setTracking(unsigned char t);
	unsigned char getTracking();

	void setTarget(Vector3 vec);
	Vector3 get_trackposition();
	
	void set_speed(Vector3 v);
	Vector3 get_speed();

	Box get_box();
	void setBoxSize(int X, int Y, int Z);
	//

	Vector3 getCog();
	float getCogX();
	float getCogY();
	float getCogZ();

	//
	Matrix4 get_matrix();
};

