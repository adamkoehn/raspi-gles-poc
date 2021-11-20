#ifndef SRC_SHADER
#define SRC_SHADER

class Shader
{
public:
    Shader(unsigned int program) : program_(program) {}
    unsigned int getProgram() { return program_; }

private:
    unsigned int program_;
};

#endif /* SRC_SHADER */
