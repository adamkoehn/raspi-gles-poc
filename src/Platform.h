#ifndef SRC_PLATFORM
#define SRC_PLATFORM

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Platform
{
public:
    ~Platform();
    GLFWwindow *createWindow(int width, int height, bool fullScreen);

private:
    GLFWwindow *window_;
    bool init_();
    bool makeWindow_(int width, int height, bool fullScreen);
    bool createContext_();
    void logError_();
};

#endif /* SRC_PLATFORM */
