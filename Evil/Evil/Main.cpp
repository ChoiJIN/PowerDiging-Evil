// Graphic Library
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Standard Library
#include <iostream>
#include <fstream>

// Game Library
#include "GLApp.h"
#include "GS.h"

#include "TestScreen.h"

int main(void)
{
	GLApp app;
	if (app.init() == APP_INIT_ERROR)
		return -1;

	TestScreen tes;
	GLApp::getInstance()->pushScreen(&tes);

	//	glMatrixMode(GL_PROJECTION);
	//	gluPerspective(45, 1, 0.1, 100.0);
	//	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 100.0);

	glMatrixMode(GL_MODELVIEW);

	app.mainLoop();

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

}