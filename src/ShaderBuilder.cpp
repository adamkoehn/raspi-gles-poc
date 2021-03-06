#include "ShaderBuilder.h"

unsigned int ShaderBuilder::compileVertexShader(std::string path)
{
    std::cout << "compiling vertex shader " << path << std::endl;
    return compileShader_(path, GL_VERTEX_SHADER);
}

unsigned int ShaderBuilder::compileFragmentShader(std::string path)
{
    std::cout << "compiling fragment shader " << path << std::endl;
    return compileShader_(path, GL_FRAGMENT_SHADER);
}

unsigned int ShaderBuilder::linkProgram(unsigned int vshader, unsigned int fshader)
{
    int success;
    char log[512];
    unsigned int program;

    std::cout << "linking program" << std::endl;

	program = glCreateProgram();
	glAttachShader(program, vshader);
	glAttachShader(program, fshader);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, log);
		std::cerr << "program link error: " << log << std::endl;
	}

	glDeleteShader(vshader);
	glDeleteShader(fshader);

    return program;
}

unsigned int ShaderBuilder::compileShader_(std::string path, GLenum type)
{
    int success;
	unsigned int shader = glCreateShader(type);
    std::string source = readPath_(path);
    const char *code = source.c_str();

	glShaderSource(shader, 1, &code, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		logError_(shader);
	}

    return shader;
}

std::string ShaderBuilder::readPath_(std::string path)
{
    std::stringstream buffer;
	std::ifstream file(path);
	if (file.is_open())
	{
		buffer << file.rdbuf();
	}
	else
	{
		std::cerr << "could not read " << path << std::endl;
	}

	file.close();

	return buffer.str();
}

void ShaderBuilder::logError_(unsigned int shader)
{
    char log[512];
    glGetShaderInfoLog(shader, 512, NULL, log);
    std::cerr << "shader: " << log << std::endl;    
}