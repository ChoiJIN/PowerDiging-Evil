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