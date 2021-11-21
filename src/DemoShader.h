#ifndef SRC_DEMO_SHADER
#define SRC_DEMO_SHADER

#include <GL/glew.h>

class DemoShader
{
public:
    DemoShader(unsigned int program) : program_(program) {}
    void use() { glUseProgram(program_); }

private:
    unsigned int program_;
};

#endif /* SRC_SHADER */
