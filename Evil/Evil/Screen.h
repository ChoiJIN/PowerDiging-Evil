#pragma once

//#include "GLApp.h"
#include <GLFW\glfw3.h>
#include <vector>
#include <ctime>

#include "Cinematic.h"
#include "Character.h"
#include "Object.h"
#include "Matrices.h"
#include "GLUtil.h"


using namespace std;

class Screen
{
public:
	Screen()
	{
		character = GS::character;
		uiComponent.push_back(hpBar);
		uiComponent[0] = Object(Vector3(0, 8, 0));
		uiComponent[0].loadObj("hp" + to_string(character->getLife()));
	}

	virtual ~Screen()
	{
	}

	virtual void update(double delta) = 0
	{
		
		currentTime = time(NULL);

		if (character->getLife() == 0)
			GS::setGameEnd(true);
	}

	virtual void render() = 0
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// UI
		glMatrixMode(GL_PROJECTION);
		perspective = GLUtil::Ortho(-10, 10, -10, 10, 0.01, 100);
		glLoadMatrixf(perspective.get());
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		if (hpVal != character->getLife()) {
			uiComponent[0] = Object(Vector3(0, 8, 0));
			uiComponent[0].loadObj("hp" + to_string(character->getLife()));
			hpVal = character->getLife();
		}

		uiComponent[0].draw();

		glMatrixMode(GL_PROJECTION);
		perspective = GLUtil::perspective(90.f, 1, 0.01f, 100.0f);
		glLoadMatrixf(perspective.get());

		glMatrixMode(GL_MODELVIEW);
		modelview = GLUtil::LookAt(character->getPosition(), character->getLook(), Vector3(0, 1, 0));

		glLoadIdentity();
		glMultMatrixf(modelview.get());

		for (size_t i = 0; i < objs.size(); i++)
			objs[i].draw();

	}

	GLuint getTextureId(string name)
	{

	}

	void getDamaged()
	{

	}

	inline void Character_Objects_Collision_Detection() // ĳ���Ϳ� ������Ʈ�� �浹�ߴ� �� update ���� üũ�Ѵ�.
	{
		for (size_t i = 0; i < objs.size(); i++) // ��� ������Ʈ�� �˻�
		{
			// ���� �� ���� ������Ʈ�� ���
			if (objs[i].get_passable() == false)
			{
				// ĳ���Ͱ� Ű�� �Է¹޾� �̵��ϴ� 4���� ��쿡 ������Ʈ�� �浹�ϴ� �� ����, �浹�� ��쿡�� ĳ������ Collision ��� ������ "true"�� �ȴ�.
				if (character->collision_check(objs[i].get_box(), character->getCdelta(0))
					|| objs[i].get_box().collision_detection_3D(character->get_box(), -character->getCdelta(0)))
				{
					character->setFrontCollision(true);
				}
				if (character->collision_check(objs[i].get_box(), character->getCdelta(1))
					|| objs[i].get_box().collision_detection_3D(character->get_box(), -character->getCdelta(1)))
				{
					character->setBackCollision(true);
				}
				if (character->collision_check(objs[i].get_box(), character->getCdelta(2))
					|| objs[i].get_box().collision_detection_3D(character->get_box(), -character->getCdelta(2)))
				{
					character->setLeftCollision(true);
				}
				if (character->collision_check(objs[i].get_box(), character->getCdelta(3))
					|| objs[i].get_box().collision_detection_3D(character->get_box(), -character->getCdelta(3)))
				{
					character->setRightCollision(true);
				}
			}

			// ĳ���Ͱ� ���� ������Ʈ�� �浹�� ���
			if (character->collision_check(objs[i].get_box(), Vector3(0.f, 0.f, 0.f))
				|| objs[i].get_box().collision_detection_3D(character->get_box(), Vector3(0.f, 0.f, 0.f))) // �浹 ������ �ϸ� true, �ƴϸ� false �̰ɷ� �� ���� ������ ����.
			{
				// ������Ʈ�� get_type�� 1�� ���� 2�ʸ��� Life�� 1�� �𵵷� �Ѵ�.
				if (objs[i].get_type() == 1 && (currentTime - crashTime) > 2)
				{
					crashTime = currentTime;
					character->setLife(character->getLife() - 1);
					cout << "���� ������ = " << (int)character->getLife() << endl;
				}
			}
		}
	}

	inline void Character_Room_Collision_Detection() // ĳ���Ͱ� �� ������ ������ �ϴ� ���
	{
		// ĳ���Ͱ� Ű�� �Է¹޾� �̵��ϴ� 4���� ��쿡 ���� �մ� �� ����, �浹�� ��쿡�� ĳ������ Collision ��� ������ "true"�� �ȴ�.
		if (!roomBox.collision_detection_in(character->get_box(), character->getCdelta(0)))
		{
			character->setFrontCollision(true);
		}
		else
			character->setFrontCollision(false);

		if (!roomBox.collision_detection_in(character->get_box(), character->getCdelta(1)))
		{
			character->setBackCollision(true);
		}
		else
			character->setBackCollision(false);

		if (!roomBox.collision_detection_in(character->get_box(), character->getCdelta(2)))
		{
			character->setLeftCollision(true);
		}
		else
			character->setLeftCollision(false);

		if (!roomBox.collision_detection_in(character->get_box(), character->getCdelta(3)))
		{
			character->setRightCollision(true);
		}
		else
			character->setRightCollision(false);
	}

	void Object_Tracking_Character(int index) // index ��° ������Ʈ�� ĳ���͸� �����ϵ��� �ϴ� �Լ�
	{
		// ������Ʈ�� ĳ������ ��ġ�� üũ�Ѵ�. �׸��� �� ��ġ�� �����Ѵ�. ������ ��, ������Ʈ�� ĳ������ ��ġ�� �ٽ� üũ�ϰ� �����Ѵ�.
		// ������Ʈ�� ĳ���Ϳ� �浹�� ���, �� �̻� �������� �ʴ´�.
		if (character->collision_check(objs[index].get_box(), Vector3(0, 0, 0))
			|| objs[index].get_box().collision_detection_3D(character->get_box(), Vector3(0, 0, 0)))
		{
			objs[index].setTracking(false);
		}
		else
		{
			objs[index].setTracking(true);
			objs[index].trackpos(character->getPosition());
		}
	}

protected:
	Character* character;
	std::vector<Object> uiComponent;
	std::vector<Object> objs;
	Box roomBox;
	Object hpBar;
	Matrix4 modelview, perspective;

private:
	time_t currentTime;
	time_t crashTime = 0;
	int hpVal = 10;
};