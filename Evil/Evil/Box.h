#pragma once

#include "Matrices.h"

class Box // �ϴ� ��ǥ�࿡ ������ Box
{
	// X����, Y����, Z����, �����߽�, �� ���� ��ǥ, �ٱ��� ���ϴ� ��� ����
	// 6���� �簢��
	// 0123, 0154, 1265, 2376, 3047, 4567 �� ����
public:
	Box() {};
	Box(const Vector3 center, const float X, const float Y, const float Z) // �����߽�, X����, Y����, Z����
	{
		//		XLength = X;
		//		YLength = Y;
		//		ZLength = Z;
		//	cog = center;
		p0 = Vector3(center.x + (X / 2), center.y + (Y / 2), center.z + (Z / 2));
		p1 = Vector3(center.x - (X / 2), center.y + (Y / 2), center.z + (Z / 2));
		p2 = Vector3(center.x - (X / 2), center.y - (Y / 2), center.z + (Z / 2));
		p3 = Vector3(center.x + (X / 2), center.y - (Y / 2), center.z + (Z / 2));
		p4 = Vector3(center.x + (X / 2), center.y + (Y / 2), center.z - (Z / 2));
		p5 = Vector3(center.x - (X / 2), center.y + (Y / 2), center.z - (Z / 2));
		p6 = Vector3(center.x - (X / 2), center.y - (Y / 2), center.z - (Z / 2));
		p7 = Vector3(center.x + (X / 2), center.y - (Y / 2), center.z - (Z / 2));
	}
	~Box() {};

	void set_box(const Vector3 center, const float X, const float Y, const float Z);
	void move_box(const Vector3 move);
	Vector3 get_cog(); // �߽��� ã��
					   // 6���� ��� ����
	Vector3 n0123(); // v03(3 - 0) cross v01(1 - 0)
	Vector3 n0154(); // v01(1 - 0) cross v04(4 - 0)
	Vector3 n1265(); // v12(2 - 1) cross v15(5 - 1)
	Vector3 n2376(); // v23(3 - 2) cross v26(6 - 2)
	Vector3 n3047(); // v30(0 - 3) cross v37(7 - 3)
	Vector3 n4567(); // v45(5 - 4) cross v47(7 - 4)
	float XLength(); // length(p1 - p0)
	float YLength(); // length(p2 - p1)
	float ZLength(); // length(p4 - p0)
	bool collision_detection_2D(const Box B); // 2D �浹 üũ
	bool collision_detection_3D(const Box iBox, Vector3 delta); // 3D �浹 üũ

private:
	// �ݽð� ����, �Ʒ��� : p0 p1 p2 p3(���� 1, 2, 3, 4 ��и�), �Ʒ���� �����ǰ� p4, p5, p6, p7(���� 1, 2, 3, 4 ��и�)
	Vector3 p0;
	Vector3 p1;
	Vector3 p2;
	Vector3 p3;
	Vector3 p4;
	Vector3 p5;
	Vector3 p6;
	Vector3 p7;
	//	Vector3 cog; // ������ �߽�
	//	float XLength = 0; // p0�� p1 ������ �Ÿ�
	//	float YLength = 0; // p0�� p3 ������ �Ÿ�
	//	float ZLength = 0; // p0�� p4 ������ �Ÿ�
};