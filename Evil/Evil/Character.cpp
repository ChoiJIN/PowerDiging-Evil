#define _USE_MATH_DEFINES

#include "Character.h"
#include "Vectors.h"
#include "GS.h"
#include "Matrices.h"
#include <cmath>

Character::Character()
{
	position = Vector3(0, 0, 0);
	look = Vector3(0, 0, 1);
	posX = 0;
	posY = 0;
	posZ = 0;
	yaw = 0.0;
	pitch = 0.0;
}

Character::~Character()
{
}

void Character::RefreshCamera() {

	lookX = cosf(yaw) * cosf(pitch);
	lookY = sinf(pitch);
	lookZ = sinf(yaw) * cosf(pitch);

	strafe_lx = cosf(yaw - (float)M_PI_2);
	strafe_lz = sinf(yaw - (float)M_PI_2);

	position = Vector3(posX, posY, posZ);
	look = Vector3(position.x + lookX, position.y + lookY, position.z + lookZ);
}

void Character::moveCameraFB(float incrs) {

	float lx = cos(yaw) * cos(pitch);
	float ly = sin(pitch);
	float lz = sin(yaw) * cos(pitch);

	posX = posX + incrs*lx;
	posY = posY + incrs*ly;
	posZ = posZ + incrs*lz;

	RefreshCamera();
}
void Character::moveCameraRL(float incrs) {

	posX = posX + incrs*strafe_lx;
	posZ = posZ + incrs*strafe_lz;

	RefreshCamera();
}


void Character::rotateCamera(double mouseX, double mouseY)
{
	const float limit = 30.0f * (float)M_PI / 180.0f;
		float g_rotation_speed = (float)M_PI / 180 * 0.2f;
		float diffX = (float)(mouseX - 300);
		float diffY = (float)(mouseY - 300);

		diffX *= g_rotation_speed;
		diffY *= g_rotation_speed;


		yaw += (float)diffX;
		pitch -= (float)diffY;

		if (pitch < -limit)
			pitch = -limit;

		if (pitch > limit)
			pitch = limit;

		RefreshCamera();
}

const Vector3& Character::getPosition() const
{
	return position;
}

const Vector3 & Character::getLook() const
{
	return look;
}