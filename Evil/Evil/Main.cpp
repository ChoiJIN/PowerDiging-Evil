// Graphic Library
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Standard Library
#include <iostream>
#include <fstream>
#include <map>

// assimp include files. These three are usually needed.

// Game Library
#include "GLApp.h"
#include "GS.h"
#include "ImageLoader.h"

#include "TestScreen.h"
#include "StartScreen.h"
using namespace std;

int main(void)
{
	GameOption option;
	option.roomSize = 20;
	option.characterHeight = 3;

	GS::option = option;
	GS::character = new Character();

	GLApp app;
	if (app.init() == APP_INIT_ERROR)
		return -1;


	StartScreen SS;
	GLApp::getInstance()->pushScreen(&SS);

//	ImageLoader::loadTexture("brick.jpg");
//	ImageLoader::loadTexture("brick_door.jpg");
//	ImageLoader::loadTexture("brick_bottom.jpg");
	ImageLoader::loadTexture("Evil_Title.jpg");

	glMatrixMode(GL_MODELVIEW);

	
	//freopen("cineFile_01.txt", "w", stdout);



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