#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"
#include <iostream>

#include "Slash.h"
#include "Circle.h"
#include "Rect.h"
#include "X.h"
#include "DownArrow.h"
#include "UpArrow.h"
#include "LeftArrow.h"
#include "RightArrow.h"
#include "DownLine.h"
#include "A.h"

using namespace std;

Geometric **my_objects = new Geometric*[10];

void drawOnPixelBuffer(double xpos, double ypos) {
	std::fill_n(pixels, width*height * 3, 1.0f);

	// 초기화
	my_objects[0] = new Slash(50, 50, 200, 200, xpos, ypos);
	my_objects[1] = new Circle(50, 300, 200, 450, xpos, ypos);
	my_objects[2] = new Rect(250, 50, 400, 200, xpos, ypos);
	my_objects[3] = new X(250, 300, 400, 450, xpos, ypos);
	my_objects[4] = new DownArrow(450, 50, 600, 200, xpos, ypos);
	my_objects[5] = new UpArrow(450, 300, 600, 450, xpos, ypos);
	my_objects[6] = new LeftArrow(650, 50, 800, 200, xpos, ypos);
	my_objects[7] = new RightArrow(650, 300, 800, 450, xpos, ypos);
	my_objects[8] = new DownLine(850, 50, 1000, 200, xpos, ypos);
	my_objects[9] = new A(850, 300, 1000, 450, xpos, ypos);

	// 그리기
	for (int i = 0; i < 10; i++) {
		my_objects[i]->draw();
	}

	
}

int main(void) {


	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

							  //»ï°¢Çü ÁÂÇ¥
	float vertices[] =
	{
		0.0, 0.5, 0.0, //top corner
		-0.5, -0.5, 0.0, //bottom left corner
		0.5, -0.5, 0.0 //bottom right corner
	};


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		double xpos, ypos;

		glfwGetCursorPos(window, &xpos, &ypos);


		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer(xpos, ypos);


		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
	
}