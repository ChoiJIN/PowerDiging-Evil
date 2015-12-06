#pragma once
#include <stack>
#include <vector>
#include "Debug.h"
#include "Character.h"

using namespace std;

struct GameOption {
	size_t screenLimit;
	float roomSize;
	float characterHeight;
};

class GS {
private:
	static bool gameEnd;

public:
	static GameOption option;
	static Debug debug;
	static Character* character;
	static double moveSpeed;

	static bool isGameEnd()
	{
		return gameEnd;
	}

	static void setGameEnd(bool val) // ���� ����
	{
		GS::debug.log("Game Over");
		gameEnd = val;
	}
};
