#include "GLDraw.h"

void GLDraw::drawPlane(const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& d)
{
	glBegin(GL_QUADS);
	glVertex3d(a.x, a.y, a.z);
	glVertex3d(b.x, b.y, b.z);
	glVertex3d(c.x, c.y, c.z);
	glVertex3d(d.x, d.y, d.z);
	glEnd();
}

void GLDraw::drawPlane(Vector3 pts[4])
{
	drawPlane(pts[0], pts[1], pts[2], pts[3]);
	glBegin(GL_QUADS);
	for (int i = 0; i < 4; i++)
		glVertex3d(pts[i].x, pts[i].y, pts[i].z);
	glEnd();
}

void GLDraw::drawPlaneTexture(Vector3 pts[4], int textureId)
{
	glBegin(GL_QUADS);
	for (int i = 0; i < 4; i++)
		glVertex3d(pts[i].x, pts[i].y, pts[i].z);
	glEnd();
}

void GLDraw::drawRoom(float size, int textureId[6])
{
	Vector3 pts[8];
	pts[0] = Vector3(0, 0, 0) - Vector3(size, size, size);
	pts[1] = pts[0] + Vector3(2 * size, 0, 0);
	pts[2] = pts[1] + Vector3(0, 2 * size, 0);
	pts[3] = pts[2] + Vector3(-2 * size, 0, 0);
	pts[4] = Vector3(0, 0, 0) + Vector3(size, size, size);
	pts[5] = pts[4] + Vector3(-2 * size, 0, 0);
	pts[6] = pts[5] + Vector3(0, -2 * size, 0);
	pts[7] = pts[6] + Vector3(2 * size, 0, 0);

	// side
	glColor3d(1, 1, 1);
	drawPlane(pts[0], pts[3], pts[5], pts[6]);
	glColor3d(1, 0, 0);
	drawPlane(pts[0], pts[1], pts[2], pts[3]);
	glColor3d(1, 1, 1);
	drawPlane(pts[7], pts[4], pts[2], pts[1]);
	glColor3d(1, 1, 0);
	drawPlane(pts[6], pts[5], pts[4], pts[7]);

	// bottom
	glColor3d(0, 1, 0);
	drawPlane(pts[2], pts[4], pts[5], pts[3]);

	// top
	glColor3d(0, 0, 1);
	drawPlane(pts[7], pts[1], pts[0], pts[6]);
}