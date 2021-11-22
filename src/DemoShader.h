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
    void setLightInfo(glm::vec4 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
    void setMaterialInfo(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess);
    void setModelViewMatrix(glm::mat4 modelViewMatrix);
    void setNormalMatrix(glm::mat3 normalMatrix);
    void setProjectionMatrix(glm::mat4 projectionMatrix);

private:
    unsigned int program_;
    struct {
        unsigned int position;
        unsigned int ambient;
        unsigned int diffuse;
        unsigned int specular;
    } lightInfo_;
    struct {
        unsigned int ambient;
        unsigned int diffuse;
        unsigned int specular;
        unsigned int shininess;
    } materialInfo_;
    unsigned int modelViewMatrix_;
    unsigned int normalMatrix_;
    unsigned int projectionMatrix_;
    unsigned int mvp_;
};

#endif /* SRC_SHADER */
