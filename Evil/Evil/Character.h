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
	void moveCameraFB(float incrs);
	void moveCameraRL(float incrs);
	void printState();
	void setState(unsigned char s);
	Box get_box();
	bool collision_check(Box B, Vector3 delta);


	const Vector3& getPosition() const;
	const Vector3& getLook() const;

private:
	Vector3 position;
	Vector3 look;
	Box Collision_Box;
	bool front_move, back_move, left_move, right_move = true;
	unsigned char state = 0, Life = 5;
	float lastX, lastY;
	float yaw, pitch;
	float strafe_lx, strafe_lz;
};

