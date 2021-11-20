#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Platform.h"
#include "Window.h"
#include "WindowFactory.h"

std::string readFile(std::string path)
{
	std::stringstream buffer;
	std::ifstream file(path);
	if (file.is_open())
	{
		buffer << file.rdbuf();
	}
	else
	{
		std::cout << "could not read " << path << std::endl;
	}

	file.close();

	return buffer.str();
}

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

unsigned int createProgram()
{
	int success;
	char log[512];
	unsigned int vshader;
	unsigned int fshader;
	unsigned int program;
	std::string vstring;
	std::string fstring;
	const char * vsource;
	const char * fsource;

	vstring = readFile("shaders/demo.vert.glsl");
	fstring = readFile("shaders/demo.frag.glsl");

	vsource = vstring.c_str();
	fsource = fstring.c_str();

	std::cout << "compiling vertex shader" << std::endl;

	vshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vshader, 1, &vsource, NULL);
	glCompileShader(vshader);
	glGetShaderiv(vshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vshader, 512, NULL, log);
		std::cout << "vshader: " << log << std::endl;
	}

	std::cout << "compiling fragment shader" << std::endl;

	fshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fshader, 1, &fsource, NULL);
	glCompileShader(fshader);
	glGetShaderiv(fshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fshader, 512, NULL, log);
		std::cout << "fshader: " << log << std::endl;
	}

	std::cout << "linking program" << std::endl;

	program = glCreateProgram();
	glAttachShader(program, vshader);
	glAttachShader(program, fshader);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, log);
		std::cout << "link: " << log << std::endl;
	}

	glDeleteShader(vshader);
	glDeleteShader(fshader);

	return program;
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
	Window *window = windowFactory->createWindow();
	
	if (window)
	{
		glWindow = window->getWindow();
		program = createProgram();
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

		ret = 0;
	}

	delete window;
	delete windowFactory;
	delete platform;

	return ret;
}
