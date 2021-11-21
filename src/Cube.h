#ifndef SRC_CUBE
#define SRC_CUBE

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "DemoShader.h"

class Cube
{
public:
    Cube(DemoShader *shader, unsigned int vao);
    void setup();
    void update(float deltaTime);
    void draw();

private:
    DemoShader *shader_;
    unsigned int vao_;
    float speed_;
    glm::mat4 model_;
};

#endif /* SRC_CUBE */
