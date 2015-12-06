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
	}

	virtual ~Screen()
	{
	}

	virtual void update(double delta) = 0
	{
		character->RefreshCamera();

		currentTime = time(NULL);

		if (character->getLife() == 0)
			GS::setGameEnd(true);

	}

	virtual void render() = 0
	{
		//cout << "Screen.h�� render()" << endl;s
		//cout << "���⿡ ��� Screen���� ������ model, view ����� ȣ���ϸ� �ȴ�." << endl;

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		Matrix4 look = GLUtil::LookAt(character->getPosition(), character->getLook(), Vector3(0, 1, 0));
		Matrix4 perspective = GLUtil::perspective(90.f, 1, 0.01f, 100.0f);

		glLoadIdentity();
		glMultMatrixf(perspective.get());
		glMultMatrixf(look.get());

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
				if (character->collision_check(objs[i].get_box(), character->getCdelta(0)/character->getCdelta(0).length())
					|| objs[i].get_box().collision_detection_3D(character->get_box(), -character->getCdelta(0) / character->getCdelta(0).length()))
				{
					character->setFrontCollision(true);
				}
				if (character->collision_check(objs[i].get_box(), character->getCdelta(1) / character->getCdelta(1).length())
					|| objs[i].get_box().collision_detection_3D(character->get_box(), -character->getCdelta(1) / character->getCdelta(1).length()))
				{
					character->setBackCollision(true);
				}
				if (character->collision_check(objs[i].get_box(), character->getCdelta(2) / character->getCdelta(2).length())
					|| objs[i].get_box().collision_detection_3D(character->get_box(), -character->getCdelta(2) / character->getCdelta(2).length()))
				{
					character->setLeftCollision(true);
				}
				if (character->collision_check(objs[i].get_box(), character->getCdelta(3) / character->getCdelta(3).length())
					|| objs[i].get_box().collision_detection_3D(character->get_box(), -character->getCdelta(3) / character->getCdelta(3).length()))
				{
					character->setRightCollision(true);
				}
			}

			// ĳ���Ͱ� ���� ������Ʈ�� �浹�� ���
			if (character->collision_check(objs[i].get_box(), -objs[i].get_speed())
				|| objs[i].get_box().collision_detection_3D(character->get_box(), objs[i].get_speed())) // �浹 ������ �ϸ� true, �ƴϸ� false �̰ɷ� �� ���� ������ ����.
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

	inline void Object_Object_Collision_Detection()
	{
		for (size_t i = 0; i < objs.size(); i++)
			for (size_t j = 0; j < objs.size(); j++)
			{
				if (objs[i].getTracking() == true && i != j) // i�� ���𰡸� ������ ��
					if (objs[i].get_passable() == false && objs[j].get_passable() == false) // i�� j�� ��� ��� �Ұ����� ��ü�� ��
						if (objs[i].get_box().collision_detection_3D(objs[j].get_box(), objs[i].get_speed()) || objs[j].get_box().collision_detection_3D(objs[i].get_box(), -objs[i].get_speed()))
						{
//							                     cout << i << " ������Ʈ�� speed = " << objs[i].get_speed();
							objs[i].set_speed(Vector3(1.1*(cos(M_PI / 18)*objs[i].get_speed().x - sin(M_PI / 18)*objs[i].get_speed().z), objs[i].get_speed().y, 1.1*(sin(M_PI / 18)*objs[i].get_speed().x + cos(M_PI / 18)*objs[i].get_speed().z)));
//							                     cout << " -> " << objs[i].get_speed() << endl;
							objs[i].setCollision(true);
							//                  cout << i << " ������Ʈ�� " << j << "������Ʈ �浹 üũ" << endl;
						}
						else if (objs[i].get_box().collision_detection_3D(objs[j].get_box(), 0.05f*objs[i].getTracking()*(character->getPosition() - objs[i].get_box().get_cog()).normalize())
							|| objs[j].get_box().collision_detection_3D(objs[i].get_box(), -0.05f*objs[i].getTracking()*(character->getPosition() - objs[i].get_box().get_cog()).normalize()))
						{
							objs[i].setCollision(false);
						}
						else
						{
							objs[i].trackpos(character->getPosition());
							objs[i].setCollision(false);
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
		if (character->collision_check(objs[index].get_box(), -objs[index].get_speed())
			|| objs[index].get_box().collision_detection_3D(character->get_box(), objs[index].get_speed()))
		{
			objs[index].setTracking(false);
			//         objs[index].trackpos(character->getPosition());
		}
		//      else if(objs[index].getCollision() == true)
		//      {
		//         objs[index].setTracking(true);
		//      }
		else
		{
			objs[index].setTracking(true);
			//         objs[index].trackpos(character->getPosition());
		}

		//      cout << index << " ������Ʈ�� speed = " << objs[index].get_speed() << endl;
		//      cout << index << " ������Ʈ�� �ӷ� = " << objs[index].get_speed().length() << endl;
		cout << "Object " << index << "�� tracking = " << objs[index].getTracking() << endl;
		cout << "Object " << index << "�� collision = " << objs[index].getCollision() << endl;
	}

protected:

	Character* character;
	std::vector<Object> objs;
	Box roomBox;

private:
	time_t currentTime;
	time_t crashTime = 0;
};