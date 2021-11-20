#include "WindowFactory.h"

Window *WindowFactory::createWindow()
{
    GLFWwindow *window;

    window = platform_->createWindow();

    return window ? new Window(window) : NULL;
}