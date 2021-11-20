#ifndef SRC_TRIANGLE
#define SRC_TRIANGLE

#include <GL/glew.h>

class Triangle
{
public:
    Triangle(unsigned int vao) : vao_(vao) {}
    void draw();

private:
    unsigned int vao_;
};

#endif /* SRC_TRIANGLE */
