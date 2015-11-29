#pragma once
#include <GL/glew.h>

class GLPrimitive {
public:
	GLuint vertexBuffer;

	virtual void draw() = 0;

};
