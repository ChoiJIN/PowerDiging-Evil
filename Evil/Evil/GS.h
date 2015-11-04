#pragma once
#include <stack>
#include "Debug.h"

using namespace std;

class GameOption {
public:
	size_t screenLimit;
};

class GS {
private:
	static bool gameEnd;
	static GameOption gameOption;

public:
	static Debug debug;

	static void loadGameOption();

	static bool isGameEnd()
	{
		return gameEnd;
	}

	static void setGameEnd(bool val)
	{
		gameEnd = val;
	}
};
