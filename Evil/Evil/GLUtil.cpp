#include "GLUtil.h"

Matrix4 GLUtil::LookAt(const Vector3 & eye, const Vector3 & at, const Vector3 & up)
{
	Vector3 n = (eye - at).normalize();
	Vector3 u = up.cross(n);
	Vector3 v = n.cross(u).normalize();
	Vector3 p = Vector3(0.0, 0.0, 0.0);
	Matrix4 c(
		u.x, v.x, n.x, p.x,
		u.y, v.y, n.y, p.y,
		u.z, v.z, n.z, p.z,
		0, 0, 0, 1
		);
	Matrix4 meye;
	meye.translate(-eye);
	return c * meye;
}

Matrix4 GLUtil::perspective(float fovy, float aspect, float n, float f)
{
	float q = 1.0f / tan(radians(0.5f * fovy));
	float A = q / aspect;
	float B = (n + f) / (n - f);
	float C = (2.0f * n * f) / (n - f);

	Matrix4 result(
		A, 0.0f, 0.0f, 0.0f,
		0.0f, q, 0.0f, 0.0f,
		0.0f, 0.0f, B, -1.0f,
		0.0f, 0.0f, C, 0.0f);

	//	result[0] = Vector4(A, 0.0f, 0.0f, 0.0f);
	//	result[1] = Vector4(0.0f, q, 0.0f, 0.0f);
	//	result[2] = Vector4(0.0f, 0.0f, B, -1.0f);
	//	result[3] = Vector4(0.0f, 0.0f, C, 0.0f);

	return result;
}

Matrix4 GLUtil::frustum(float left, float right, float bottom, float top, float n, float f)
{
	Matrix4 result;
	result.identity();

	if ((right == left) ||
		(top == bottom) ||
		(n == f) ||
		(n < 0.0) ||
		(f < 0.0))
		return result;

	result = Matrix4(
		(2.0f * n) / (right - left), 0.0f, 0.0f, 0.0f,
		0.0f, (2.0f * n) / (top - bottom), 0.0f, 0.0f,
		(right + left) / (right - left), (top + bottom) / (top - bottom), -(f + n) / (f - n), -1.0f,
		0.0f, 0.0f, -(2.0f * f * n) / (f - n), 0.0f);
	return result;
}

Matrix4 GLUtil::Ortho(const float left, const float right, const float bottom, const float top, const float zNear, const float zFar)
{
	Matrix4 c;
	c[0] = 2.0 / (right - left);
	c[5] = 2.0 / (top - bottom);
	c[10] = 2.0 / (zNear - zFar);
	c[15] = 1.0;
	c[12] = -(right + left) / (right - left);
	c[13] = -(top + bottom) / (top - bottom);
	c[14] = -(zFar + zNear) / (zFar - zNear);
	return c;
}
