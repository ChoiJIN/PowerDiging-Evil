#pragma once
#include <stack>
#include "Debug.h"
#include "Screen.h"

using namespace std;

class GameOption {
public:
	size_t screenLimit;
};

class GameSystem {
private:
	static bool gameEnd;
	static stack<Screen> screenStk;
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

	static void stepGameState(double deltaTime)
	{

	}

	static inline void changeScreen(Screen screen)
	{
		if (gameOption.screenLimit <= screenStk.size()) {
			debug.log("Too many screen");
		}
		else {
			screenStk.push(screen);
		}
	}

	static void exitScreen()
	{
		if (screenStk.size() != 0) {
			
		}
	}
};
