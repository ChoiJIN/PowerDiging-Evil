#pragma once

#include "Matrices.h"

// make LookAt matrix 
class GLUtil {
public:
	static Matrix4 LookAt(const Vector3& eye, const Vector3& at, const Vector3& up);
};
