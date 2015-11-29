#include "Object.h"



Object::Object()
{
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

void Object::draw()
{
	glTranslatef(position.x, position.y, position.z);
	loader.Draw();
	glTranslatef(-position.x, -position.y, -position.z);
}

void Object::use()
{
}

void Object::setPosition(float x, float y, float z)
{
	this->position.x = x;
	this->position.y = y;
	this->position.z = z;

}


