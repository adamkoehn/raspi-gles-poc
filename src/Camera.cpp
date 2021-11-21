#include "Camera.h"

Camera::Camera(DemoShader *shader)
    : shader_(shader)
{
    projection_ = glm::perspective(glm::radians(45.0f), 800.0f / 480.0f, 0.1f, 100.0f);
    view_ = glm::lookAt(
        glm::vec3(0.0f, 0.0f, 3.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::setProjection()
{
    shader_->setProjection(projection_);
}

void Camera::setView()
{
    shader_->setView(view_);
}