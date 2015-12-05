#define _USE_MATH_DEFINES

#include "Character.h"
#include "Vectors.h"
#include "GS.h"
#include "Matrices.h"
#include <cmath>

Character::Character()
{
	float initialY = GS::option.characterHeight - GS::option.roomSize;
	position = Vector3(0, initialY, 0);
	look = Vector3(0, initialY, 1);
	Collision_Box = Box(position, 4, 4, 4);
	yaw = 0.0;
	pitch = 0.0;
}

Character::~Character()
{
}

void Character::RefreshCamera() {
	if (front_move)
		moveCameraFB(GS::moveSpeed);
	if (back_move)
		moveCameraFB(-GS::moveSpeed);
	if (left_move)
		moveCameraRL(GS::moveSpeed);
	if (right_move)
		moveCameraRL(-GS::moveSpeed);

	look.x = cos(yaw) * cos(pitch);
	look.y = sin(pitch);
	look.z = sin(yaw) * cos(pitch);

	strafe_lx = cos(yaw - (float)M_PI_2);
	strafe_lz = sin(yaw - (float)M_PI_2);

	look = Vector3(position.x + look.x, position.y + look.y, position.z + look.z);
}

void Character::moveCameraFB(float incrs) {

	float lx = cos(yaw) * cos(pitch);
	float ly = sin(pitch);
	float lz = sin(yaw) * cos(pitch);

	position.x = position.x + incrs*lx;
	position.z = position.z + incrs*lz;
	Collision_Box.move_box(Vector3(incrs*lx, 0, incrs*lz));
}
void Character::moveCameraRL(float incrs) {

	position.x = position.x + incrs*strafe_lx;
	position.z = position.z + incrs*strafe_lz;
	Collision_Box.move_box(Vector3(incrs*strafe_lx, 0, incrs*strafe_lz));
}

Box Character::get_box()
{
	return Collision_Box;
}

bool Character::collision_check(Box B, Vector3 delta)
{
	if (Collision_Box.collision_detection_3D(B, delta))
		return true;
	else
		return false;
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
}

void Character::printState()
{
	switch (state)
	{
	case 0:
		cout << "당신은 정상 상태입니다. = 0" << endl;
		break;
	case 1:
		cout << "당신은 상처를 입었습니다. = 1" << endl;
		break;
	case 2:
		cout << "당신은 공포에 질려 있습니다. = 2" << endl;
		break;
	default:
		break;
	}
}

void Character::setState(unsigned char s)
{
	state = s;
}

unsigned char Character::getLife()
{
	return Life;
}

void Character::setLife(unsigned char life)
{
	Life = life;
}

const Vector3& Character::getPosition() const
{
	return position;
}

const Vector3 & Character::getLook() const
{
	return look;
}

void Character::setFrontMove(bool b)
{
	front_move = b;
}

void Character::setBackMove(bool b)
{
	back_move = b;

}

void Character::setLeftMove(bool b)
{
	left_move = b;
}

void Character::setRightMove(bool b)
{
	right_move = b;
}
