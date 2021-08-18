//
// Created by Stefan on 08/05/2021.
//
#include <Game.h>

namespace Game
{

    Window::Window(const std::string &title, uint32_t width, uint32_t height) // TODO: move window class to static with WindowProps global struct
    {
        if (!glfwInit())
        {
            LOG_ERROR("Error initializing glfw");
            Application::Exit(-1);
        }

        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        this->width = width;
        this->height = height;
        window = glfwCreateWindow(this->width, this->height, title.c_str(), nullptr, nullptr);

        if (!window)
        {
            glfwTerminate();
            LOG_ERROR("Error creating the window");
            Application::Exit(-1);
        }

        glfwMakeContextCurrent(window);

        //TODO: initialize framebuffer
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    bool Window::shouldClose()
    {
        return glfwWindowShouldClose(window);
    }

    void Window::beginFrame()
    {
        glfwSwapBuffers(window);
        glfwPollEvents();

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    uint32_t Window::getWidth()
    {
        return width;
    }

    uint32_t Window::getHeight()
    {
        return height;
    }

    uint32_t Window::getFramebuffer()
    {
        return framebuffer;
    }
}
