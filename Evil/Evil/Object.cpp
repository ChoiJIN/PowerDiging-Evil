#include "Object.h"



Object::Object()
{
	cog = Vector3(0.f, 0.f, 0.f);
	obj_matrix.identity();
	Collision_Box = Box(cog, 2, 1, 2);
}

Object::Object(Vector3 center)
{
	cog = center;
	obj_matrix.identity();
	Collision_Box = Box(cog, 2, 1, 2);
}

Object::~Object()
{
}

void Object::set_passable(bool b)
{
	passable = b;
}

bool Object::get_passable()
{
	return passable;
}

void Object::loadObj(string fileName)
{
	string objName = "Model/" + fileName + ".obj";
	string materialName = "Model/" + fileName + ".mtl";
	loader.Load(objName.c_str(), materialName.c_str());
}

void Object::set_type(unsigned char c)
{
	type = c;
}
unsigned char Object::get_type()
{
	return type;
}

void Object::draw()
{
	if (!tracking)
	{
		loader.Draw(cog);
	}
	else
	{
		cog += speed;
		Collision_Box.move_box(speed);
		loader.Draw(cog);
	}
}
//
void Object::use()
{
	cog += Vector3(0, 2, 0);
	
	loader.Draw(cog);
}

Vector3 Object::getCog() {
	return cog;
}

float Object::getCogX() {
	return cog[0];
}

float Object::getCogY() {
	return cog[1];
}

float Object::getCogZ() {
	return cog[2];
}

//

void Object::setTracking(bool t) // Ʈ��ŷ �� ���� �� ���� ����
{
	tracking = t;
}

bool Object::getTracking()
{
	return tracking;
}

void Object::trackpos(Vector3 vec) // ������ Ʈ��ŷ���� ����
{
	trackPosition = vec;
	speed = 0.02f*tracking*(trackPosition - cog);
}

Vector3 Object::get_trackposition()
{
	return trackPosition;
}

Box Object::get_box()
{
	return Collision_Box;
}

void Object::setBoxSize(int X, int Y, int Z)
{
	Collision_Box.set_box(cog, X, Y, Z);
}

Matrix4 Object::get_matrix()
{
	return obj_matrix;
}