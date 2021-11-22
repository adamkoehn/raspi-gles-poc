#ifndef SRC_CUBE
#define SRC_CUBE

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "DemoShader.h"

class Cube
{
public:
    Cube(DemoShader *shader, unsigned int vao);
    glm::vec3 getModelColor() { return glm::vec3(0.2f, 0.2f, 1.0f); }
    glm::mat4 getModel() { return model_; }
    void update(float deltaTime);
    void draw();

private:
    DemoShader *shader_;
    unsigned int vao_;
    float speed_;
    glm::mat4 model_;
};

#endif /* SRC_CUBE */
