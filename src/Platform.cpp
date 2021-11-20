#include "Platform.h"

GLFWwindow *Platform::createWindow(int width, int height, bool fullScreen)
{
    if (init_())
    {
        if (makeWindow_(width, height, fullScreen))
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

bool Platform::makeWindow_(int width, int height, bool fullScreen)
{
    GLFWmonitor *monitor = NULL;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    if (fullScreen)
    {
        monitor = glfwGetPrimaryMonitor();
    }

    window_ = glfwCreateWindow(width, height, "demo", monitor, NULL);
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