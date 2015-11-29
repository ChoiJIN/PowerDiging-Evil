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
	string id;
	GLuint texture = 0;
	CObjLoader loader;

public:
	Object();
	~Object();

	void loadObj(string filename);

	void draw();

	void use();
};

