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
	static bool play;
	static unsigned char KeyInterface;
	static unsigned char PageUpDown; // 0일 때 현상유지, 1일 때 push, 2일 때 pop
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
		return isCinematicPlaying;
	}

	static void setPlay(bool p)
	{
		play = p;
	}

	static unsigned char getKeyInterface()
	{
		return KeyInterface;
	}

	static void setKeyInterface(unsigned char I)
	{
		KeyInterface = I;
	}

	static unsigned char getPageUpDown()
	{
		return PageUpDown;
	}

	static void setPageUpDown(unsigned char n)
	{
		PageUpDown = n;
	}

	static bool getPlay()
	{
		return play;
	}

	static void setCinematic(bool val) 
	{
		isCinematicPlaying = val;
	}
};
