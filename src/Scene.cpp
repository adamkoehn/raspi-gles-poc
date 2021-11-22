#include "Scene.h"

void Scene::drawCube(Cube *cube)
{
    glm::mat4 modelViewMatrix = camera_->getView() * cube->getModel();
    glm::mat3 normalMatrix = glm::inverse(glm::transpose(glm::mat3(modelViewMatrix)));

    shader_->setModelViewMatrix(modelViewMatrix);
    shader_->setNormalMatrix(normalMatrix);

    cube->draw();
}

void Scene::setup()
{
    shader_->setLightInfo(
        glm::vec4(10.0f, 10.0f, 5.0f, 1.0f),
        glm::vec3(0.5f, 0.5f, 0.5f),
        glm::vec3(0.8f, 0.8f, 0.8f),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    shader_->setMaterialInfo(
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(0.5f, 0.5f, 0.5f),
        32.0f
    );
    shader_->setProjectionMatrix(camera_->getProjection());
}