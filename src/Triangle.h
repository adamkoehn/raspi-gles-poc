#ifndef SRC_TRIANGLE
#define SRC_TRIANGLE

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "DemoShader.h"

class Triangle
{
public:
    Triangle(DemoShader *shader, unsigned int vao);
    void update(float deltaTime);
    void draw();

private:
    DemoShader *shader_;
    unsigned int vao_;
    float speed_;
    glm::mat4 model_;
};

#endif /* SRC_TRIANGLE */
