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
    void setModelColor(glm::vec3 color);
    void setLightColor(glm::vec3 color);
    void setLightPosition(glm::vec3 position);
    void setProjection(glm::mat4 projection);
    void setView(glm::mat4 view);
    void setModel(glm::mat4 model);
    void setDefaultLightColor();
    void setDefaultLightPosition();

private:
    unsigned int program_;
    unsigned int model_;
    unsigned int view_;
    unsigned int projection_;
    unsigned int modelColor_;
    unsigned int lightColor_;
    unsigned int lightPosition_;
};

#endif /* SRC_SHADER */
