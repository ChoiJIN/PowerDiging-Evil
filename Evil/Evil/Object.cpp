#include "Object.h"



Object::Object()
{
	cog = Vector3(0.f, 0.f, 0.f);
	obj_matrix.identity();
	Collision_Box = Box(cog, 2, 2, 2);
}

Object::Object(Vector3 center)
{
	cog = center;
	obj_matrix.identity();
//	obj_matrix.translate(center);
	Collision_Box = Box(cog, 2, 2, 2);
}

Object::~Object()
{
}

void Object::loadObj(string fileName)
{
	string objName = "Model/" + fileName + ".obj";
	string materialName = "Model/" + fileName + ".mtl";
	loader.Load(objName.c_str(), materialName.c_str());
}

unsigned char Object::get_type()
{
	return type;
}

void Object::draw()
{
	speed = 0.005*tracking*(trackPosition - cog);
	if (!tracking)
	{
//		speed = Vector3(0.f, 0.f, 0.f);
		loader.Draw(cog);
	}
	else
	{
		cog += speed;
		Collision_Box.move_box(speed);
		loader.Draw(cog);
//		cout << "obj의 속도 = " << speed << endl;
//		cout << "목표의 위치 = " << trackPosition << endl;
//		cout << "obj의 위치 = " << cog << endl;
	}
}

void Object::use()
{
}

void Object::setTracking(bool t) // 트래킹 할 건지 말 건지 결정
{
	tracking = t;
}

bool Object::getTracking()
{
	return tracking;
}

void Object::trackpos(Vector3 vec) // 누구를 트래킹할지 결정
{
	trackPosition = vec;
}

Box Object::get_box()
{
	return Collision_Box;
}

Matrix4 Object::get_matrix()
{
	return obj_matrix;
}
