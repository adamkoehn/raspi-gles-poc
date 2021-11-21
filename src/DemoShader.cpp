#include "DemoShader.h"

DemoShader::DemoShader(unsigned int program)
    : program_(program)
{
    model_ = glGetUniformLocation(program_, "Model");
}

void DemoShader::use()
{
    glUseProgram(program_);
}

void DemoShader::setUniformModel(glm::mat4 model)
{
    glUniformMatrix4fv(model_, 1, GL_FALSE, glm::value_ptr(model));
}