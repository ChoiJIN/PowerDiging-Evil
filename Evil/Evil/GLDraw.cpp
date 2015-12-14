#include "GLDraw.h"

void GLDraw::plane(const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& d)
{
	glBegin(GL_QUADS);
	glVertex3d(a.x, a.y, a.z);
	glVertex3d(b.x, b.y, b.z);
	glVertex3d(c.x, c.y, c.z);
	glVertex3d(d.x, d.y, d.z);
	glEnd();
}

void GLDraw::plane(Vector3 pts[4])
{
	plane(pts[0], pts[1], pts[2], pts[3]);
	glBegin(GL_QUADS);
	for (int i = 0; i < 4; i++)
		glVertex3d(pts[i].x, pts[i].y, pts[i].z);
	glEnd();
}

void GLDraw::planeTexture(Vector3 pts[4], GLuint textureId)
{
	glBindTexture(GL_TEXTURE_2D, textureId);
	glBegin(GL_QUADS);
	for (int i = 0; i < 4; i++)
		glVertex3d(pts[i].x, pts[i].y, pts[i].z);
	glEnd();
}

void GLDraw::planeTexture(const Vector3 & a, const Vector3 & b, const Vector3 & c, const Vector3 & d, GLuint textureId)
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, textureId);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);
	glVertex3d(a.x, a.y, a.z);
	glTexCoord2d(1, 1);
	glVertex3d(b.x, b.y, b.z);
	glTexCoord2d(1, 0);
	glVertex3d(c.x, c.y, c.z);
	glTexCoord2d(0, 0);
	glVertex3d(d.x, d.y, d.z);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void GLDraw::room(float size, GLuint textureId[6])
{
	Vector3 pts[8];
	pts[0] = Vector3(0, 0, 0) - Vector3(size, size, size);
	pts[1] = pts[0] + Vector3(0, size, 0);
	pts[2] = pts[0] + Vector3(2 * size, size, 0);
	pts[3] = pts[0] + Vector3(2 * size, 0, 0);
	pts[4] = pts[0] + Vector3(2 * size, 0, 2 * size); // (+ - +)
	pts[5] = pts[0] + Vector3(2 * size, size, 2 * size); // (+ 0 +)
	pts[6] = pts[0] + Vector3(0, size, 2 * size); // (- 0 +)
	pts[7] = pts[0] + Vector3(0, 0, 2 * size); // (- - +) 내 생각에는 7->4->5->6

	// side
	planeTexture(pts[7], pts[0], pts[1], pts[6], textureId[0]);
	planeTexture(pts[0], pts[3], pts[2], pts[1], textureId[1]);
	planeTexture(pts[3], pts[4], pts[5], pts[2], textureId[2]);
	planeTexture(pts[4], pts[7], pts[6], pts[5], textureId[3]);

	// bottom
	planeTexture(pts[3], pts[0], pts[7], pts[4], textureId[4]);

	// top
	planeTexture(pts[1], pts[2], pts[5], pts[6], textureId[5]);
}