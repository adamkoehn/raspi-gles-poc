#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Platform.h"
#include "Window.h"
#include "DemoShader.h"
#include "Triangle.h"
#include "WindowFactory.h"
#include "ShaderFactory.h"
#include "PrimitiveFactory.h"

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
}

int main(void)
{
	int ret = 1;
	GLFWwindow *glWindow;

	Platform *platform = new Platform();
	WindowFactory *windowFactory = new WindowFactory(platform);
	Window *window = windowFactory->createWindowForLaptop();
	
	if (window)
	{
		ShaderFactory *shaderFactory = new ShaderFactory();
		PrimitiveFactory *primitiveFactory = new PrimitiveFactory();
		DemoShader *shader = shaderFactory->makeDemoShader();
		Triangle *triangle = primitiveFactory->bufferTriangle();
		delete shaderFactory;
		delete primitiveFactory;

		glWindow = window->getWindow();

		while (!glfwWindowShouldClose(glWindow))
		{
			processInput(glWindow);
			glClear(GL_COLOR_BUFFER_BIT);
			shader->use();
			triangle->draw();
			glfwSwapBuffers(glWindow);
			glfwPollEvents();
		}

		delete shader;
		delete triangle;
		ret = 0;
	}

	delete window;
	delete windowFactory;
	delete platform;

	return ret;
}
