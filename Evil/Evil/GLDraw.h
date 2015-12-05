#pragma once
#include <GLFW/glfw3.h>
#include "Matrices.h"

class GLDraw {
public:
	static void plane(const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& d);
	static void plane(Vector3 pts[4]);
	static void planeTexture(Vector3 pts[4], GLuint textureId);
	static void planeTexture(const Vector3 & a, const Vector3 & b, const Vector3 & c, const Vector3 & d, GLuint textureId);
	
	// size: ���� ũ��(������ü)
	// textureId: 0~3(����), 4(�Ʒ���), 5(����)
	static void room(float size, GLuint textureId[6]);
};
