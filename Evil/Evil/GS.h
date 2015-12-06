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
	static bool isCinematicPlaying;

public:
	static GameOption option;
	static Debug debug;
	static Character* character;
	static float moveSpeed;

	static bool isGameEnd()
	{
		return gameEnd;
	}

	static void setGameEnd(bool val) // 게임 오버
	{
		GS::debug.log("Game Over");
		gameEnd = val;
	}

	// Cinematic을 실행할 조건이냐
	static bool inCinematic() 
	{
		return !character->getWatched() && isCinematicPlaying;
	}

	static void setCinematic(bool val) 
	{
		isCinematicPlaying = val;
	}
};
