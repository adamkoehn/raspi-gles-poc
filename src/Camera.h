#ifndef SRC_CAMERA
#define SRC_CAMERA

#include <glm/glm.hpp>

#include "DemoShader.h"

class Camera
{
public:
    Camera(DemoShader *shader);
    glm::mat4 getProjection() { return projection_; }
    glm::mat4 getView() { return view_; }

private:
    DemoShader *shader_;
    glm::mat4 projection_;
    glm::mat4 view_;
};

#endif /* SRC_CAMERA */
