#include "Triangle.h"

Triangle::Triangle(DemoShader *shader, unsigned int vao)
    : shader_(shader), vao_(vao), speed_(5.0f)
{
    model_ = glm::mat4(1.0f);
}

void Triangle::draw()
{
    shader_->setUniformModel(model_);
    glBindVertexArray(vao_);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

void Triangle::update(float deltaTime)
{
    model_ = glm::rotate(model_, glm::radians(deltaTime * speed_), glm::vec3(0.0f, 0.0f, 1.0f));
}