#ifndef SRC_PLATFORM
#define SRC_PLATFORM

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Platform
{
public:
    ~Platform();
    GLFWwindow *createWindow();

private:
    GLFWwindow *window_;
    bool init_();
    bool makeWindow_();
    bool createContext_();
    void logError_();
};

#endif /* SRC_PLATFORM */
