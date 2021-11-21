#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Platform.h"
#include "Window.h"
#include "DemoShader.h"
#include "Camera.h"
#include "Cube.h"
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
	float lastTime;
	float deltaTime;
	float currentTime;
	GLFWwindow *glWindow;

	Platform *platform = new Platform();
	WindowFactory *windowFactory = new WindowFactory(platform);
	Window *window = windowFactory->createWindowForLaptop();

	if (window)
	{
		ShaderFactory *shaderFactory = new ShaderFactory();
		PrimitiveFactory *primitiveFactory = new PrimitiveFactory();
		DemoShader *shader = shaderFactory->makeDemoShader();
		Camera *camera = new Camera(shader);
		Cube *cube = primitiveFactory->buildCube(shader);
		delete shaderFactory;
		delete primitiveFactory;

		glWindow = window->getWindow();

		shader->use();
		shader->setDefaultLightColor();
		shader->setDefaultLightPosition();
		camera->setProjection();
		camera->setView();
		cube->setup();

		lastTime = (float)glfwGetTime();
		while (!glfwWindowShouldClose(glWindow))
		{
			currentTime = (float)glfwGetTime();
			deltaTime = currentTime - lastTime;
			lastTime = currentTime;

			// process input
			processInput(glWindow);

			// update
			cube->update(deltaTime);

			// draw
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			cube->draw();
			glfwSwapBuffers(glWindow);

			// system maintenance
			glfwPollEvents();
		}

		delete shader;
		delete cube;
		ret = 0;
	}

	delete window;
	delete windowFactory;
	delete platform;

	return ret;
}
