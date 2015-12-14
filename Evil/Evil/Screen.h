#pragma once

//#include "GLApp.h"
#include <GLFW\glfw3.h>
#include <vector>
#include <ctime>

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
		if (GS::inCinematic()) {
			character->playCinematic();
			if (character->currentFrame > character->maxFrame - 1) {
				character->alreadyWatched();
				GS::setCinematic(false);
				character->currentFrame = 0;
			}
		}
		else {
			character->RefreshCamera();
		}

		currentTime = time(NULL);

		if (character->getLife() == 0)
			GS::setGameEnd(true);

		for (int i = 0; i < objs.size(); i++)
			objs[i].update(delta);
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

	unsigned char getInterfaceType()
	{
		return Interfacetype;
	}

	void Character_Objects_Collision_Detection() // ĳ���Ϳ� ������Ʈ�� �浹�ߴ� �� update ���� üũ�Ѵ�.
	{
		for (size_t i = 0; i < objs.size(); i++) // ��� ������Ʈ�� �˻�
		{
			// ���� �� ���� ������Ʈ�� ���
			if (objs[i].get_passable() == false)
			{
				// ĳ���Ͱ� Ű�� �Է¹޾� �̵��ϴ� 4���� ��쿡 ������Ʈ�� �浹�ϴ� �� ����, �浹�� ��쿡�� ĳ������ Collision ��� ������ "true"�� �ȴ�.
				if (objs[i].get_box().collision_detection_3D_mutal(character->get_box(), -character->getCdelta(0) / character->getCdelta(0).length()))
				{
					character->setFrontCollision(true);
				}
				if (objs[i].get_box().collision_detection_3D_mutal(character->get_box(), -character->getCdelta(1) / character->getCdelta(1).length()))
				{
					character->setBackCollision(true);
				}
				if (objs[i].get_box().collision_detection_3D_mutal(character->get_box(), -character->getCdelta(2) / character->getCdelta(2).length()))
				{
					character->setLeftCollision(true);
				}
				if (objs[i].get_box().collision_detection_3D_mutal(character->get_box(), -character->getCdelta(3) / character->getCdelta(3).length()))
				{
					character->setRightCollision(true);
				}
			}

			// ĳ���Ͱ� ���� ������Ʈ�� �浹�� ���
			if (objs[i].get_box().collision_detection_3D_mutal(GS::character->get_box(), objs[i].get_speed())) // �浹 ������ �ϸ� true, �ƴϸ� false �̰ɷ� �� ���� ������ ����.
			{
				if (objs[i].getTracking() == 1)
					objs[i].setTracking(2);

				// ������Ʈ�� get_type�� 1�� ���� 2�ʸ��� Life�� 1�� �𵵷� �Ѵ�.
				if (objs[i].get_type() == 1 && (currentTime - crashTime) > 2)
				{
					crashTime = currentTime;
					character->setLife(character->getLife() - 1);
					cout << "���� ������ = " << (int)character->getLife() << endl;
				}
				if (GS::character->checkInteract() && objs[i].get_type() == 2) {  // ���ͷ��ǰ� �ݸ����� �Ѵ� üũ.
					objs.erase(objs.begin() + i);
					character->setLife(character->getLife() + 1);
					break;
				}
			}
		}
	}

	void Object_Object_Collision_Detection()
	{
		for (size_t i = 0; i < objs.size(); i++)
		{
			for (size_t j = 0; j < objs.size(); j++)
			{
				if (objs[i].getTracking() == 1 && i != j) // i�� ���𰡸� ������ ��
					if (objs[i].get_passable() == false && objs[j].get_passable() == false) // i�� j�� ��� ��� �Ұ����� ��ü�� ��
						if (objs[i].get_box().collision_detection_3D_mutal(objs[j].get_box(), objs[i].get_speed()))
						{
							//							cout << i << " ������Ʈ�� speed = " << objs[i].get_speed();
							if((character->getPosition() - objs[i].getCog()).cross((objs[j].getCog() - objs[i].getCog())).y >= 0)
								objs[i].set_speed(Vector3(cos(M_PI / 18)*objs[i].get_speed().x - sin(M_PI / 18)*objs[i].get_speed().z, objs[i].get_speed().y, sin(M_PI / 18)*objs[i].get_speed().x + cos(M_PI / 18)*objs[i].get_speed().z));
							else
								objs[i].set_speed(Vector3(cos(-M_PI / 18)*objs[i].get_speed().x - sin(-M_PI / 18)*objs[i].get_speed().z, objs[i].get_speed().y, sin(-M_PI / 18)*objs[i].get_speed().x + cos(-M_PI / 18)*objs[i].get_speed().z));
							//							cout << " -> " << objs[i].get_speed() << endl;
							objs[i].setCollision(true);
							//						cout << i << " ������Ʈ�� " << j << "������Ʈ �浹 üũ" << endl;
						}
						else if (objs[i].get_box().collision_detection_3D_mutal(objs[j].get_box(), 0.1f*(objs[i].get_trackposition() - objs[i].get_box().get_cog()).normalize()))
						{
							objs[i].setCollision(false);
						}
						else
						{
							objs[i].setTarget(character->getPosition());
							objs[i].setCollision(false);
						}
			}
		}
	}

	void Character_Room_Collision_Detection() // ĳ���Ͱ� �� ������ ������ �ϴ� ���
	{
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

protected:

	Character* character;
	std::vector<Object> uiComponent;
	std::vector<Object> objs;
	Box roomBox;
	Object hpBar;
	Matrix4 modelview, perspective;
	unsigned char Interfacetype = 0; // 0�� : SŰ�� ������ ����, 1�� : ����� �������̽�

private:
	time_t currentTime;
	time_t crashTime = 0;
	int hpVal = 1;
};