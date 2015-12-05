#pragma once

#include "Matrices.h"
#include "Cinematic.h"
#include "Box.h"

class Character
{
public:
	Character();
	~Character();

	void RefreshCamera();
	void RefreshCinematic();

	void rotateCamera(double mouseX, double mouseY);
	void moveCameraFB(float incrs);
	void moveCameraRL(float incrs);
	void printState();
	void setState(unsigned char s);
	Box get_box();
	bool collision_check(Box B, Vector3 delta);

	unsigned char getLife();
	void setLife(unsigned char life);
	void showCameraPosition();
	float getposY();
	float getposX();
	float getposZ();

	void loadCinematic(string fileName);
	void alreadyWatched();
	bool getWatched();

	void playCinematic();
	int currentFrame = 0;

	const Vector3& getPosition() const;
	const Vector3& getLook() const;

	void setFrontMove(bool b);
	void setBackMove(bool b);
	void setLeftMove(bool b);
	void setRightMove(bool b);

private:
	Vector3 position;
	Vector3 look;
	Box Collision_Box;
	bool front_move = false;
	bool back_move = false;
	bool left_move = false;
	bool right_move = false;
	unsigned char state = 0, Life = 5;
	float lastX, lastY;
	float yaw, pitch;
	float strafe_lx, strafe_lz;

	Cinematic loader;
	bool watched = false;
};

