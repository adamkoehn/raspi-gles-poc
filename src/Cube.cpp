#include "Cube.h"

Cube::Cube(DemoShader *shader, unsigned int vao)
    : shader_(shader), vao_(vao)
{
    speed_ = 20.0f;

    model_ = glm::mat4(1.0f);
    model_ = glm::scale(model_, glm::vec3(1.0f));
}

void Cube::update(float deltaTime)
{
    model_ = glm::rotate(model_, glm::radians(deltaTime * speed_), glm::vec3(0.4f, 0.3f, 1.0f));
}

void Cube::draw()
{
    glBindVertexArray(vao_);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}