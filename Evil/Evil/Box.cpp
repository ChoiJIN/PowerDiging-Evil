#include "Box.h"
//#include <iostream>

//using namespace std;

void Box::set_box(const Vector3 center, const float X, const float Y, const float Z)
{
	//�ڽ� ����
	//	XLength = X;
	//	YLength = Y;
	//	ZLength = Z;
	//	cog = center;
	p0 = Vector3(center.x + (X / 2), center.y + (Y / 2), center.z - (Z / 2));
	p1 = Vector3(center.x - (X / 2), center.y + (Y / 2), center.z - (Z / 2));
	p2 = Vector3(center.x - (X / 2), center.y - (Y / 2), center.z - (Z / 2));
	p3 = Vector3(center.x + (X / 2), center.y - (Y / 2), center.z - (Z / 2));
	p4 = Vector3(center.x + (X / 2), center.y + (Y / 2), center.z + (Z / 2));
	p5 = Vector3(center.x - (X / 2), center.y + (Y / 2), center.z + (Z / 2));
	p6 = Vector3(center.x - (X / 2), center.y - (Y / 2), center.z + (Z / 2));
	p7 = Vector3(center.x + (X / 2), center.y - (Y / 2), center.z + (Z / 2));
}

void Box::move_box(const Vector3 move)
{
	p0 += move;
	p1 += move;
	p2 += move;
	p3 += move;
	p4 += move;
	p5 += move;
	p6 += move;
	p7 += move;
}

Vector3 Box::get_cog()
{
	Vector3 center = (p0 + p1 + p2 + p3 + p4 + p5 + p6 + p7) / 8;
	return center;
}

Vector3 Box::n0123() // n4567 ��Ī
{
	return (p3 - p0).cross((p1 - p0)).normalize();
}

Vector3 Box::n0154() // n2376 ��Ī
{
	return (p4 - p0).cross((p0 - p1)).normalize();
}

Vector3 Box::n1265() // n3047 ��Ī
{
	return (p5 - p1).cross((p1 - p2)).normalize();
}

Vector3 Box::n2376()
{
	return (p6 - p2).cross((p2 - p3)).normalize();
}

Vector3 Box::n3047()
{
	return (p7 - p3).cross((p3 - p0)).normalize();
}

Vector3 Box::n4567()
{
	return (p5 - p4).cross((p7 - p4)).normalize();
}

float Box::XLength()
{
	return (p1 - p0).length();
}

float Box::YLength()
{
	return (p2 - p1).length();
}

float Box::ZLength()
{
	return (p4 - p0).length();
}

bool Box::collision_detection_in(Box iBox, Vector3 delta) // iBox�� �������� �� iBox�� ������ Box�� �ȿ� �ִ� �� ����
{
	//���� �ڽ����� ���� �ڽ��� ���� �浹 üũ
	// 2D : 4���� ��(x, y)�� ax + by + c = �������, �������� 4���� ���� üũ�� ����
	// 3D : 8���� ��(x, y, z)�� ax + by + cz + d = �������, �������� 6���� ��� üũ�� ����

	Box B = Box(iBox.get_cog() + delta, iBox.XLength(), iBox.YLength(), iBox.ZLength());

	if ((B.p0 - p0).dot(n0123()) >= 0 &&
		(B.p0 - p4).dot(n4567()) >= 0 &&
		(B.p0 - p0).dot(n0154()) >= 0 &&
		(B.p0 - p2).dot(n2376()) >= 0 &&
		(B.p0 - p1).dot(n1265()) >= 0 &&
		(B.p0 - p3).dot(n3047()) >= 0)
		if ((B.p1 - p0).dot(n0123()) >= 0 &&
			(B.p1 - p4).dot(n4567()) >= 0 &&
			(B.p1 - p0).dot(n0154()) >= 0 &&
			(B.p1 - p2).dot(n2376()) >= 0 &&
			(B.p1 - p1).dot(n1265()) >= 0 &&
			(B.p1 - p3).dot(n3047()) >= 0)
			if ((B.p2 - p0).dot(n0123()) >= 0 &&
				(B.p2 - p4).dot(n4567()) >= 0 &&
				(B.p2 - p0).dot(n0154()) >= 0 &&
				(B.p2 - p2).dot(n2376()) >= 0 &&
				(B.p2 - p1).dot(n1265()) >= 0 &&
				(B.p2 - p3).dot(n3047()) >= 0)
				if ((B.p3 - p0).dot(n0123()) >= 0 &&
					(B.p3 - p4).dot(n4567()) >= 0 &&
					(B.p3 - p0).dot(n0154()) >= 0 &&
					(B.p3 - p2).dot(n2376()) >= 0 &&
					(B.p3 - p1).dot(n1265()) >= 0 &&
					(B.p3 - p3).dot(n3047()) >= 0)
					if ((B.p4 - p0).dot(n0123()) >= 0 &&
						(B.p4 - p4).dot(n4567()) >= 0 &&
						(B.p4 - p0).dot(n0154()) >= 0 &&
						(B.p4 - p2).dot(n2376()) >= 0 &&
						(B.p4 - p1).dot(n1265()) >= 0 &&
						(B.p4 - p3).dot(n3047()) >= 0)
						if ((B.p5 - p0).dot(n0123()) >= 0 &&
							(B.p5 - p4).dot(n4567()) >= 0 &&
							(B.p5 - p0).dot(n0154()) >= 0 &&
							(B.p5 - p2).dot(n2376()) >= 0 &&
							(B.p5 - p1).dot(n1265()) >= 0 &&
							(B.p5 - p3).dot(n3047()) >= 0)
							if ((B.p6 - p0).dot(n0123()) >= 0 &&
								(B.p6 - p4).dot(n4567()) >= 0 &&
								(B.p6 - p0).dot(n0154()) >= 0 &&
								(B.p6 - p2).dot(n2376()) >= 0 &&
								(B.p6 - p1).dot(n1265()) >= 0 &&
								(B.p6 - p3).dot(n3047()) >= 0)
								if ((B.p7 - p0).dot(n0123()) >= 0 &&
									(B.p7 - p4).dot(n4567()) >= 0 &&
									(B.p7 - p0).dot(n0154()) >= 0 &&
									(B.p7 - p2).dot(n2376()) >= 0 &&
									(B.p7 - p1).dot(n1265()) >= 0 &&
									(B.p7 - p3).dot(n3047()) >= 0)
									return true;

	// �浹 �׽�Ʈ
	/*		cout << (B.p2 - p0).dot(n0123()) << endl;
	cout << (B.p2 - p4).dot(n4567()) << endl;
	cout << (B.p2 - p0).dot(n0154()) << endl;
	cout << (B.p2 - p2).dot(n2376()) << endl;
	cout << (B.p2 - p1).dot(n1265()) << endl;
	cout << (B.p2 - p3).dot(n3047()) << endl;
	*/

	return false;
}

bool Box::collision_detection_3D(Box iBox, Vector3 delta) // iBox�� �� �������� Box ���ο� �ִ� �� üũ
{
	//���� �ڽ����� ���� �ڽ��� ���� �浹 üũ
	// 2D : 4���� ��(x, y)�� ax + by + c = �������, �������� 4���� ���� üũ�� ����
	// 3D : 8���� ��(x, y, z)�� ax + by + cz + d = �������, �������� 6���� ��� üũ�� ����

	Box B = Box(iBox.get_cog() - delta, iBox.XLength(), iBox.YLength(), iBox.ZLength());

	if ((B.p0 - p0).dot(n0123()) >= 0 &&
		(B.p0 - p4).dot(n4567()) >= 0 &&
		(B.p0 - p0).dot(n0154()) >= 0 &&
		(B.p0 - p2).dot(n2376()) >= 0 &&
		(B.p0 - p1).dot(n1265()) >= 0 &&
		(B.p0 - p3).dot(n3047()) >= 0)
		return true;

	if ((B.p1 - p0).dot(n0123()) >= 0 &&
		(B.p1 - p4).dot(n4567()) >= 0 &&
		(B.p1 - p0).dot(n0154()) >= 0 &&
		(B.p1 - p2).dot(n2376()) >= 0 &&
		(B.p1 - p1).dot(n1265()) >= 0 &&
		(B.p1 - p3).dot(n3047()) >= 0)
		return true;

	if ((B.p2 - p0).dot(n0123()) >= 0 &&
		(B.p2 - p4).dot(n4567()) >= 0 &&
		(B.p2 - p0).dot(n0154()) >= 0 &&
		(B.p2 - p2).dot(n2376()) >= 0 &&
		(B.p2 - p1).dot(n1265()) >= 0 &&
		(B.p2 - p3).dot(n3047()) >= 0)
		return true;

	if ((B.p3 - p0).dot(n0123()) >= 0 &&
		(B.p3 - p4).dot(n4567()) >= 0 &&
		(B.p3 - p0).dot(n0154()) >= 0 &&
		(B.p3 - p2).dot(n2376()) >= 0 &&
		(B.p3 - p1).dot(n1265()) >= 0 &&
		(B.p3 - p3).dot(n3047()) >= 0)
		return true;

	if ((B.p4 - p0).dot(n0123()) >= 0 &&
		(B.p4 - p4).dot(n4567()) >= 0 &&
		(B.p4 - p0).dot(n0154()) >= 0 &&
		(B.p4 - p2).dot(n2376()) >= 0 &&
		(B.p4 - p1).dot(n1265()) >= 0 &&
		(B.p4 - p3).dot(n3047()) >= 0)
		return true;

	if ((B.p5 - p0).dot(n0123()) >= 0 &&
		(B.p5 - p4).dot(n4567()) >= 0 &&
		(B.p5 - p0).dot(n0154()) >= 0 &&
		(B.p5 - p2).dot(n2376()) >= 0 &&
		(B.p5 - p1).dot(n1265()) >= 0 &&
		(B.p5 - p3).dot(n3047()) >= 0)
		return true;

	if ((B.p6 - p0).dot(n0123()) >= 0 &&
		(B.p6 - p4).dot(n4567()) >= 0 &&
		(B.p6 - p0).dot(n0154()) >= 0 &&
		(B.p6 - p2).dot(n2376()) >= 0 &&
		(B.p6 - p1).dot(n1265()) >= 0 &&
		(B.p6 - p3).dot(n3047()) >= 0)
		return true;

	if ((B.p7 - p0).dot(n0123()) >= 0 &&
		(B.p7 - p4).dot(n4567()) >= 0 &&
		(B.p7 - p0).dot(n0154()) >= 0 &&
		(B.p7 - p2).dot(n2376()) >= 0 &&
		(B.p7 - p1).dot(n1265()) >= 0 &&
		(B.p7 - p3).dot(n3047()) >= 0)
		return true;

	return false;
}

bool Box::collision_detection_3D_mutal(Box iBox, Vector3 delta)
{
	Box B = Box(iBox.get_cog() - delta, iBox.XLength(), iBox.YLength(), iBox.ZLength());

	Vector3 n0123_o = n0123();
	Vector3 n4567_o = n4567();
	Vector3 n0154_o = n0154();
	Vector3 n2376_o = n2376();
	Vector3 n1265_o = n1265();
	Vector3 n3047_o = n3047();

	if ((B.p0 - p0).dot(n0123_o) >= 0 &&
		(B.p0 - p4).dot(n4567_o) >= 0 &&
		(B.p0 - p0).dot(n0154_o) >= 0 &&
		(B.p0 - p2).dot(n2376_o) >= 0 &&
		(B.p0 - p1).dot(n1265_o) >= 0 &&
		(B.p0 - p3).dot(n3047_o) >= 0)
		return true;

	if ((B.p1 - p0).dot(n0123_o) >= 0 &&
		(B.p1 - p4).dot(n4567_o) >= 0 &&
		(B.p1 - p0).dot(n0154_o) >= 0 &&
		(B.p1 - p2).dot(n2376_o) >= 0 &&
		(B.p1 - p1).dot(n1265_o) >= 0 &&
		(B.p1 - p3).dot(n3047_o) >= 0)
		return true;

	if ((B.p2 - p0).dot(n0123_o) >= 0 &&
		(B.p2 - p4).dot(n4567_o) >= 0 &&
		(B.p2 - p0).dot(n0154_o) >= 0 &&
		(B.p2 - p2).dot(n2376_o) >= 0 &&
		(B.p2 - p1).dot(n1265_o) >= 0 &&
		(B.p2 - p3).dot(n3047_o) >= 0)
		return true;

	if ((B.p3 - p0).dot(n0123_o) >= 0 &&
		(B.p3 - p4).dot(n4567_o) >= 0 &&
		(B.p3 - p0).dot(n0154_o) >= 0 &&
		(B.p3 - p2).dot(n2376_o) >= 0 &&
		(B.p3 - p1).dot(n1265_o) >= 0 &&
		(B.p3 - p3).dot(n3047_o) >= 0)
		return true;

	if ((B.p4 - p0).dot(n0123_o) >= 0 &&
		(B.p4 - p4).dot(n4567_o) >= 0 &&
		(B.p4 - p0).dot(n0154_o) >= 0 &&
		(B.p4 - p2).dot(n2376_o) >= 0 &&
		(B.p4 - p1).dot(n1265_o) >= 0 &&
		(B.p4 - p3).dot(n3047_o) >= 0)
		return true;

	if ((B.p5 - p0).dot(n0123_o) >= 0 &&
		(B.p5 - p4).dot(n4567_o) >= 0 &&
		(B.p5 - p0).dot(n0154_o) >= 0 &&
		(B.p5 - p2).dot(n2376_o) >= 0 &&
		(B.p5 - p1).dot(n1265_o) >= 0 &&
		(B.p5 - p3).dot(n3047_o) >= 0)
		return true;

	if ((B.p6 - p0).dot(n0123_o) >= 0 &&
		(B.p6 - p4).dot(n4567_o) >= 0 &&
		(B.p6 - p0).dot(n0154_o) >= 0 &&
		(B.p6 - p2).dot(n2376_o) >= 0 &&
		(B.p6 - p1).dot(n1265_o) >= 0 &&
		(B.p6 - p3).dot(n3047_o) >= 0)
		return true;

	if ((B.p7 - p0).dot(n0123_o) >= 0 &&
		(B.p7 - p4).dot(n4567_o) >= 0 &&
		(B.p7 - p0).dot(n0154_o) >= 0 &&
		(B.p7 - p2).dot(n2376_o) >= 0 &&
		(B.p7 - p1).dot(n1265_o) >= 0 &&
		(B.p7 - p3).dot(n3047_o) >= 0)
		return true;

	Vector3 n0123_B = B.n0123();
	Vector3 n4567_B = B.n4567();
	Vector3 n0154_B = B.n0154();
	Vector3 n2376_B = B.n2376();
	Vector3 n1265_B = B.n1265();
	Vector3 n3047_B = B.n3047();

	if ((p0 - B.p0).dot(n0123_B) >= 0 &&
		(p0 - B.p4).dot(n4567_B) >= 0 &&
		(p0 - B.p0).dot(n0154_B) >= 0 &&
		(p0 - B.p2).dot(n2376_B) >= 0 &&
		(p0 - B.p1).dot(n1265_B) >= 0 &&
		(p0 - B.p3).dot(n3047_B) >= 0)
		return true;

	if ((p1 - B.p0).dot(n0123_B) >= 0 &&
		(p1 - B.p4).dot(n4567_B) >= 0 &&
		(p1 - B.p0).dot(n0154_B) >= 0 &&
		(p1 - B.p2).dot(n2376_B) >= 0 &&
		(p1 - B.p1).dot(n1265_B) >= 0 &&
		(p1 - B.p3).dot(n3047_B) >= 0)
		return true;

	if ((p2 - B.p0).dot(n0123_B) >= 0 &&
		(p2 - B.p4).dot(n4567_B) >= 0 &&
		(p2 - B.p0).dot(n0154_B) >= 0 &&
		(p2 - B.p2).dot(n2376_B) >= 0 &&
		(p2 - B.p1).dot(n1265_B) >= 0 &&
		(p2 - B.p3).dot(n3047_B) >= 0)
		return true;

	if ((p3 - B.p0).dot(n0123_B) >= 0 &&
		(p3 - B.p4).dot(n4567_B) >= 0 &&
		(p3 - B.p0).dot(n0154_B) >= 0 &&
		(p3 - B.p2).dot(n2376_B) >= 0 &&
		(p3 - B.p1).dot(n1265_B) >= 0 &&
		(p3 - B.p3).dot(n3047_B) >= 0)
		return true;

	if ((p4 - B.p0).dot(n0123_B) >= 0 &&
		(p4 - B.p4).dot(n4567_B) >= 0 &&
		(p4 - B.p0).dot(n0154_B) >= 0 &&
		(p4 - B.p2).dot(n2376_B) >= 0 &&
		(p4 - B.p1).dot(n1265_B) >= 0 &&
		(p4 - B.p3).dot(n3047_B) >= 0)
		return true;

	if ((p5 - B.p0).dot(n0123_B) >= 0 &&
		(p5 - B.p4).dot(n4567_B) >= 0 &&
		(p5 - B.p0).dot(n0154_B) >= 0 &&
		(p5 - B.p2).dot(n2376_B) >= 0 &&
		(p5 - B.p1).dot(n1265_B) >= 0 &&
		(p5 - B.p3).dot(n3047_B) >= 0)
		return true;

	if ((p6 - B.p0).dot(n0123_B) >= 0 &&
		(p6 - B.p4).dot(n4567_B) >= 0 &&
		(p6 - B.p0).dot(n0154_B) >= 0 &&
		(p6 - B.p2).dot(n2376_B) >= 0 &&
		(p6 - B.p1).dot(n1265_B) >= 0 &&
		(p6 - B.p3).dot(n3047_B) >= 0)
		return true;

	if ((p7 - B.p0).dot(n0123_B) >= 0 &&
		(p7 - B.p4).dot(n4567_B) >= 0 &&
		(p7 - B.p0).dot(n0154_B) >= 0 &&
		(p7 - B.p2).dot(n2376_B) >= 0 &&
		(p7 - B.p1).dot(n1265_B) >= 0 &&
		(p7 - B.p3).dot(n3047_B) >= 0)
		return true;

	return false;
}