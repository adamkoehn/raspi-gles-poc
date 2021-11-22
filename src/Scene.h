#ifndef SRC_SCENE
#define SRC_SCENE

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "DemoShader.h"
#include "Camera.h"
#include "Cube.h"

class Scene
{
public:
    Scene(DemoShader *shader, Camera *camera) : shader_(shader), camera_(camera) {}
    void drawCube(Cube *cube);
    void setup();

private:
    DemoShader *shader_;
    Camera *camera_;
};

#endif /* SRC_SCENE */
