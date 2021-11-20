#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Platform.h"
#include "Window.h"
#include "Shader.h"
#include "WindowFactory.h"
#include "ShaderFactory.h"

unsigned int createTriangle()
{
	unsigned int vao;
	unsigned int vbo;

	float verticies[] = {
		0.0f, 0.5f, 0.0f, 0.0f, 1.0f, // top, blue
		-0.5f, -0.5f, 1.0f, 0.0f, 0.0f, // left, red
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // right, green
	};

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float) * 2));
	glEnableVertexAttribArray(1);

	return vao;
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
}

int main(void)
{
	int ret = 1;
	GLFWwindow *glWindow;
	unsigned int vao;
	unsigned int program;

	Platform *platform = new Platform();
	WindowFactory *windowFactory = new WindowFactory(platform);
	Window *window = windowFactory->createWindowForLaptop();
	
	if (window)
	{
		ShaderFactory *shaderFactory = new ShaderFactory();
		Shader *shader = shaderFactory->makeShader("shaders/demo.vert.glsl", "shaders/demo.frag.glsl");
		delete shaderFactory;

		glWindow = window->getWindow();
		program = shader->getProgram();
		vao = createTriangle();

		glUseProgram(program);
		glBindVertexArray(vao);	

		while (!glfwWindowShouldClose(glWindow))
		{
			processInput(glWindow);
			glClear(GL_COLOR_BUFFER_BIT);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glfwSwapBuffers(glWindow);
			glfwPollEvents();
		}

		delete shader;
		ret = 0;
	}

	delete window;
	delete windowFactory;
	delete platform;

	return ret;
}
