#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GS.h"
#include "Screen.h"

using namespace std;

#define APP_INIT_ERROR -1

class GLApp
{
public:
	GLApp();
	~GLApp();

	static GLApp* getInstance();

	int init();
	void mainLoop();

	/* Screen */
	void pushScreen(Screen* screen);
	void popScreen(Screen* screen);

	/* GLFW Callbacks */
	static void errorCallback(int error, const char* description);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void buttonCallback(GLFWwindow* window, int button, int action, int mode);
	static void cursorCallback(GLFWwindow* window, double x, double y);

private:
	static GLApp* instance;
	GLFWwindow* window;
	stack<Screen*> screenStk;

};

