#ifndef SRC_CAMERA
#define SRC_CAMERA

#include <glm/glm.hpp>

#include "DemoShader.h"

class Camera
{
public:
    Camera(DemoShader *shader);
    void setProjection();
    void setView();

private:
    DemoShader *shader_;
    glm::mat4 projection_;
    glm::mat4 view_;
};

#endif /* SRC_CAMERA */
