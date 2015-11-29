#pragma once
#include <string>
#include <vector>
#include "Vectors.h"
#include "ObjLoader.h"
#include <GL/glew.h>

using namespace std;
class Object
{
private:
	CObjLoader loader;
	Vector3 position;

public:
	Object();
	~Object();

	void loadObj(string filename);

	void draw();

	void use();

	void setPosition(float x, float y, float z);
};

