#ifndef SRC_DEMO_SHADER
#define SRC_DEMO_SHADER

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class DemoShader
{
public:
    DemoShader(unsigned int program);
    void use();
    void setUniformModel(glm::mat4 model);

private:
    unsigned int program_;
    unsigned int model_;
};

#endif /* SRC_SHADER */
