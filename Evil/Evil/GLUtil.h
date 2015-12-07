#pragma once

#include "Matrices.h"
#define M_PI       3.14159265358979323846

template <typename T>
inline T radians(T angleInDegrees)
{
	return angleInDegrees * static_cast<T>(M_PI / 180.0);
}

// make LookAt matrix 
class GLUtil {
public:
	static Matrix4 LookAt(const Vector3& eye, const Vector3& at, const Vector3& up);
	static Matrix4 perspective(float fovy, float aspect, float n, float f);
	static Matrix4 frustum(float left, float right, float bottom, float top, float n, float f);
	static Matrix4 Ortho(const float left, const float right, const float bottom, const float top, const float zNear, const float zFar);

};