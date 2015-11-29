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
	loader.Draw();
}

void Object::use()
{
}


