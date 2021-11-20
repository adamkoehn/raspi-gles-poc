#ifndef SRC_SHADERFACTORY
#define SRC_SHADERFACTORY

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Shader.h"

class ShaderFactory
{
public:
    Shader *makeShader(std::string vertexShaderPath, std::string fragmentShaderPath);

private:
    unsigned int compileVertexShader_(std::string path);
    unsigned int compileFragmentShader_(std::string path);
    unsigned int compileShader_(std::string path, GLenum type);
    unsigned int linkProgram_(unsigned int vshader, unsigned int fshader);
    std::string readPath_(std::string path);
    void logError_(unsigned int shader);
};

#endif /* SRC_SHADERFACTORY */
