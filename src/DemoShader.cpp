#include "DemoShader.h"

DemoShader::DemoShader(unsigned int program)
    : program_(program)
{
    model_ = glGetUniformLocation(program_, "Model");
    view_ = glGetUniformLocation(program_, "View");
    projection_ = glGetUniformLocation(program_, "Projection");
    modelColor_ = glGetUniformLocation(program_, "ModelColor");
    lightColor_ = glGetUniformLocation(program_, "LightColor");
    lightPosition_ = glGetUniformLocation(program_, "LightPosition");
}

void DemoShader::use()
{
    glUseProgram(program_);
}

void DemoShader::setProjection(glm::mat4 projection)
{
    glUniformMatrix4fv(projection_, 1, GL_FALSE, glm::value_ptr(projection));
}

void DemoShader::setView(glm::mat4 view)
{
    glUniformMatrix4fv(view_, 1, GL_FALSE, glm::value_ptr(view));
}

void DemoShader::setModel(glm::mat4 model)
{
    glUniformMatrix4fv(model_, 1, GL_FALSE, glm::value_ptr(model));
}

void DemoShader::setModelColor(glm::vec3 color)
{
    glUniform3fv(modelColor_, 1, glm::value_ptr(color));
}

void DemoShader::setLightColor(glm::vec3 color)
{
    glUniform3fv(lightColor_, 1, glm::value_ptr(color));
}

void DemoShader::setDefaultLightColor()
{
    setLightColor(glm::vec3(1.0f));
}

void DemoShader::setLightPosition(glm::vec3 position)
{
    glUniform3fv(lightPosition_, 1, glm::value_ptr(position));
}

void DemoShader::setDefaultLightPosition()
{
    setLightPosition(glm::vec3(200.0f, 200.0f, 100.0f));
}