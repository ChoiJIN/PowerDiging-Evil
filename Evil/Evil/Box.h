#pragma once

#include "Matrices.h"

class Box // 일단 좌표축에 평행한 Box
{
	// X길이, Y길이, Z길이, 무게중심, 각 점의 좌표, 바깥을 향하는 노멀 벡터
	// 6개의 사각형
	// 0123, 0154, 1265, 2376, 3047, 4567 로 구성
public:
	Box() {};
	Box(const Vector3 center, const float X, const float Y, const float Z) // 무게중심, X길이, Y길이, Z길이
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
	Vector3 get_cog(); // 중심점 찾기
					   // 6개의 노멀 벡터
	Vector3 n0123(); // v03(3 - 0) cross v01(1 - 0)
	Vector3 n0154(); // v01(1 - 0) cross v04(4 - 0)
	Vector3 n1265(); // v12(2 - 1) cross v15(5 - 1)
	Vector3 n2376(); // v23(3 - 2) cross v26(6 - 2)
	Vector3 n3047(); // v30(0 - 3) cross v37(7 - 3)
	Vector3 n4567(); // v45(5 - 4) cross v47(7 - 4)
	float XLength(); // length(p1 - p0)
	float YLength(); // length(p2 - p1)
	float ZLength(); // length(p4 - p0)
	bool collision_detection_in(Box iBox, Vector3 delta); // 2D 충돌 체크
	bool collision_detection_3D(Box iBox, Vector3 delta); // 3D 충돌 체크
	bool collision_detection_3D_mutal(Box iBox, Vector3 delta); // 3D 상호충돌 체크

private:
	// 반시계 방향, 아랫면 : p0 p1 p2 p3(각각 1, 2, 3, 4 사분면), 아랫면과 대응되게 p4, p5, p6, p7(각각 1, 2, 3, 4 사분면)
	Vector3 p0;
	Vector3 p1;
	Vector3 p2;
	Vector3 p3;
	Vector3 p4;
	Vector3 p5;
	Vector3 p6;
	Vector3 p7;
	//	Vector3 cog; // 상자의 중심
	//	float XLength = 0; // p0과 p1 사이의 거리
	//	float YLength = 0; // p0과 p3 사이의 거리
	//	float ZLength = 0; // p0과 p4 사이의 거리
};