#include "Box.h"
//#include <iostream>

//using namespace std;

void Box::set_box(const Vector3 center, const float X, const float Y, const float Z)
{
	//박스 세팅
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

Vector3 Box::n0123() // n4567 대칭
{
	return (p3 - p0).cross((p1 - p0)).normalize();
}

Vector3 Box::n0154() // n2376 대칭
{
	return (p4 - p0).cross((p0 - p1)).normalize();
}

Vector3 Box::n1265() // n3047 대칭
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

bool Box::collision_detection_2D(const Box B)
{
	//현재 박스에서 다음 박스에 대한 충돌 체크
	// 2D : 4개의 점(x, y)이 ax + by + c = 양수인지, 음수인지 4개의 직선 체크로 결정
	// 3D : 8개의 점(x, y, z)이 ax + by + cz + d = 양수인지, 음수인지 6개의 평면 체크로 결정

	return false;
}

bool Box::collision_detection_3D(Box iBox, Vector3 delta) // iBox의 각 꼭지점이 Box 내부에 있는 지 체크
{
	//현재 박스에서 다음 박스에 대한 충돌 체크
	// 2D : 4개의 점(x, y)이 ax + by + c = 양수인지, 음수인지 4개의 직선 체크로 결정
	// 3D : 8개의 점(x, y, z)이 ax + by + cz + d = 양수인지, 음수인지 6개의 평면 체크로 결정

	Box B = Box(iBox.get_cog() - delta, iBox.XLength(), iBox.YLength(), iBox.ZLength());

	if ((B.p0 - p0).dot(n0123()) >= 0 &&
		(B.p0 - p4).dot(n4567()) >= 0 &&
		(B.p0 - p0).dot(n0154()) >= 0 &&
		(B.p0 - p2).dot(n2376()) >= 0 &&
		(B.p0 - p1).dot(n1265()) >= 0 &&
		(B.p0 - p3).dot(n3047()) >= 0)
		return true;

	// 충돌 테스트
	/*		cout << (B.p2 - p0).dot(n0123()) << endl;
	cout << (B.p2 - p4).dot(n4567()) << endl;
	cout << (B.p2 - p0).dot(n0154()) << endl;
	cout << (B.p2 - p2).dot(n2376()) << endl;
	cout << (B.p2 - p1).dot(n1265()) << endl;
	cout << (B.p2 - p3).dot(n3047()) << endl;
	*/
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