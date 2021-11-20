#include "WindowFactory.h"

Window *WindowFactory::createWindowForPi()
{
    GLFWwindow *window;

    window = platform_->createWindow(800, 480, true);

    return window ? new Window(window) : NULL;
}

Window *WindowFactory::createWindowForLaptop()
{
    GLFWwindow *window;

    window = platform_->createWindow(800, 480, false);

    return window ? new Window(window) : NULL;
}