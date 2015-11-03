// Graphic Library
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Standard Library
#include <iostream>
#include <fstream>

// Game Library
#include "GameSystem.h"

//Define an error callback
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
	_fgetchar();
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

static void button_callback(GLFWwindow* window, int button, int action, int mode)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		std::cout << "pressed" << std::endl;
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
		std::cout << "released" << std::endl;
	}
}

static void cursor_callback(GLFWwindow* window, double x, double y)
{
	std::cout << x << ", " << y << std::endl;
}

int main(void)
{
	//Set the error callback
	glfwSetErrorCallback(error_callback);

	//Initialize GLFW
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	//Set the GLFW window creation hints - these are optional
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Request a specific OpenGL version
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //Request a specific OpenGL version
	//glfwWindowHint(GLFW_SAMPLES, 4); //Request 4x antialiasing
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Declare a window object
	GLFWwindow* window;

	//Create a window and create its OpenGL context
	window = glfwCreateWindow(600, 600, "Test Window", NULL, NULL);

	//If the window couldn't be created
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
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_callback);
	glfwSetMouseButtonCallback(window, button_callback);

	//Initialize GLEW
	GLenum err = glewInit();

	//If GLEW hasn't initialized
	if (err != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		return -1;
	}

	//Set a background color
	glClearColor(0.3f, 0.3f, 0.3f, 0.0f);

	//Main Loop
	double deltaTime = 1000 / 30.0;
	double timeAccumulator = 0;
	
	while (!GameSystem::isGameEnd())
	{
		double timeSimulatedThisIteration = 0;
		double startTime = glfwGetTime();

		while (timeAccumulator >= deltaTime)
		{
			GameSystem::stepGameState(deltaTime);
			timeAccumulator -= deltaTime;
			timeSimulatedThisIteration += deltaTime;
		}

		//stepAnimation(timeSimulatedThisIteration);

		// Draw
		//renderFrame();
		GameSystem::debug.log("merong");

		glfwPollEvents();

		timeAccumulator += glfwGetTime() - startTime;
	}

	//while (!glfwWindowShouldClose(window))
	//{
	//	float ratio;
	//	int width, height;
	//	glfwGetFramebufferSize(window, &width, &height);
	//	ratio = width / (float)height;
	//	glViewport(0, 0, width, height);

	//	glClear(GL_COLOR_BUFFER_BIT);

	//	double time = glfwGetTime();

	//	std::cout << time << std::endl;

	//	glBegin(GL_TRIANGLES);
	//	glVertex2d(0, 0);
	//	glVertex2d(0.5, 0.5);
	//	glVertex2d(0.5, 0);
	//	glEnd();

	//	//Swap buffers
	//	glfwSwapBuffers(window);
	//	//Get and organize events, like keyboard and mouse input, window resizing, etc...
	//	glfwPollEvents();
	//}

	//Close OpenGL window and terminate GLFW
	glfwDestroyWindow(window);
	//Finalize and clean up GLFW
	glfwTerminate();

	exit(EXIT_SUCCESS);
}