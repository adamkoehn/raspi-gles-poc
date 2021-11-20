#ifndef SRC_PRIMITIVEFACTORY
#define SRC_PRIMITIVEFACTORY

#include <GL/glew.h>

#include "Triangle.h"

class PrimitiveFactory
{
public:
    Triangle *bufferTriangle();
};

#endif /* SRC_PRIMITIVEFACTORY */
