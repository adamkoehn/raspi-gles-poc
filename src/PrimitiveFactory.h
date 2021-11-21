#ifndef SRC_PRIMITIVEFACTORY
#define SRC_PRIMITIVEFACTORY

#include <GL/glew.h>

#include "Cube.h"

class PrimitiveFactory
{
public:
    Cube *buildCube(DemoShader *shader);
};

#endif /* SRC_PRIMITIVEFACTORY */
