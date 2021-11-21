#ifndef SRC_SHADERFACTORY
#define SRC_SHADERFACTORY

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <iostream>

#include "ShaderBuilder.h"
#include "DemoShader.h"

class ShaderFactory
{
public:
    DemoShader *makeDemoShader();
};

#endif /* SRC_SHADERFACTORY */
