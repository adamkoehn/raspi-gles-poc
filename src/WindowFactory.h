#ifndef SRC_WINDOWFACTORY
#define SRC_WINDOWFACTORY

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Platform.h"
#include "Window.h"

class WindowFactory
{
public:
    WindowFactory(Platform *platform) : platform_(platform) {}
    Window *createWindowForPi();
    Window *createWindowForLaptop();

private:
    Platform *platform_;
};

#endif /* SRC_WINDOWFACTORY */
