#pragma once

#include "Matrices.h"

class Character
{
public:
	Character();
	~Character();

	void RefreshCamera();

	void rotateCamera(double mouseX, double mouseY);
	void moveCameraFB(float incrs);
	void moveCameraRL(float incrs);


	const Vector3& getPosition() const;
	const Vector3& getLook() const;

private:
	Vector3 position;
	Vector3 look;
	float lastX, lastY;
	float posX, posY, posZ;
	float lookX, lookY, lookZ;
	float yaw, pitch;
	float strafe_lx, strafe_lz;
};

