#include "Platform.h"

GLFWwindow *Platform::createWindow()
{
    if (init_())
    {
        if (makeWindow_())
        {
            if (createContext_())
            {
                return window_;
            }
        }
    }

    return NULL;
}

bool Platform::init_()
{
    if (glfwInit() != GLFW_TRUE)
    {
        logError_();
        return false;
    }

    return true;
}

bool Platform::makeWindow_()
{
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    window_ = glfwCreateWindow(800, 480, "demo", glfwGetPrimaryMonitor(), NULL);
    if (!window_)
    {
        logError_();
        return false;
    }
    glfwSwapInterval(1);

    return true;
}

bool Platform::createContext_()
{
    GLenum error;

    glfwMakeContextCurrent(window_);
    
    error = glewInit();
    if (error != GLEW_OK)
    {
        std::cerr << "glew init error: " << glewGetErrorString(error) << std::endl;
        return false;
    }

    glViewport(0, 0, 800, 480);

    return true;
}

void Platform::logError_()
{
    const char *errorMessage;
    int errorCode = glfwGetError(&errorMessage);
    std::cerr << errorCode << ": " << errorMessage << std::endl;
}

Platform::~Platform()
{
    if (window_)
    {
        glfwDestroyWindow(window_);
        glfwTerminate();
    }
}