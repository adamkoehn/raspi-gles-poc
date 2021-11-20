#ifndef SRC_WINDOW
#define SRC_WINDOW

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window(GLFWwindow *window) : window_(window) {}
    GLFWwindow *getWindow() { return window_; }

private:
    GLFWwindow *window_;
};

#endif /* SRC_WINDOW */
