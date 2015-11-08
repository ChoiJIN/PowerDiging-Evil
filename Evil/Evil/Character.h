#pragma once

#include "Matrices.h"

class Character
{
public:
	Character();
	~Character();

	const Vector3& getPosition() const;
	const Vector3& getLook() const;

private:
	Vector3 position;
	Vector3 look;
};

