#include "GLApp.h"
#include "ImageLoader.h"
#include "TestScreen.h"

GLApp* GLApp::instance = NULL;

GLApp::GLApp()
{
	instance = this;
}


GLApp::~GLApp()
{
	//Close OpenGL window and terminate GLFW
	glfwDestroyWindow(window);
	//Finalize and clean up GLFW
	glfwTerminate();
	stack<Screen*>().swap(screenStk);
	exit(EXIT_SUCCESS);
}

GLApp * GLApp::getInstance()
{
	return instance;
}

int GLApp::init()
{
	//Set the error callback
	glfwSetErrorCallback(errorCallback);

	//Initialize GLFW
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);

	if (!window)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//This function makes the context of the specified window current on the calling thread. 
	glfwMakeContextCurrent(window);

	//Sets the swap interval(fps)
	glfwSwapInterval(1);

	//Sets the key callback
	glfwSetKeyCallback(window, keyCallback);
	glfwSetCursorPosCallback(window, cursorCallback);
	glfwSetMouseButtonCallback(window, buttonCallback);

	//Initialize GLEW
	GLenum err = glewInit();

	//If GLEW hasn't initialized
	if (err != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		return -1;
	}

	glSetting();

	return 0;
}

void GLApp::glSetting()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_TEXTURE_2D);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void GLApp::mainLoop()
{
	//Main Loop
	const double deltaTime = 1 / 30.0; // in seconds
	double timeAccumulator = 0;

	// while문 한 번이 한 프레임
	while (!GS::isGameEnd())
	{
		if (screenStk.empty()) {
			GS::debug.log("게임에는 하나 이상의 Screen이 존재해야 합니다.");
			return;
		}

		double timeSimulatedThisIteration = 0;
		double startTime = glfwGetTime();

		// 이전 프레임에서 현재 프레임까지 걸린 시간이
		// 미리 설정한 delta time이상 흘렀을때만 연산
		while ((timeAccumulator >= deltaTime) && GS::getPlay() == true)
		{
			screenStk.top()->update(deltaTime);
			timeAccumulator -= deltaTime;
			timeSimulatedThisIteration += deltaTime;
		}

		//stepAnimation(timeSimulatedThisIteration);

		screenStk.top()->render();

		glfwSwapBuffers(window);

		glfwPollEvents();

		if(GS::getPlay() == true)
		timeAccumulator += glfwGetTime() - startTime;

	}
}

void GLApp::pushScreen(Screen* screen)
{
	screenStk.push(screen);
}

void GLApp::popScreen()
{
	screenStk.pop();
}

void GLApp::errorCallback(int error, const char * description)
{
	fputs(description, stderr);
	_fgetchar();
}


void GLApp::keyCallback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		//glfwSetWindowShouldClose(window, GL_TRUE);
		GS::setGameEnd(true);
	// move
	if(GS::getKeyInterface() == 0)
		switch (key) {
		case GLFW_KEY_S:
		{
			if(action == GLFW_PRESS) GS::setPageUpDown(1);
			break;
		}
		}
	else if(GS::getKeyInterface() == 1)
		switch (key) {
		case GLFW_KEY_A:
			if (action == GLFW_PRESS) GS::character->setLeftMove(true);
			else if (action == GLFW_RELEASE) GS::character->setLeftMove(false);
			break;
		case GLFW_KEY_D:
			if (action == GLFW_PRESS) GS::character->setRightMove(true);
			else if (action == GLFW_RELEASE) GS::character->setRightMove(false);
			break;
		case GLFW_KEY_W:
			if (action == GLFW_PRESS) GS::character->setFrontMove(true);
			else if (action == GLFW_RELEASE) GS::character->setFrontMove(false);
			break;
		case GLFW_KEY_S:
			if (action == GLFW_PRESS) GS::character->setBackMove(true);
			else if (action == GLFW_RELEASE) GS::character->setBackMove(false);
			break;
		case GLFW_KEY_E:
			if (action == GLFW_PRESS) GS::character->interact(true);
			else if (action == GLFW_RELEASE) GS::character->interact(false);
			break;
		case GLFW_KEY_P:
			if (action == GLFW_PRESS) GS::setPlay(false);
			break;
		case GLFW_KEY_R:
			if (action == GLFW_PRESS) GS::setPlay(true);
			break;
		}
}

void GLApp::buttonCallback(GLFWwindow * window, int button, int action, int mode)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		GS::debug.log("pressed");
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
		GS::debug.log("released");
	}
}

void GLApp::cursorCallback(GLFWwindow * window, double x, double y)
{
	static bool just_warped = false;

	if (just_warped) {
		just_warped = false;
		return;
	}
	GS::character->rotateCamera(x, y);
	
	//GS::debug.log(to_string(x) + ", " + to_string(y));

	glfwSetCursorPos(window, 300, 300);
	just_warped = true;
}