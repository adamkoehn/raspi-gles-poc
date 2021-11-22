#include "DemoShader.h"

DemoShader::DemoShader(unsigned int program)
    : program_(program)
{
    lightInfo_.position = glGetUniformLocation(program_, "Light.Position");
    lightInfo_.ambient = glGetUniformLocation(program_, "Light.Ambient");
    lightInfo_.diffuse = glGetUniformLocation(program_, "Light.Diffuse");
    lightInfo_.specular = glGetUniformLocation(program_, "Light.Specular");
    materialInfo_.ambient = glGetUniformLocation(program_, "Material.Ambient");
    materialInfo_.diffuse = glGetUniformLocation(program_, "Material.Diffuse");
    materialInfo_.specular = glGetUniformLocation(program_, "Material.Specular");
    materialInfo_.shininess = glGetUniformLocation(program_, "Material.Shininess");
    modelViewMatrix_ = glGetUniformLocation(program_, "ModelViewMatrix");
    normalMatrix_ = glGetUniformLocation(program_, "NormalMatrix");
    projectionMatrix_ = glGetUniformLocation(program_, "ProjectionMatrix");
}

void DemoShader::use()
{
    glUseProgram(program_);
}

void DemoShader::setLightInfo(glm::vec4 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
{
    glUniform4fv(lightInfo_.position, 1, glm::value_ptr(position));
    glUniform3fv(lightInfo_.ambient, 1, glm::value_ptr(ambient));
    glUniform3fv(lightInfo_.diffuse, 1, glm::value_ptr(diffuse));
    glUniform3fv(lightInfo_.specular, 1, glm::value_ptr(specular));
}

void DemoShader::setMaterialInfo(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess)
{
    glUniform3fv(materialInfo_.ambient, 1, glm::value_ptr(ambient));
    glUniform3fv(materialInfo_.diffuse, 1, glm::value_ptr(diffuse));
    glUniform3fv(materialInfo_.specular, 1, glm::value_ptr(specular));
    glUniform1f(materialInfo_.shininess, shininess);
}

void DemoShader::setModelViewMatrix(glm::mat4 modelViewMatrix)
{
    glUniformMatrix4fv(modelViewMatrix_, 1, GL_FALSE, glm::value_ptr(modelViewMatrix));
}

void DemoShader::setNormalMatrix(glm::mat3 normalMatrix)
{
    glUniformMatrix3fv(normalMatrix_, 1, GL_FALSE, glm::value_ptr(normalMatrix));
}

void DemoShader::setProjectionMatrix(glm::mat4 projectionMatrix)
{
    glUniformMatrix4fv(projectionMatrix_, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}