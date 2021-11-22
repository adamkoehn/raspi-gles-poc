#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Platform.h"
#include "Window.h"
#include "DemoShader.h"
#include "Camera.h"
#include "Cube.h"
#include "Scene.h"
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
	Window *window = windowFactory->createWindowForPi();

	if (window)
	{
		ShaderFactory *shaderFactory = new ShaderFactory();
		PrimitiveFactory *primitiveFactory = new PrimitiveFactory();
		DemoShader *shader = shaderFactory->makeDemoShader();
		Camera *camera = new Camera(shader);
		Scene *scene = new Scene(shader, camera);
		Cube *cube = primitiveFactory->buildCube(shader);
		delete shaderFactory;
		delete primitiveFactory;

		glWindow = window->getWindow();

		shader->use();
		scene->setup();

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
			scene->drawCube(cube);
			glfwSwapBuffers(glWindow);

			// system maintenance
			glfwPollEvents();
		}

		delete scene;
		delete shader;
		delete cube;
		ret = 0;
	}

	delete window;
	delete windowFactory;
	delete platform;

	return ret;
}
