#include "Character.h"
#include "Vectors.h"
#include "GS.h"

Character::Character()
{
	look = Vector3(0, 0, -1);
}


Character::~Character()
{
}

const Vector3& Character::getPosition() const
{
	return position;
}

const Vector3 & Character::getLook() const
{
	return look;
}