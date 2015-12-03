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
	obj_matrix.translate(center);
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
	glTranslatef(cog.x, cog.y, cog.z);
	loader.Draw();
	glTranslatef(-cog.x, -cog.y, -cog.z);
}

void Object::use()
{
}

Box Object::get_box()
{
	return Collision_Box;
}

Matrix4 Object::get_matrix()
{
	return obj_matrix;
}
