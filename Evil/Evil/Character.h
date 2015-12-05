#pragma once

#include "Matrices.h"
#include "Box.h"

class Character
{
public:
	Character();
	~Character();

	void RefreshCamera();

	void rotateCamera(double mouseX, double mouseY);
	void moveFunction(float incrs, int type, bool savedelta);
	void moveCameraFB(float incrs);
	void moveCameraRL(float incrs);
	void printState();
	void setState(unsigned char s);
	Box get_box();
	bool collision_check(Box B, Vector3 delta);

	unsigned char getLife();
	void setLife(unsigned char life);
	const Vector3& getPosition() const;
	const Vector3& getLook() const;
	const Vector3& getCdelta(int num) const;
//	bool get_front_move();
//	bool get_back_move();
//	bool get_left_move();
//	bool get_right_move();

	void setFrontMove(bool b);
	void setBackMove(bool b);
	void setLeftMove(bool b);
	void setRightMove(bool b);

	void setFrontCollision(bool b);
	void setBackCollision(bool b);
	void setLeftCollision(bool b);
	void setRightCollision(bool b);

private:
	Vector3 position;
	Vector3 look;
	Box Collision_Box;
	bool front_move = false;
	bool back_move = false;
	bool left_move = false;
	bool right_move = false;

	bool front_collision = false;
	bool back_collision = false;
	bool left_collision = false;
	bool right_collision = false;

	unsigned char state = 0, Life = 50;
	float lastX, lastY;
	float yaw, pitch;
	float strafe_lx, strafe_lz;
	Vector3 Cdelta[4] = { Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f) };  // 0번 UP, 1번 DOWN, 2번 LEFT, 3번 RIGHT
	
};
