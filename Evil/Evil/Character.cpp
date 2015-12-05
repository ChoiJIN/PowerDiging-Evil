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
	Collision_Box = Box(position, 1, 1, 1);
	yaw = 0.0;
	pitch = 0.0;
}

Character::~Character()
{
}

void Character::RefreshCamera() { // moveFunction(float incrs, int type) type = 0 : FB, type = 1 : RL
// 0번 UP, 1번 DOWN, 2번 LEFT, 3번 RIGHT

	if (front_move && !front_collision)
		moveFunction(GS::moveSpeed, 0, true);
	if (back_move && !back_collision)
		moveFunction(-GS::moveSpeed, 0, true);
	if (left_move && !left_collision)
		moveFunction(GS::moveSpeed, 1, true);
	if (right_move && !right_collision)
		moveFunction(-GS::moveSpeed, 1, true);

	look.x = cos(yaw) * cos(pitch);
	look.y = sin(pitch);
	look.z = sin(yaw) * cos(pitch);

	strafe_lx = cos(yaw - (float)M_PI_2);
	strafe_lz = sin(yaw - (float)M_PI_2);

	Cdelta[0] = Vector3(GS::moveSpeed*cos(yaw) * cos(pitch), 0, GS::moveSpeed*sin(yaw) * cos(pitch));
	Cdelta[1] = Vector3(-GS::moveSpeed*cos(yaw) * cos(pitch), 0, -GS::moveSpeed*sin(yaw) * cos(pitch));
	Cdelta[2] = Vector3(GS::moveSpeed*strafe_lx, 0, GS::moveSpeed*strafe_lz);
	Cdelta[3] = Vector3(-GS::moveSpeed*strafe_lx, 0, -GS::moveSpeed*strafe_lz);

	look = Vector3(position.x + look.x, position.y + look.y, position.z + look.z);
}

void Character::moveFunction(float incrs, int type, bool savedelta) // type = 0 : FB, type = 1 : RL
{
/*	if (savedelta == true) // 0번 UP, 1번 DOWN, 2번 LEFT, 3번 RIGHT
	{
		if(front_move)
			Cdelta[0] = Vector2(incrs, type);
		if(back_move)
			Cdelta[1] = Vector2(incrs, type);
		if(left_move)
			Cdelta[2] = Vector2(incrs, type);
		if(right_move)
			Cdelta[3] = Vector2(incrs, type);
	}*/
	if (type == 0)
		moveCameraFB(incrs);
	else if (type == 1)
		moveCameraRL(incrs);
	else
		GS::debug.log("move error");
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

const Vector3 & Character::getCdelta(int num) const
{
	return Cdelta[num];
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

void Character::setFrontCollision(bool b)
{
	front_collision = b;
}

void Character::setBackCollision(bool b)
{
	back_collision = b;
}

void Character::setLeftCollision(bool b)
{
	left_collision = b;
}

void Character::setRightCollision(bool b)
{
	right_collision = b;
}

/*
bool Character::get_front_move()
{
	return front_move;
}

bool Character::get_back_move()
{
	return back_move;
}

bool Character::get_left_move()
{
	return left_move;
}

bool Character::get_right_move()
{
	return right_move;
}*/