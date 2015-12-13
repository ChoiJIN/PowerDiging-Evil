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
	loader.Draw(cog);
}
//

void Object::update(double delta)
{
	if (collision == false && tracking == 1)
	{
		cog += speed;
		Collision_Box.move_box(speed);
	}
	else if (tracking == 2)
		tracking = 1;
}

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

void Object::setCollision(bool b)
{
	collision = b;
}

bool Object::getCollision()
{
	return collision;
}

void Object::setTracking(unsigned char t) // 트래킹 안하는 물체로 바꿀건지, 정지할 건지, 트래킹 할 건지
{
	tracking = t;
}

unsigned char Object::getTracking()
{
	return tracking;
}

void Object::setTarget(Vector3 vec) // 누구를 트래킹할지 결정
{
	trackPosition = vec;
	speed = Vector3(0.1f*(trackPosition - cog).normalize().x, 0, 0.1f*(trackPosition - cog).normalize().z);
}

Vector3 Object::get_trackposition()
{
	return trackPosition;
}

void Object::set_speed(Vector3 v)
{
	speed = v;
}

Vector3 Object::get_speed()
{
	return speed;
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
