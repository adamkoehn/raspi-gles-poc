#ifndef SRC_SHADER
#define SRC_SHADER

#include <GL/glew.h>

class Shader
{
public:
    Shader(unsigned int program) : program_(program) {}
    void use() { glUseProgram(program_); }

private:
    unsigned int program_;
};

#endif /* SRC_SHADER */
