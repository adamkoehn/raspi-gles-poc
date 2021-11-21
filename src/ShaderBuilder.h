#ifndef SRC_SHADERBUILDER
#define SRC_SHADERBUILDER

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class ShaderBuilder
{
public:
    unsigned int compileVertexShader(std::string path);
    unsigned int compileFragmentShader(std::string path);
    unsigned int linkProgram(unsigned int vshader, unsigned int fshader);

private:
    unsigned int compileShader_(std::string path, GLenum type);
    std::string readPath_(std::string path);
    void logError_(unsigned int shader);

};

#endif /* SRC_SHADERBUILDER */
