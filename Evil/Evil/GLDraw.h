#pragma once
#include <GLFW/glfw3.h>
#include "Matrices.h"

class GLDraw {
public:
	static void plane(const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& d);
	static void plane(Vector3 pts[4]);
	static void planeWithTexture(Vector3 pts[4], int textureId);
	
	// size: ¹æÀÇ Å©±â(Á¤À°¸éÃ¼)
	// textureId: 0~3(¿·¸é), 4(¾Æ·§¸é), 5(À­¸é)
	static void room(float size, int textureId[6]);
};
